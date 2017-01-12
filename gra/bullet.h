#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "brick.h"
#include "panzer.h"
#include "game.h"
#include "enemy.h"
#include "enemy_fast.h"
#include "wall.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QSignalMapper>
#include <QList>
#include <typeinfo>
#include <qdebug.h>
#include <level2.h>
#include "player.h"
#include <QMediaPlayer>


class Bullet: public QObject,public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet(int zwrot);
    QTimer * timer;
public slots:
    //void move();

    void ruch1();
    void ruch2();
    void ruch3();
    void ruch4();
};

#endif // BULLET_H
