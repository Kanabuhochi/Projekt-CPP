#include "floor.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Floor::Floor(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/floor.jpg"));
}

