#include "samplinggraphicsitem.h"


SamplingGraphicsItem::SamplingGraphicsItem(int i, double la, double lo)
{
    index = i;
    lat = la;
    lon = lo;
    checkFlag = false;
    checkedPixmap = QPixmap(":/image/greenFlag.png");
    uncheckedPixmap = QPixmap(":/image/redFlag.png");
}

QRectF SamplingGraphicsItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 -penWidth / 2,
                  110 + penWidth, 32 + penWidth);
}

void SamplingGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget)
{
//    qDebug()<<this->scene()->views().takeFirst()->transform();
    painter->setTransform(this->scene()->views().takeFirst()->transform().inverted(), true);
    if(checkFlag)
        painter->drawPixmap(0,0,checkedPixmap);
    else
        painter->drawPixmap(0,0,uncheckedPixmap);
    painter->drawText(28,10,"测量点 " + QString::number(index));
    painter->drawText(25,25,"(" + QString::number(lat) + " N, " + QString::number(lon) + " E)");
}

void SamplingGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void SamplingGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void SamplingGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        checkFlag = true;
    if(event->button() == Qt::RightButton)
        checkFlag = false;
    update();
}

bool SamplingGraphicsItem::checked()
{
    return checkFlag;
}
