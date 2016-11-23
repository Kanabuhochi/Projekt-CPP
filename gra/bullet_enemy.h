#ifndef BULLET_enemy_H
#define BULLET_enemy_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "enemy.h"
#include <QTimer>



class Bullet_enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet_enemy(int zwrot);//, int pociski_enemy);
    QTimer * timer;
   // int pociski_enemy;
public slots:
    //void move(int pociski_enemy);
    void ruch11();
    void ruch22();
    void ruch33();
    void ruch44();
};

#endif // BULLET_enemy_H
