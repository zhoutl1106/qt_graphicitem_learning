#ifndef shipGRAPHICSITEM_H
#define shipGRAPHICSITEM_H

#include <QGraphicsItem>
#include "global_define.h"

class shipGraphicsItem : public QGraphicsItem
{
public:
    shipGraphicsItem();
    QRectF boundingRect() const;
    int type() const { return TypeShip; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget);

private:
    QPixmap shipPixmap;
};

#endif // shipGRAPHICSITEM_H
