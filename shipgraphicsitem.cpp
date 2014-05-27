#include "shipgraphicsitem.h"

shipGraphicsItem::shipGraphicsItem()
{
    shipPixmap = QPixmap(":/image/ship.png");
}

QRectF shipGraphicsItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 -penWidth / 2,
                  110 + penWidth, 32 + penWidth);
}

void shipGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setTransform(this->scene()->views().takeFirst()->transform().inverted(), true);
    painter->drawPixmap(0,0,shipPixmap);
}
