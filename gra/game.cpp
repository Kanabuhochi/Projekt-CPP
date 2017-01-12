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
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,795,595);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/floor.jpg")));
    setScene(scene);
    menus = new QTimer();
    connect(menus,SIGNAL(timeout()),this,SLOT(start()));
    beg = new QGraphicsPixmapItem();
    beg->setPixmap(QPixmap(":/images/images/tlo/menu2.png"));
    beg->setPos(0,600);
    beg->setPos(0,600);
    scene->addItem(beg);
    menus->start(10);
    shot = new QMediaPlayer;
    shot->setMedia(QUrl("qrc:/sound/sounds/SHOT.wav"));
    shot->setVolume(100);
    endo = new QMediaPlayer;
    endo->setMedia(QUrl("qrc:/sound/sounds/GAME OVER.wav"));
    endo->setVolume(100);


}
void Game::menu()
{
    timer = new QTimer();
    timer2 = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(gover()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(endscreen()));
    rst = new QTimer();
    connect(rst,SIGNAL(timeout()),this,SLOT(reset()));
    score = 0;
    move = 0;
    cont = 1;
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
            klocki.insert(0,enemy);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned enemy"<<enemies;

        }
        else if(x==2)
        {
            Enemy * enemy = new Enemy();
            enemy->setScale(1);
            enemy->setPos(385,45); // 395 i 740
            scene->addItem(enemy);
            klocki.insert(0,enemy);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned enemy"<<enemies;
        }
        else if(x==3)
        {
            Enemy * enemy = new Enemy();
            enemy->setScale(1);
            enemy->setPos(625,45); // 395 i 740
            scene->addItem(enemy);
            klocki.insert(0,enemy);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned enemy"<<enemies;
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
            klocki.insert(0,enemy_fast);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned fast"<<enemies;
        }
        else if(x==2)
        {
            Enemy_fast * enemy_fast = new Enemy_fast();
            enemy_fast->setScale(1);
            enemy_fast->setPos(385,45); // 395 i 740
            scene->addItem(enemy_fast);
            klocki.insert(0,enemy_fast);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned fast"<<enemies;
        }
        else if(x==3)
        {
            Enemy_fast * enemy_fast = new Enemy_fast();
            enemy_fast->setScale(1);
            enemy_fast->setPos(625,45); // 395 i 740
            scene->addItem(enemy_fast);
            klocki.insert(0,enemy_fast);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned fast"<<enemies;
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
            klocki.insert(0,panzer);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned panzer"<<enemies;
        }
        else if(x==2)
        {
            Panzer * panzer = new Panzer();
            panzer->setScale(1);
            panzer->setPos(385,45); // 395 i 740
            scene->addItem(panzer);
            klocki.insert(0,panzer);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned panzer"<<enemies;
        }
        else if(x==3)
        {
            Panzer * panzer = new Panzer();
            panzer->setScale(1);
            panzer->setPos(625,45); // 395 i 740
            scene->addItem(panzer);
            klocki.insert(0,panzer);
            enemies=enemies+1;
            total -= 1;
            //qDebug()<<"Enemies ="<<enemies;
            //qDebug()<<"Spawned panzer"<<enemies;
        }

        scene->removeItem(remains[remains.size() - 1]);
        delete (remains.takeAt(remains.size() - 1));
    }


}
void Game::check()
{
    //qDebug()<<"Score = "<<score;
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
    timer5 = new QTimer();
    checker = new QTimer();
    connect(timer5,SIGNAL(timeout()),this,SLOT(spawn()));
    connect(checker,SIGNAL(timeout()),this,SLOT(check()));
    connect(scoring,SIGNAL(timeout()),this,SLOT(scores()));
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
    tank = new QMediaPlayer();
    tank->setMedia(QUrl("qrc:/sound/sounds/TANKHIT.wav"));
    tank->setVolume(100);
    wall = new QMediaPlayer();
    wall->setMedia(QUrl("qrc:/sound/sounds/WALL.wav"));
    wall->setVolume(100);
}
void Game::gover()
{
    cont = 0;
    checker->stop();
    timer5->stop();
    if(gam->pos().y()>280)
    {
        gam->setPos(gam->x(),gam->y()-1);
        over->setPos(over->x(),over->y()-1);
    }
    else if(gam->pos().y() == 280)
    {
        timer->stop();
        delete timer;

       // timer2->start(4000);
        scoring->start(3000);
    }

}
void Game::endscreen()
{
    qDebug()<<"test";
    scene->clear();
    endmusic();
    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/end.png")));


 //   klocki.clear();


    rst->start(4000);
    timer2->stop();

}
void Game::start()
{
   //
    if(beg->pos().y()>0)
    {
        beg->setPos(beg->x(),beg->y()-5);
    }
    else if(beg->pos().y() == 0)
    {
        menus->stop();
        delete menus;
        menu();
        bhit = new QMediaPlayer;
        bhit->setMedia(QUrl("qrc:/sound/sounds/BRICKHIT.wav"));
        bhit->setVolume(100);
    }
}
void Game::reset()
{
    rst->stop();
    menu();
}
void Game::scores()
{
    delete gam;
    delete over;
    delete timer5;
    delete checker;

    scene->clear();
    klocki.clear();
    QString n = QString("%1").arg(normal*100);
    QString f = QString("%1").arg(fast*200);
    QString p = QString("%1").arg(pancer*500);
    QString nk = QString("%1").arg(normal);
    QString fk = QString("%1").arg(fast);
    QString pk = QString("%1").arg(pancer);
    QString sc = QString("%1").arg(normal+fast+pancer);
    QString tot = QString("%1").arg(score);
    normalo = new QGraphicsTextItem(n);
    fasto = new QGraphicsTextItem(f);
    pancero = new QGraphicsTextItem(p);
    nn = new QGraphicsTextItem(nk);
    ff = new QGraphicsTextItem(fk);
    pp = new QGraphicsTextItem(pk);
    sco = new QGraphicsTextItem(sc);
    totalo = new QGraphicsTextItem(tot);
    high = new QGraphicsTextItem("20000");

    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/scores.png")));

    normalo->setPos(100,217);
    normalo->setScale(3);
    normalo->setDefaultTextColor(Qt::white);
    scene->addItem(normalo);

    fasto->setPos(100,277);
    fasto->setScale(3);
    fasto->setDefaultTextColor(Qt::white);
    scene->addItem(fasto);

    pancero->setPos(100,337);
    pancero->setScale(3);
    pancero->setDefaultTextColor(Qt::white);
    scene->addItem(pancero);

    nn->setPos(300,217);
    nn->setScale(3);
    nn->setDefaultTextColor(Qt::white);
    scene->addItem(nn);

    ff->setPos(300,277);
    ff->setScale(3);
    ff->setDefaultTextColor(Qt::white);
    scene->addItem(ff);

    pp->setPos(300,337);
    pp->setScale(3);
    pp->setDefaultTextColor(Qt::white);
    scene->addItem(pp);

    sco->setPos(300,385);
    sco->setScale(3);
    sco->setDefaultTextColor(Qt::white);
    scene->addItem(sco);

    totalo->setPos(200,155);
    totalo->setScale(3);
    totalo->setDefaultTextColor(Qt::yellow);
    scene->addItem(totalo);

    high->setPos(450,35);
    high->setScale(3);
    high->setDefaultTextColor(Qt::yellow);
    scene->addItem(high);

    normal = 0;
    fast = 0;
    pancer = 0;
    newscore = 0;
    scoring->stop();
    delete scoring;
    if(cont == 1)
    {
        nexto = new QTimer();
        connect(nexto,SIGNAL(timeout()),this,SLOT(next()));
        nexto->start(3000);
    }
    else if(cont == 0)
    {
       timer2->start(4000);
    }
}

void Game::next()
{
    delete nexto;
    Nextlevel * nextlevel = new Nextlevel();
}
void Game::endmusic()
{
    QMediaPlayer * gm = new QMediaPlayer;
    gm->setMedia(QUrl("qrc:/sound/sounds/END.wav"));
    gm->setVolume(100);
    gm->play();
}
