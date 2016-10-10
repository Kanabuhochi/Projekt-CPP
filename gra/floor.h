#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Floor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Floor(QGraphicsItem * parent=0);
};



#endif // FLOOR_H
