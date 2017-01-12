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
    Bullet_enemy(int zwrot);
    ~Bullet_enemy();
    QTimer * timer;
public slots:
    void ruch11();
    void ruch22();
    void ruch33();
    void ruch44();
};

#endif // BULLET_enemy_H
