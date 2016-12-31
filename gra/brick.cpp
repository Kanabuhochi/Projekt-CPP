#include "brick.h"
#include "bullet.h"
#include <QList>
#include <typeinfo>
#include <qdebug.h>
#include <QList>
#include <bullet.h>
#include <QGraphicsScene>



Brick::Brick(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/images/tlo/brick.png"));
}

void Brick::zburz()
{
    setPixmap(QPixmap(":/images/images/tlo/brick-downhit.png"));
    qDebug()<<"TEST";
}



