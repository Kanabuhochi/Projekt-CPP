#ifndef BRICKHITUP_H
#define BRICKHITUP_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>

class Brickhitup: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brickhitup(QGraphicsItem * parent=0);
      ~Brickhitup();
};


#endif // BRICKHITUP_H
