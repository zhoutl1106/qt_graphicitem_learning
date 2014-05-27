#include "buoygraphicsitem.h"


buoyGraphicsItem::buoyGraphicsItem(bool visual, int ind)
{
    visiable = visual;
    this->setVisible(visiable);
    index = ind;
    buoyPixmap = QPixmap(":/image/buoy.png");
}

QRectF buoyGraphicsItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 -penWidth / 2,
                  110 + penWidth, 32 + penWidth);
}

void buoyGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setTransform(this->scene()->views().takeFirst()->transform().inverted(), true);
    painter->drawPixmap(0,0,buoyPixmap);
    painter->drawText(28,10,"浮标 0" + QString::number(index));
}
