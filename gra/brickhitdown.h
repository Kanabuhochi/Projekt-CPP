#ifndef BRICKHITDOWN_H
#define BRICKHITDOWN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>

class Brickhitdown: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brickhitdown(QGraphicsItem * parent=0);
};


#endif // BRICKHITDOWN_H
