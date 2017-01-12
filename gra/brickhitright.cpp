#include "brickhitright.h"
#include "bullet.h"
#include <QList>
#include <typeinfo>
#include <qdebug.h>
#include <QList>
#include <bullet.h>
#include <QGraphicsScene>

Brickhitright::Brickhitright(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/brick-righthit.png"));
}

Brickhitright::~Brickhitright()
{

}



