#include "remaining.h"
#include "game.h"
extern Game * game;
Remaining::Remaining(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //setPixmap(QPixmap(":/remaining/images/remaining/20.png"));
    setPixmap(QPixmap(":/images/images/tlo/rem.png"));

}
