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
#include "remaining.h"
#include <qdebug.h>
extern Player * player;

Game::Game()
{

    timer5 = new QTimer();
    connect(timer5,SIGNAL(timeout()),this,SLOT(spawn()));

    checker = new QTimer();
    connect(checker,SIGNAL(timeout()),this,SLOT(check()));

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
    Cursor * cursor = new Cursor();
    cursor->setScale(1);
    cursor->setPos(235,290);
    cursor->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(cursor);
    cursor->setFocus();

}

void Game::spawn()
{
    srand (time(NULL));
    int x = rand() % 3 + 1;
    int y = rand() % 10;
   if (y <= 4)
    {
        if(x==1)
        {
            Enemy * enemy = new Enemy();
            enemy->setScale(1);
            enemy->setPos(145,45); // 395 i 740
            scene->addItem(enemy);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned enemy"<<enemies;

        }
        else if(x==2)
        {
            Enemy * enemy = new Enemy();
            enemy->setScale(1);
            enemy->setPos(385,45); // 395 i 740
            scene->addItem(enemy);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned enemy"<<enemies;
        }
        else if(x==3)
        {
            Enemy * enemy = new Enemy();
            enemy->setScale(1);
            enemy->setPos(625,45); // 395 i 740
            scene->addItem(enemy);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned enemy"<<enemies;
        }
        scene->removeItem(remains[remains.size() - 1]);
        delete (remains.takeAt(remains.size() - 1));

    }
   if (y <=7 && y > 4)
    {
        if(x==1)
        {
            Enemy_fast * enemy_fast = new Enemy_fast;
            enemy_fast->setScale(1);
            enemy_fast->setPos(145,45); // 395 i 740
            scene->addItem(enemy_fast);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned fast"<<enemies;
        }
        else if(x==2)
        {
            Enemy_fast * enemy_fast = new Enemy_fast();
            enemy_fast->setScale(1);
            enemy_fast->setPos(385,45); // 395 i 740
            scene->addItem(enemy_fast);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned fast"<<enemies;
        }
        else if(x==3)
        {
            Enemy_fast * enemy_fast = new Enemy_fast();
            enemy_fast->setScale(1);
            enemy_fast->setPos(625,45); // 395 i 740
            scene->addItem(enemy_fast);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned fast"<<enemies;
        }
        scene->removeItem(remains[remains.size() - 1]);
        delete (remains.takeAt(remains.size() - 1));

    }
   else if (y == 8 || y == 9)
    {
        if(x==1)
        {
            Panzer * panzer = new Panzer();
            panzer->setScale(1);
            panzer->setPos(145,45); // 395 i 740
            scene->addItem(panzer);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned panzer"<<enemies;
        }
        else if(x==2)
        {
            Panzer * panzer = new Panzer();
            panzer->setScale(1);
            panzer->setPos(385,45); // 395 i 740
            scene->addItem(panzer);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned panzer"<<enemies;
        }
        else if(x==3)
        {
            Panzer * panzer = new Panzer();
            panzer->setScale(1);
            panzer->setPos(625,45); // 395 i 740
            scene->addItem(panzer);
            enemies=enemies+1;
            total -= 1;
            qDebug()<<"Enemies ="<<enemies;
            qDebug()<<"Spawned panzer"<<enemies;
        }

        scene->removeItem(remains[remains.size() - 1]);
        delete (remains.takeAt(remains.size() - 1));


    }


}
void Game::check()
{
    qDebug()<<"Score = "<<score;
    qDebug()<<"Remainig = "<<total;
    if(enemies>=4)
    {
        timer5->stop();
        qDebug()<<"Spawning stopped";
    }
    else if(enemies<4)
    {
        timer5->start(3000);
        qDebug()<<"Keep spawning";
    }
    if (total == 0)
    {
        timer5->stop();
    }
}

void Game::play()
{
    for(int h = 70; h <= 260; h += 20)
        for(int z = 710; z <= 730; z += 20)
        {
            Remaining *remaining = new Remaining();
            remaining->setPos(z,h);
            remaining->setScale(2.5); //2.5
            scene->addItem(remaining);
            remains.append(remaining);
        }
    timer5->start(3000);
    checker->start(4500);
}

