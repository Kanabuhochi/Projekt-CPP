#include "game.h"
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QFocusEvent>

extern int zwrot;

Game::Game()
{

    scene = new QGraphicsScene();    
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg8.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Player();
    player->setScale(1);
    player->setPos(405,550);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    enemy = new Enemy();
    enemy->setScale(1);
    enemy->setPos(50,30);
    scene->addItem(enemy);

    int i=0;
    int j=0;
    for(i=90;i<755;i=i+99)
    {
        for(j=65;j<581;j=j+87)
        {
            water = new Water();
            water->setPos(i,j);
            scene->addItem(water);
        }
    }

    for(i=65;i<800;i=i+99)
    {
        for(j=45;j<600;j=j+87)
        {
            change = new Change();
            change->setPos(i,j);
            scene->addItem(change);
        }
    }

    show();

}




