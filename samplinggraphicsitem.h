#ifndef SAMPLINGGRAPHICSITEM_H
#define SAMPLINGGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QBrush>
#include "global_define.h"

class SamplingGraphicsItem : public QGraphicsItem
{
public:
    SamplingGraphicsItem(int i, double lat, double lon);
    QRectF boundingRect() const;
    int type() const { return TypeSampling; }
    int getIndex() { return index; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    bool checked();

private:
    int index;
    double lat;
    double lon;
    bool checkFlag;
    QPixmap checkedPixmap;
    QPixmap uncheckedPixmap;
};

#endif // SAMPLINGGRAPHICSITEM_H
