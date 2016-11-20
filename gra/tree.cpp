#include "tree.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Tree::Tree(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/tree.png"));
}

