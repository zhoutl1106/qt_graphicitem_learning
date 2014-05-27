#include "mygridgraphicsscene.h"

MyGridGraphicsScene::MyGridGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void MyGridGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->fillRect(rect,QColor(0,117,169));
    const int gridSize = 200;

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

//    qDebug() << lines.size();
    painter->setPen(QPen(Qt::lightGray,0));
    painter->drawLines(lines.data(), lines.size());

    /*const QRectF crect = rect.normalized();
    painter->save();
    painter->setPen(QPen(Qt::lightGray,0));
    int l = int(crect.left());
    l -= (l % 10);

    int r = int(crect.right());
    r -= (r % 10);
    if(r < int(crect.right()))
    r += 10;

    int t = int(crect.top());
    t -= (t % 10);

    int b = int(crect.bottom());
    b -= (b % 10);
    if(b < int(crect.bottom()))
    b += 10;

    for( int x = l; x <= r; x+=10)
    for( int y = t; y <= b; y+=10)
    painter->drawPoint(x,y);

    painter->restore();*/
}
