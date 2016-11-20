#ifndef WATER_H
#define WATER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Water: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Water(QGraphicsItem * parent=0);
};

#endif // WATER_H
