#ifndef WALL_H
#define WALL_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Wall: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Wall(QGraphicsItem * parent=0);
};

#endif // WALL_H
