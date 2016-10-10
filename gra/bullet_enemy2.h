#ifndef BULLET_enemy2_H
#define BULLET_enemy2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>



class Bullet_enemy2: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet_enemy2(QGraphicsItem * parent=0);
public slots:
    void move();
    void ruch1();
    void ruch2();
    void ruch3();
    void ruch4();
};

#endif // BULLET_enemy2_H
