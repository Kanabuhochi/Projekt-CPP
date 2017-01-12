#include "brickhitup.h"
#include "bullet.h"
#include <QList>
#include <typeinfo>
#include <qdebug.h>
#include <QList>
#include <bullet.h>
#include <QGraphicsScene>

Brickhitup::Brickhitup(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/brickuphit.png"));
}

Brickhitup::~Brickhitup()
{

}


