#include "inventorytablemodel.h"

#include <QImage>
#include <QMimeData>

InventoryTableModel::InventoryTableModel()
{

}

void InventoryTableModel::loadFromDb()
{
    beginResetModel();
    _db.loadInventory(_inventory);
    endResetModel();
}

void InventoryTableModel::saveToDb()
{
    _db.saveInventory(_inventory);
}

void InventoryTableModel::useItem(QModelIndex index)
{
    _inventory.useItem(index.column(), index.row());
    emit dataChanged(index, index, {Qt::UserRole, Qt::UserRole + 1, Qt::DisplayRole});
}

void InventoryTableModel::addItem(QModelIndex index, const Item &item)
{
    _inventory.moveItem(index.column(), index.row(), item);
    emit dataChanged(index, index, {Qt::UserRole, Qt::UserRole + 1, Qt::DisplayRole});
}

void InventoryTableModel::moveItem(int sourceColumn, int sourceRow, QModelIndex destinationIndex)
{
    _inventory.moveItem(sourceColumn, sourceRow,destinationIndex.column(), destinationIndex.row());
    auto sourceIndex = createIndex(sourceRow, sourceColumn);
    emit dataChanged(sourceIndex, sourceIndex, {Qt::UserRole, Qt::UserRole + 1, Qt::DisplayRole});
    emit dataChanged(destinationIndex, destinationIndex, {Qt::UserRole, Qt::UserRole + 1, Qt::DisplayRole});
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
        return cell.item ? QImage(cell.item->image()) : QVariant();
    }

    return {};
}


Qt::ItemFlags InventoryTableModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
    {
        return QAbstractTableModel::flags(index) | Qt::ItemFlag::ItemIsDragEnabled | Qt::ItemFlag::ItemIsDropEnabled;
    }
    return QAbstractTableModel::flags(index);
}

QMimeData *InventoryTableModel::mimeData(const QModelIndexList &indexes) const
{
    QByteArray array;
    array.push_back(indexes.first().column());
    array.push_back(indexes.first().row());

    QMimeData* mimeData = new QMimeData;
    mimeData->setData("application/inventory", array);
    return mimeData;
}
