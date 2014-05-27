#ifndef MYGRIDGRAPHICSSCENE_H
#define MYGRIDGRAPHICSSCENE_H

#include <QGraphicsScene>
#include "global_define.h"

class MyGridGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyGridGraphicsScene(QObject *parent = 0);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

signals:

public slots:

};

#endif // MYGRIDGRAPHICSSCENE_H
