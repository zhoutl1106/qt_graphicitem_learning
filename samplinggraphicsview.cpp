#include "samplinggraphicsview.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

SamplingGraphicsView::SamplingGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new MyGridGraphicsScene;
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);
    setDragMode(QGraphicsView::ScrollHandDrag);
    scene->setSceneRect(-500,-500,1000,1000);

    shipGraphicsItem *item0 = new shipGraphicsItem;
    item0->setPos(0,0);
    scene->addItem(item0);

    buoyGraphicsItem *item1 = new buoyGraphicsItem(true,3);
    item1->setPos(100,100);
    scene->addItem(item1);
    buoyGraphicsItem *item2 = new buoyGraphicsItem(true,4);
    item2->setPos(200,200);
    scene->addItem(item2);

     responderItem05 = new responderGraphicsItem(true,5);
     responderItem05->setPos(-300,-300);
     scene->addItem(responderItem05);
     responderItem06 = new responderGraphicsItem(true,6);
     responderItem06->setPos(300,-300);
     scene->addItem(responderItem06);;
     responderItem07 = new responderGraphicsItem(true,7);
     responderItem07->setPos(300,300);
     scene->addItem(responderItem07);;
     responderItem08 = new responderGraphicsItem(true,8);
     responderItem08->setPos(-300,300);
     scene->addItem(responderItem08);;
     responderItem07->setResponderStatus(true);
}

void SamplingGraphicsView::addSamplingPoint(int index, double lat, double lon)
{
    SamplingGraphicsItem *item = new SamplingGraphicsItem(index, lat, lon);
    item->setPos(lat,lon);
    scene->addItem(item);
}

QList<int> SamplingGraphicsView::getSelectedPoints()
{
    selectedPointsList.clear();
    QList<QGraphicsItem*> tempList = items();
    //    qDebug()<<tempList.size();
    for(int i = 0;i < tempList.size(); i++)
    {
        if(tempList.at(i)->type() == TypeSampling)
        {
            //            qDebug()<<"checked"<<((SamplingGraphicsItem*)tempList.at(i))->checked();
            if(((SamplingGraphicsItem*)tempList.at(i))->checked())
            {
                selectedPointsList.append(((SamplingGraphicsItem*)tempList.at(i))->getIndex());
                //                qDebug()<<"index"<<((SamplingGraphicsItem*)tempList.at(i))->getIndex();
            }
        }
        else
        {
            //            qDebug()<<"type"<<TypeSampling<<tempList.at(i)->type();
        }
    }
    return selectedPointsList;
}

void SamplingGraphicsView::wheelEvent(QWheelEvent *event)
{
    if(event->delta() < 0)
        scale(0.5,0.5);
    else
        scale(2,2);
}

void SamplingGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void SamplingGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

void SamplingGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void SamplingGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(NULL != itemAt(event->pos()))
    {
        int temp = itemAt(event->pos())->type();
        switch(temp)
        {
        case TypeShip:
            qDebug()<<(QMessageBox::question(this,"请确认","确定要进入自导航模式吗？") == QMessageBox::Yes);
            break;
        case TypeBuoy:
            qDebug()<<"点击浮标";
            break;
        case TypeResponder:
            qDebug()<<"进入阵元解算模式";
            break;
        }
    }
}

void SamplingGraphicsView::keyPressEvent(QKeyEvent *event)
{

}

void SamplingGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace)
        scene->removeItem(items().at(items().size()-1));
    if(event->key() == Qt::Key_Escape)
        emit restore();
}
