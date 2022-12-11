#include "itemdelegate.h"

#include <QPainter>
#include <QImage>

ItemDelegate::ItemDelegate(QObject *parent)
    : QAbstractItemDelegate{parent}
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    auto stringRect = option.fontMetrics.boundingRect(index.data().toString());
    painter->drawText(option.rect.right() - stringRect.width() - 5, option.rect.bottom(), index.data().toString());
    painter->drawImage(option.rect, index.data(Qt::UserRole+1).value<QImage>());
}

QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return {192, 192};
}
