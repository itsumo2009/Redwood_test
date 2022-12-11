#pragma once

#include <QAbstractTableModel>

#include "database.h"
#include "inventory.h"

class InventoryTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ///
    /// \brief InventoryTableModel Конструктор
    ///
    InventoryTableModel();

    ///
    /// \brief loadFromDb Загружает инвентарь из БД
    ///
    void loadFromDb();
    ///
    /// \brief saveToDb Сохраняет инвентарь в БД
    ///
    void saveToDb();

    ///
    /// \brief useItem Использовать предмет
    /// \param index Индекс ячейки
    ///
    void useItem(QModelIndex index);
    ///
    /// \brief addItem Добавить предмет
    /// \param index Индекс ячейкм
    /// \param item Предмет
    ///
    void addItem(QModelIndex index, const Item& item);
    ///
    /// \brief moveItem Переместить предмет
    /// \param sourceColumn Исходная колонка
    /// \param sourceRow Исходная строка
    /// \param destinationIndex Индекс целевой ячейки
    ///
    void moveItem(int sourceColumn, int sourceRow, QModelIndex destinationIndex);

    // QAbstractItemModel interface
private:
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QMimeData* mimeData(const QModelIndexList &indexes) const override;

private:
    Inventory _inventory;
    Database _db;
};
