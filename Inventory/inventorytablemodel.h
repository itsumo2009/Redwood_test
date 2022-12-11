#pragma once

#include <QAbstractTableModel>

#include "inventory.h"

class InventoryTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    InventoryTableModel();

    void useItem(QModelIndex index);
    void addItem(QModelIndex index, const Item& item);
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
};
