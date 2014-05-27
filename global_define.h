#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsView>
#include <QMessageBox>

enum ItemType { TypeSampling = QGraphicsItem::UserType + 1,
                TypeBuoy = QGraphicsItem::UserType + 2,
                TypeShip = QGraphicsItem::UserType + 3,
                TypeResponder = QGraphicsItem::UserType + 4
              };


#endif // GLOBAL_DEFINE_H
