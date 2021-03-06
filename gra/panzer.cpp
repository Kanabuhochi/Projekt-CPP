#include "panzer.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <typeinfo>
#include <wall.h>
#include "bullet.h"
#include "bullet_enemy.h"
#include <stdlib.h>
#include "change.h"
#include "game.h"
#include <time.h>
#include "exp.h"
#include <qdebug.h>
//extern int zwrot1;
extern Game * game;
extern Bullet * bullet;

Panzer::Panzer(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
        srand (time(NULL));
        int x = rand() % 1500 + 1500;
        int y = rand() % 3000 + 1500;
        setPixmap(QPixmap(":/images/images/enemy/enemy_up.png"));
        timer = new QTimer();
        timer1 = new QTimer();
        timer2 = new QTimer();

       // QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(30);  //37

       // QTimer * timer1 = new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(change()));
        timer1->start(y);

      //  QTimer * timer2 = new QTimer(this);
        connect(timer2,SIGNAL(timeout()),this,SLOT(str()));
        timer2->start(x);



}

void Panzer::str()
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

void Panzer::change()
{
    zwrot1 = rand() % 4 + 1;
}
void Panzer::move()
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


void Panzer::ruch1()//gora
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
        else if(typeid(*(kolizje_sciana[i])) == typeid(Bullet))
        {
            if(health > 0)
            {

                //qDebug()<<"PANZER";
                scene()->removeItem(kolizje_sciana[i]);
                delete kolizje_sciana[i];
                game->pociski_gracz=game->pociski_gracz-1;
                health -= 1;
                return;
            }
            else if(health == 0)
            {
                //qDebug()<<"PANZER";
                Exp *exp = new Exp();
                game->score += 500;
                game->newscore += 500;
                game->tank->play();
                game->pancer += 1;
                exp->setPos(pos().x(),pos().y());
                game->scene->addItem(exp);
                scene()->removeItem(kolizje_sciana[i]);
                scene()->removeItem(this);
                delete kolizje_sciana[i];
                delete this;
                game->pociski_gracz= game->pociski_gracz-1;
                game->enemies -= 1;
                //qDebug()<<"Enemies = "<<game->enemies;
                if(game->enemies == 0 && game->total==0)
                {
                    game->stage += 1;
                    game->scoring->start(3000);

                }
                return;
            }

        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x(),y()+4);
                zwrot1= rand() % 4 + 1;
        }

    }
}

void Panzer::ruch2()//prawo
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
        else if(typeid(*(kolizje_sciana[i])) == typeid(Bullet))
        {
            if(health > 0)
            {
                //qDebug()<<"PANZER";
                scene()->removeItem(kolizje_sciana[i]);
                delete kolizje_sciana[i];
                 game->pociski_gracz= game->pociski_gracz-1;
                health -= 1;
                return;
            }
            else if(health == 0)
            {
                Exp *exp = new Exp();
                exp->setPos(pos().x(),pos().y());
                game->scene->addItem(exp);
                game->score += 500;
                game->newscore += 500;
                game->tank->play();
                game->pancer += 1;
                //qDebug()<<"PANZER";
                scene()->removeItem(kolizje_sciana[i]);
                scene()->removeItem(this);
                delete kolizje_sciana[i];
                delete this;
                game->pociski_gracz= game->pociski_gracz-1;
                game->enemies -= 1;
                //qDebug()<<"Enemies = "<<game->enemies;
                if(game->enemies == 0 && game->total==0)
                {
                    game->stage += 1;
                    game->scoring->start(3000);
                }
                return;
            }

        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x()-4,y());
                zwrot1= rand() % 4 + 1;
        }

    }
}

void Panzer::ruch3()//dol
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
        else if(typeid(*(kolizje_sciana[i])) == typeid(Bullet))
        {
            if(health > 0)
            {

                //qDebug()<<"PANZER";
                scene()->removeItem(kolizje_sciana[i]);
                delete kolizje_sciana[i];
                game->pociski_gracz= game->pociski_gracz-1;
                health -= 1;
                return;
            }
            else if(health == 0)
            {
                Exp *exp = new Exp();
                exp->setPos(pos().x(),pos().y());
                game->scene->addItem(exp);
                game->score += 500;
                game->newscore += 500;
                game->tank->play();
                game->pancer += 1;

                scene()->removeItem(kolizje_sciana[i]);
                scene()->removeItem(this);
                delete kolizje_sciana[i];
                delete this;
                 game->pociski_gracz= game->pociski_gracz-1;
                game->enemies -= 1;
                //qDebug()<<"Enemies = "<<game->enemies;
                if(game->enemies == 0 && game->total==0)
                {
                    game->stage += 1;

                    game->scoring->start(3000);
                }
                return;
            }

        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x(),y()-4);
                zwrot1= rand() % 4 + 1;
        }

    }
}

void Panzer::ruch4()//lewo
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
        else if(typeid(*(kolizje_sciana[i])) == typeid(Bullet))
        {
            if(health > 0)
            {
                //qDebug()<<"PANZER";
                scene()->removeItem(kolizje_sciana[i]);
                delete kolizje_sciana[i];
                 game->pociski_gracz=game->pociski_gracz-1;
                health -= 1;
                return;
            }
            else if(health == 0)
            {
                Exp *exp = new Exp();
                exp->setPos(pos().x(),pos().y());
                game->scene->addItem(exp);
                game->score += 500;
                game->pancer += 1;
                game->tank->play();
                scene()->removeItem(kolizje_sciana[i]);
                scene()->removeItem(this);
                delete kolizje_sciana[i];
                delete this;
                 game->pociski_gracz= game->pociski_gracz-1;
                game->enemies -= 1;
                //qDebug()<<"Enemies = "<<game->enemies;
                if(game->enemies == 0 && game->total==0)
                {
                    game->stage += 1;
                    game->scoring->start(3000);
                }
                return;
            }

        }
        else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner) || typeid(*(kolizje_sciana[i])) == typeid(Water))
        {
                setPos(x()+4,y());
                zwrot1= rand() % 4 + 1;
        }

    }
}
