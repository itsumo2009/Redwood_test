#pragma once

#include <QSqlDatabase>

#include "inventory.h"

class Database
{
public:
    ///
    /// \brief Конструктор. Создаёт соединение с базой данных
    ///
    Database();

    ///
    /// \brief saveInventory сохраняет инвентарь в БД
    /// \param inventory сохраняемый инвентарь
    ///
    void saveInventory(const Inventory& inventory);
    ///
    /// \brief loadInventory загружает инвентарь из БД
    /// \param inventory загружаемый инвентарь
    ///
    void loadInventory(Inventory& inventory);

private:
    QSqlDatabase _db;
};
