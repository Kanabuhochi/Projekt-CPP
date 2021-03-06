#include "enemy_fast.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <typeinfo>
#include <wall.h>
#include "bullet_enemy.h"
#include <stdlib.h>
#include "change.h"
#include "game.h"
#include <time.h>
#include <qdebug.h>
Enemy_fast::Enemy_fast(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
        srand (time(NULL));
        int x = rand() % 1500 + 1500;
        int y = rand() % 2000 + 1500;
        setPixmap(QPixmap(":/images/images/enemy/enemy_up.png"));
        timer = new QTimer();
        timer1 = new QTimer();
        timer2 = new QTimer();

       // QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(20);  //32

       // QTimer * timer1 = new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(change()));
        timer1->start(y);

      //  QTimer * timer2 = new QTimer(this);
        connect(timer2,SIGNAL(timeout()),this,SLOT(str()));
        timer2->start(x);



}



void Enemy_fast::str()
{
    if(zwrot1 == 1)
    {
       // if (pociski_enemy==0)
      //  {
          //  pociski_enemy=pociski_enemy+1;
            Bullet_enemy * bullet_enemy = new Bullet_enemy(zwrot1);//,pociski_enemy);
            bullet_enemy->setPos(x()-7,y()-20);
            bullet_enemy->setScale(0.7);
            scene()->addItem(bullet_enemy);
            ////qDebug()<<"Pociski="<<pociski_enemy;

     //   }
     //   else if(pociski_enemy!=0)
     //   {

     //   }
     }
    else if(zwrot1 == 2)
    {
      //  if(pociski_enemy==0)
     //   {
     //       pociski_enemy=pociski_enemy+1;
            Bullet_enemy * bullet_enemy = new Bullet_enemy(zwrot1);//,pociski_enemy);
            bullet_enemy->setPos(x()+20,y()-7);
            bullet_enemy->setScale(0.7);
            scene()->addItem(bullet_enemy);
            ////qDebug()<<"Pociski="<<pociski_enemy;

     //   }
     //   else if(pociski_enemy!=0)
    //    {

   //     }
    }
    else if(zwrot1 == 3)
    {
    //    if(pociski_enemy==0)
    //    {
     //       pociski_enemy=pociski_enemy+1;
            Bullet_enemy * bullet_enemy = new Bullet_enemy(zwrot1);//,pociski_enemy);
            bullet_enemy->setPos(x()-7,y()+20);
            bullet_enemy->setScale(0.7);
            scene()->addItem(bullet_enemy);
            ////qDebug()<<"Pociski="<<pociski_enemy;
       // }
     //   else if(pociski_enemy!=0)
     //   {

     //   }
    }
    else if(zwrot1 == 4)
    {
   //     if(pociski_enemy==0)
     //   {
     //       pociski_enemy=pociski_enemy+1;
            Bullet_enemy * bullet_enemy = new Bullet_enemy(zwrot1);//,pociski_enemy);
            bullet_enemy->setPos(x()-20,y()-7);
            bullet_enemy->setScale(0.7);
            scene()->addItem(bullet_enemy);
            ////qDebug()<<"Pociski="<<pociski_enemy;
       // }
    //    else if(pociski_enemy!=0)
   //     {

   //     }
    }
}

void Enemy_fast::change()
{
    zwrot1 = rand() % 4 + 1;
}
void Enemy_fast::move()
{
    if(zwrot1==1)
    {
        setPixmap(QPixmap(":/images/images/enemy/up.png"));
        ruch1();
    }
    else if(zwrot1==2)
    {
        setPixmap(QPixmap(":/images/images/enemy/right.png"));
        ruch2();
    }

    else if(zwrot1==3)
    {
        setPixmap(QPixmap(":/images/images/enemy/down.png"));
        ruch3();
    }

    else if(zwrot1==4)
    {
        setPixmap(QPixmap(":/images/images/enemy/left.png"));
        ruch4();
    }
}


void Enemy_fast::ruch1()//gora
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_up.png"));

    if (pos().y() > 40)
    {
        setPos(x(),y()-3);
    }
    else if (pos().y() <= 40)
    {
        zwrot1 = rand() % 4 + 1;
        //ruch4();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x(),y()+4);
                zwrot1= rand() % 4 + 1;
        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x(),y()+4);
                zwrot1= rand() % 4 + 1;
        }

    }
}

void Enemy_fast::ruch2()//prawo
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_right.png"));

    if (pos().x() < 630)
    {
        setPos(x()+3,y());
    }
    else if (pos().x() >= 630)
    {
        zwrot1 = rand() % 4 + 1;
        //ruch1();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x()-4,y());
                zwrot1= rand() % 4 + 1;
        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x()-4,y());
                zwrot1= rand() % 4 + 1;
        }

    }
}

void Enemy_fast::ruch3()//dol
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_down.png"));

    if (pos().y() < 530)
    {
        setPos(x(),y()+3);
    }
    else if (pos().y() >= 530)
    {
        zwrot1 = rand() % 4 + 1;
        //ruch2();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x(),y()-4);
                zwrot1= rand() % 4 + 1;
        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x(),y()-4);
                zwrot1= rand() % 4 + 1;
        }

    }
}

void Enemy_fast::ruch4()//lewo
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_left.png"));

    if (pos().x() > 141)
    {
        setPos(x()-3,y());

    }
    else if (pos().x() <= 141)
    {
        zwrot1 = rand() % 4 + 1;
        //ruch3();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x()+4,y());
                zwrot1= rand() % 4 + 1;
        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x()+4,y());
                zwrot1= rand() % 4 + 1;
        }

    }
}
