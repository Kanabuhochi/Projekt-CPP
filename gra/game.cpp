#include "game.h"
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QFocusEvent>
#include "menu.h"
#include "cursor.h"

extern int zwrot;
//extern Menu * menu;

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setScene(scene);
    menu();
}

void Game::menu()
{

    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/menu2.png")));
    Cursor*cursor = new Cursor();
    cursor->setScale(1);
    cursor->setPos(235,290);
    cursor->setFlag(QGraphicsItem::ItemIsFocusable);
    cursor->setFocus();
    scene->addItem(cursor);

}


/*

    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg8.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

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
            ice = new Ice();
            ice->setPos(i,j);
            scene->addItem(ice);
        }
    }
    player = new Player();
    player->setScale(1);
    player->setPos(405,550);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(player);
    player->setFocus();
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
*/
