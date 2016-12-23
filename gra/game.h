#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "wall.h"
#include "brick.h"
#include "brick_corner.h"
#include "brickhitdown.h"
#include "brickhitup.h"
#include "brickhitright.h"
#include "brickhitleft.h"
#include "tree.h"
#include "ice.h"
#include "water.h"
#include "change.h"
#include "cursor.h"
#include <QList>
#include <level1.h>




class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QTimer * timer5;
    QGraphicsScene * scene;
    int enemies = 0;
    int move = 0;
    void menu();
    void play();
    QList<Brick *> bricks;


public slots:
    void spawn();
};

#endif // GAME_H
