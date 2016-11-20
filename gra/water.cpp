#include "water.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Water::Water(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/water.png"));
}

