#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>



class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
public slots:
    //void move();
    void ruch1();
    void ruch2();
    void ruch3();
    void ruch4();
};

#endif // BULLET_H
