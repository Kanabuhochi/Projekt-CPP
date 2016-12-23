#ifndef BRICKHITLEFT_H
#define BRICKHITLEFT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include "brick.h"
#include <typeinfo>

class Brickhitleft: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brickhitleft(QGraphicsItem * parent=0);

};



#endif // BRICKHITLEFT_H
