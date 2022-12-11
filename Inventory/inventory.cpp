#include "inventory.h"

#include <QSound>

const Inventory::Cell& Inventory::cell(int i, int j) const
{
    return _cells[i][j];
}

Inventory::Cell& Inventory::cell(int i, int j)
{
    return _cells[i][j];
}

void Inventory::moveItem(int sourceI, int sourceJ, int destinationI, int destinationJ)
{
    auto& sourceCell = _cells[sourceI][sourceJ];
    auto& destCell = _cells[destinationI][destinationJ];
    if (!sourceCell.item.data())
    {
        return;
    }

    if (destCell.item.data() && sourceCell.item->type() == destCell.item->type())
    {
        destCell.count += sourceCell.count;
    }
    else
    {
        destCell.item.reset(new Item(*sourceCell.item));
        destCell.count = sourceCell.count;
    }

    sourceCell.item.reset();
    sourceCell.count = 0;
}

void Inventory::moveItem(int i, int j, const Item& item)
{
    auto& cell = _cells[i][j];
    if (cell.item.data() && cell.item->type() == item.type())
    {
        ++cell.count;
    }
    else
    {
        cell.item.reset(new Item(item));
        cell.count = 1;
    }
}

void Inventory::useItem(int i, int j)
{
    auto& cell = _cells[i][j];
    if (cell.item.data() && cell.count > 0)
    {
        QSound::play("://apple.wav");
        if (--cell.count == 0)
        {
            cell.item.reset();
        }
    }
}

QSize Inventory::size() const
{
    return {3, 3};
}
