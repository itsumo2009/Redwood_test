#pragma once

#include <QAbstractTableModel>

#include "inventory.h"

class InventoryTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    InventoryTableModel();

    // QAbstractItemModel interface
private:
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    Inventory _inventory;
};
