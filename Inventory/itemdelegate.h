#pragma once

#include <QAbstractItemDelegate>

class ItemDelegate : public QAbstractItemDelegate
{
public:
    explicit ItemDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
private:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};
