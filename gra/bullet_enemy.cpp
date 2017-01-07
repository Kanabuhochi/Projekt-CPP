#include "bullet_enemy.h"
#include "wall.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include "game.h"
#include <typeinfo>
#include <QDebug>
#include <QObject>
//extern int zwrot1;
//extern int pociski_enemy;
//Enemy * enemy;
extern Game * game;
Bullet_enemy::Bullet_enemy(int zwrot1): QObject()//, int pociski_enemy): QObject()//, QGraphicsPixmapItem(parent)
{
    timer = new QTimer();
  //  this->pociski_enemy = pociski_enemy;

   // setPixmap(QPixmap(":/images/images/pocisk/gora.png"));

    //int zwrot1 = enemy->zwrot1;
    if(zwrot1 == 1)
    {
        setPixmap(QPixmap(":/images/images/pocisk/gora.png"));
       // QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch11()));
    //    connect(&timer,&QTimer::timeout,this,&Bullet_enemy::ruch11);
        timer->start(30);
    }
    else if(zwrot1==2)
    {
        setPixmap(QPixmap(":/images/images/pocisk/prawo.png"));
       // QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch22()));
    //    connect(&timer,&QTimer::timeout,this,&Bullet_enemy::ruch22);
        timer->start(30);
    }
    else if(zwrot1==3)
    {
        setPixmap(QPixmap(":/images/images/pocisk/dol.png"));
       // QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch33()));
     //   connect(&timer,&QTimer::timeout,this,&Bullet_enemy::ruch33);
        timer->start(30);
    }
    else if(zwrot1==4)
    {
        setPixmap(QPixmap(":/images/images/pocisk/lewo.png"));
      //  QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch44()));
     //   connect(&timer,&QTimer::timeout,this,&Bullet_enemy::ruch44);
        timer->start(30);
    }
}
/*void Bullet_enemy::move(int pociski_enemy)
{
    int zwrot1 = 1;
    if(zwrot1==1)
    {
        ruch11(pociski_enemy);
    }
    else if(zwrot1==2)
    {
        ruch22(pociski_enemy);
    }

    else if(zwrot1==3)
    {
        ruch33(pociski_enemy);
    }

    else if(zwrot1==4)
    {
        ruch44(pociski_enemy);
    }
}
*/
void Bullet_enemy::ruch11()
{
        //int pociski_enemy = enemy->pociski_enemy;
        QList<QGraphicsItem *> kolizje1 = collidingItems();
        for(int i = 0,  n = kolizje1.size(); i<n; i++)
        {
            if(typeid(*(kolizje1[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    timer->stop();
                    delete timer;
                    delete this;
        //            pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    timer->stop();
                    delete timer;
                    delete this;                    
       //             pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick))
            {
                    int x = kolizje1[i]->pos().x();
                    int y = kolizje1[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brickhitdown *brickhitdown = new Brickhitdown();
                    brickhitdown->setPos(x,y);
                    game->scene->addItem(brickhitdown);
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);

                    delete kolizje1[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitdown))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitright))
            {
                int x = kolizje1[i]->pos().x();
                int y = kolizje1[i]->pos().y();
                //qDebug<<"x"<<x<<"y"<<y;
                Brick_corner *brick_corner = new Brick_corner();
                brick_corner->setPos(x,y);
                game->scene->addItem(brick_corner);
                scene()->removeItem(kolizje1[i]);
                scene()->removeItem(this);

                delete kolizje1[i];
                delete this;
              //  pociski_gracz=pociski_gracz-1;
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitleft))
            {
                int x = kolizje1[i]->pos().x();
                int y = kolizje1[i]->pos().y();
                //qDebug<<"x"<<x<<"y"<<y;
                Brick_corner *brick_corner = new Brick_corner();
                brick_corner->setPos(x,y);
                game->scene->addItem(brick_corner);
                scene()->removeItem(kolizje1[i]);
                scene()->removeItem(this);

                delete kolizje1[i];
                delete this;
           //     pociski_gracz=pociski_gracz-1;
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    delete this;
            //        pociski_gracz=pociski_gracz-1;
                    return;
            }
        }
        setPos(x(),y()-10);
        if (pos().y() < 20)
        {
            scene()->removeItem(this);
            timer->stop();
            delete timer;
            delete this;
  //          pociski_enemy=pociski_enemy-1;
        }
}
void Bullet_enemy::ruch22()
{
        //int pociski_enemy = enemy->pociski_enemy;
        QList<QGraphicsItem *> kolizje2 = collidingItems();
        for(int i = 0,  n = kolizje2.size(); i<n; i++)
        {
            if(typeid(*(kolizje2[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    timer->stop();
                    delete timer;
                    delete this;
     //               pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    timer->stop();
                    delete timer;
                    delete this;
     //               pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brick))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brickhitleft *brickhitleft = new Brickhitleft();
                    brickhitleft->setPos(x,y);
                    game->scene->addItem(brickhitleft);
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitup))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitdown))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitleft))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
        }
        setPos(x()+10,y());
        if (pos().x() > 635)
        {
            scene()->removeItem(this);
            timer->stop();
            delete timer;
            delete this;
    //        pociski_enemy=pociski_enemy-1;
        }
}
void Bullet_enemy::ruch33()
{
        //int pociski_enemy = enemy->pociski_enemy;
        QList<QGraphicsItem *> kolizje3 = collidingItems();
        for(int i = 0,  b = kolizje3.size(); i<b; i++)
        {
            if(typeid(*(kolizje3[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    timer->stop();
                    delete timer;
                    delete this;
       //             pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    timer->stop();
                    delete timer;
                    delete this;
       //             pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brick))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brickhitup *brickhitup = new Brickhitup();
                    brickhitup->setPos(x,y);
                    game->scene->addItem(brickhitup);
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitup))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitright))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitleft))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
        }
        setPos(x(),y()+10);
        if (pos().y() > 535)
        {
            scene()->removeItem(this);
            timer->stop();
            delete timer;
            delete this;
      //      pociski_enemy=pociski_enemy-1;
        }
}
void Bullet_enemy::ruch44()
{
        // int pociski_enemy = enemy->pociski_enemy;
        QList<QGraphicsItem *> kolizje4 = collidingItems();
        for(int i = 0,  n = kolizje4.size(); i<n; i++)
        {
            if(typeid(*(kolizje4[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    timer->stop();
                    delete timer;
                    delete this;
             //       pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    timer->stop();
                //    delete timer;
                    delete this;
                //    pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brick))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brickhitright *brickhitright = new Brickhitright();
                    brickhitright->setPos(x,y);
                    game->scene->addItem(brickhitright);
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitup))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitdown))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    //qDebug<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitright))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    //pociski_gracz=pociski_gracz-1;
                    return;
            }
        }
        setPos(x()-10,y());
        if (pos().x() < 120)
        {
            scene()->removeItem(this);
            timer->stop();
            delete timer;
            delete this;
        //    pociski_enemy=pociski_enemy-1;
        }
}
