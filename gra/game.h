#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "wall.h"
#include "tree.h"
#include "ice.h"
#include "water.h"
#include "change.h"
#include "cursor.h"




class Game: public QGraphicsView
{
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
    QGraphicsScene * scene;
    int move = 0;
    void menu();

};

#endif // GAME_H
