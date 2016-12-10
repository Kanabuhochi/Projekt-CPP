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
#include "wall.h"
#include "brick.h"
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
    /*
    Game();
    QGraphicsScene * scene;
    Player * player;
    Wall * wall;
    Water * water;
    Tree * tree;
    Ice * ice;
    Enemy * enemy;
    Change * change;
    */
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
