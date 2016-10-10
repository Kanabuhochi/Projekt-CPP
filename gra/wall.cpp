#include "wall.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Wall::Wall(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/wall.png"));
}

