#include "brick_corner.h"
#include "bullet.h"
#include <QList>
#include <typeinfo>
#include <qdebug.h>
#include <QList>
#include <bullet.h>
#include <QGraphicsScene>

Brick_corner::Brick_corner(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/tlo/brick-corner.png"));
}

Brick_corner::~Brick_corner()
{

}
