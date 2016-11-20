#include "ice.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Ice::Ice(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/ice.png"));
}

