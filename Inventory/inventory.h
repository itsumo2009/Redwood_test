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
    ///
    /// \brief cell Ячейка инвентаря
    /// \param i колонка
    /// \param j строка
    /// \return ссылку на ячейку инвентаря
    ///
    const Cell& cell(int i, int j) const;
    ///
    /// \brief cell Ячейка инвентаря
    /// \param i колонка
    /// \param j строка
    /// \return ссылку на ячейку инвентаря
    ///
    Cell& cell(int i, int j);

    ///
    /// \brief moveItem перемещает стопку предметов из ячейки в ячейку
    /// \param sourceI исходная колонка
    /// \param sourceJ исходная строка
    /// \param destinationI целевая колонка
    /// \param destinationJ целевая строка
    ///
    void moveItem(int sourceI, int sourceJ, int destinationI, int destinationJ);
    ///
    /// \brief moveItem перемещает предмет в инвентарь
    /// \param i целевая колонка
    /// \param j целевая строка
    /// \param item предмет
    ///
    void moveItem(int i, int j, const Item& item);
    ///
    /// \brief useItem использовать предмет
    /// \param i колонка
    /// \param j строка
    ///
    void useItem(int i, int j);

    ///
    /// \brief size
    /// \return размер инвентаря
    ///
    QSize size() const;

private:
    Cell _cells[3][3];
};
