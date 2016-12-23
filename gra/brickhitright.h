#ifndef BRICKHITRIGHT_H
#define BRICKHITRIGHT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>

class Brickhitright: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brickhitright(QGraphicsItem * parent=0);

};


#endif // BRICKHITRIGHT_H
