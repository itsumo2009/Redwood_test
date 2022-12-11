#include "database.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>

Database::Database()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("main.sqlite");
    if (!_db.open())
    {
        qDebug() << "DB has not be opened";
    }
}

void Database::saveInventory(const Inventory &inventory)
{
    for (int i=0; i < inventory.size().width(); ++i)
        for (int j=0; j < inventory.size().height(); ++j)
        {
            if (inventory.cell(i, j).item.data())
            {
                QSqlQuery query(_db);
                if (!query.exec(QString("UPDATE Inventory SET Type='apple',\"COUNT\" = %1 WHERE X = %2 AND Y = %3 ")
                        .arg(inventory.cell(i, j).count)
                        .arg(i)
                        .arg(j)))
                {
                    qDebug() << "Query has not be executed";
                }
            }
            else
            {
                QSqlQuery query(_db);
                if (!query.exec(QString("UPDATE Inventory SET Type=NULL,\"COUNT\" = 0 WHERE X = %1 AND Y = %2 ")
                        .arg(i)
                        .arg(j)))
                {
                    qDebug() << "Query has not be executed";
                }
            }
        }
}

void Database::loadInventory(Inventory& inventory)
{
    QSqlQuery query(_db);
    if (!query.exec("SELECT X,Y,Type,\"COUNT\" FROM Inventory"))
    {
        qDebug() << "Query has not be executed";
        return;
    }

    for (int i=0; i < inventory.size().width(); ++i)
        for (int j=0; j < inventory.size().height(); ++j)
        {
            inventory.cell(i, j).count = 0;
            inventory.cell(i, j).item.reset();
        }

    while (query.next())
    {
        auto x = query.record().field(0).value().toUInt();
        auto y = query.record().field(1).value().toUInt();
        auto type = query.record().field(2).value().toString();
        if (!type.isEmpty())
        {
            auto count = query.record().field(3).value().toUInt();
            if (type == "apple" && 0<=x && x <inventory.size().width() && 0<=y && y < inventory.size().height())
            {
                inventory.cell(x, y).item.reset(new Item);
                inventory.cell(x, y).count = count;
            }
        }

    }
}
