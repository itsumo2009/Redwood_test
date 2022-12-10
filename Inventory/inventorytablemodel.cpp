#include "inventorytablemodel.h"

InventoryTableModel::InventoryTableModel()
{

}


QModelIndex InventoryTableModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return {};
    }
    else
    {
        return createIndex(row, column);
    }
}

QModelIndex InventoryTableModel::parent(const QModelIndex &child) const
{
    return {};
}

int InventoryTableModel::rowCount(const QModelIndex &parent) const
{
    return _inventory.size().height();
}

int InventoryTableModel::columnCount(const QModelIndex &parent) const
{
    return _inventory.size().width();
}

QVariant InventoryTableModel::data(const QModelIndex &index, int role) const
{
    auto& cell = _inventory.cell(index.column(), index.row());
    if (role == Qt::UserRole || role == Qt::DisplayRole)
    {
        return cell.count;
    }
    else if (role == Qt::UserRole + 1)
    {
        return cell.item ? cell.item->image() : QVariant();
    }

    return {};
}
