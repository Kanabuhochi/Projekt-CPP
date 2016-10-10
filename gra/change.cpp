#include "change.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Change::Change(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/tlo/change.png"));
}

