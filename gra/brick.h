#ifndef BRICK_H
#define BRICK_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Brick: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brick(QGraphicsItem * parent=0);
    ~Brick();
};


#endif // BRICK_H
