#pragma once

#include <QScopedPointer>
#include <QSize>

#include "item.h"

class Inventory
{
public:
    struct Cell
    {
        QScopedPointer<Item> item;
        int count = 0;
    };

public:
    const Cell& cell(int i, int j) const;
    Cell& cell(int i, int j);

    void moveItem(int i, int j, const Item& item);
    void useItem(int i, int j);

    QSize size() const;

private:
    Cell _cells[3][3];
};
