#ifndef SAMPLINGGRAPHICSVIEW_H
#define SAMPLINGGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include "samplinggraphicsitem.h"
#include "buoygraphicsitem.h"
#include "shipgraphicsitem.h"
#include "respondergraphicsitem.h"
#include <QList>
#include "mygridgraphicsscene.h"

class SamplingGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SamplingGraphicsView(QWidget *parent = 0);
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void addSamplingPoint(int index,double lat,double lon);
    QList<int> getSelectedPoints();

signals:
    void restore();

public slots:

private:
    MyGridGraphicsScene *scene;
    QList<int> selectedPointsList;
    responderGraphicsItem* responderItem05;
    responderGraphicsItem* responderItem06;
    responderGraphicsItem* responderItem07;
    responderGraphicsItem* responderItem08;

};

#endif // SAMPLINGGRAPHICSVIEW_H
