#include "tree.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Tree::Tree(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setZValue(1);
    setPixmap(QPixmap(":/images/images/tlo/tree.png"));
}

