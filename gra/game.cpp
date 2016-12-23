#include "game.h"
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <stdlib.h>
#include <typeinfo>
#include "enemy_fast.h"
#include <time.h>
#include "panzer.h"
#include <QFocusEvent>
#include "menu.h"
#include <qdebug.h>

extern int zwrot;
//extern Menu * menu;

Game::Game()
{

    timer5 = new QTimer();
    connect(timer5,SIGNAL(timeout()),this,SLOT(spawn()));



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

void Game::spawn()
{
    srand (time(NULL));
    int x =rand() % 3 + 1;

    if(x==1)
    {
        Enemy * enemy = new Enemy();
        enemy->setScale(1);
        enemy->setPos(145,45); // 395 i 740
        scene->addItem(enemy);
        enemies=enemies+1;
        qDebug()<<"Enemies="<<enemies;
    }
    else if(x==2)
    {
        Enemy * enemy = new Enemy();
        enemy->setScale(1);
        enemy->setPos(385,45); // 395 i 740
        scene->addItem(enemy);
        enemies=enemies+1;
        qDebug()<<"Enemies="<<enemies;
    }
    else if(x==3)
    {
        Enemy * enemy = new Enemy();
        enemy->setScale(1);
        enemy->setPos(625,45); // 395 i 740
        scene->addItem(enemy);
        enemies=enemies+1;
        qDebug()<<"Enemies="<<enemies;
    }
    if(enemies==20)
    {
        timer5->stop();
        delete timer5;
    }

}

void Game::play()
{
  //  for(int i=145;i<=625;i+=240)
  //  {
        Panzer * panzer = new Panzer();
        panzer->setScale(1);
        panzer->setPos(385,45); //395 i 740
        scene->addItem(panzer);
        enemies=enemies+1;
        qDebug()<<"Enemies="<<enemies;
 //   }
   // timer5->start(10000);

/*
    srand (time(NULL));
    QTimer * spawner = new QTimer(this);
    connect(spawner,SIGNAL(timeout()),this,SLOT(play()));
    spawner->start(5000);
    spawn();

*/
//spawn();
}

 //   srand (time(NULL));
 //   QTimer * spawner = new QTimer(this);
 //   connect(spawner,SIGNAL(timeout()),this,SLOT(spawn()));
 //   spawner->start(3000);
 //   spawn();



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
