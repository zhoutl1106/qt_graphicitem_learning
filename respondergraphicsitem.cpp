#include "respondergraphicsitem.h"


responderGraphicsItem::responderGraphicsItem(bool visual, int ind)
{
    visiable = visual;
    this->setVisible(visiable);
    index = ind;
    responderPixmapYes = QPixmap(":/image/responderYes.png");
    responderPixmapNo = QPixmap(":/image/responderNo.png");
    m_responderStatus = false;
}

QRectF responderGraphicsItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 -penWidth / 2,
                  110 + penWidth, 32 + penWidth);
}

void responderGraphicsItem::setResponderStatus(bool t)
{
    m_responderStatus = t;
    update();
}

void responderGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setTransform(this->scene()->views().takeFirst()->transform().inverted(), true);
    if(m_responderStatus)
        painter->drawPixmap(0,0,responderPixmapYes);
    else
        painter->drawPixmap(0,0,responderPixmapNo);
    painter->drawText(28,10,"应答器 0" + QString::number(index));
}
