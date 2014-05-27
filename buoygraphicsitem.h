#ifndef BUOYGRAPHICSITEM_H
#define BUOYGRAPHICSITEM_H

#include <QGraphicsItem>
#include "global_define.h"

class buoyGraphicsItem : public QGraphicsItem
{
public:
    buoyGraphicsItem(bool visual,int ind);
    QRectF boundingRect() const;
    int type() const { return TypeBuoy; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget);
    bool visiable;
    int index;

private:
    QPixmap buoyPixmap;
};

#endif // BUOYGRAPHICSITEM_H
