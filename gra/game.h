#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "enemy2.h"
#include "wall.h"
#include "change.h"




class Game: public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;
    Player * player;
    Wall * wall;
    Enemy * enemy;
    Change * change;
    Enemy2 * enemy2;

};

#endif // GAME_H
