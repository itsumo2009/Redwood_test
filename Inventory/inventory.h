#pragma once

#include <QScopedPointer>
#include <QSize>

#include "item.h"

class Inventory
{
public:
    void moveItem(int i, int j, const Item& item);
    void useItem(int i, int j);

    QSize size() const;

private:
    struct Cell
    {
        QScopedPointer<Item> item;
        size_t count;
    };

    Cell _cells[3][3];
};
