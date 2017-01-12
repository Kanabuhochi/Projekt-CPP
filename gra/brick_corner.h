#ifndef BRICK_CORNER_H
#define BRICK_CORNER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Brick_corner: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   Brick_corner(QGraphicsItem * parent=0);
   ~Brick_corner();

};


#endif // BRICK_CORNER_H
