#pragma once

#include <QSqlDatabase>

#include "inventory.h"

class Database
{
public:
    Database();

    void saveInventory(const Inventory& inventory);
    void loadInventory(Inventory& inventory);

private:
    QSqlDatabase _db;
};
