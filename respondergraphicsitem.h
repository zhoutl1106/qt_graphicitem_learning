#ifndef responderGRAPHICSITEM_H
#define responderGRAPHICSITEM_H

#include <QGraphicsItem>
#include "global_define.h"

class responderGraphicsItem : public QGraphicsItem
{
public:
    responderGraphicsItem(bool visual,int ind);
    QRectF boundingRect() const;
    int type() const { return TypeResponder; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget);
    bool visiable;
    int index;
    void setResponderStatus(bool t);

private:
    QPixmap responderPixmapYes;
    QPixmap responderPixmapNo;
    bool m_responderStatus;
};

#endif // responderGRAPHICSITEM_H
