#include "inventory.h"

#include <QSound>

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
