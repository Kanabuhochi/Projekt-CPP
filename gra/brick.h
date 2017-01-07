#ifndef BRICK_H
#define BRICK_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>

class Brick: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brick(QGraphicsItem * parent=0);
    ~Brick();
    void zburz();
};


#endif // BRICK_H
