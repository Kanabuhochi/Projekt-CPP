#include "bullet_enemy.h"
#include "wall.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
extern int zwrot1;
extern int pociski_enemy;

Bullet_enemy::Bullet_enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

   // setPixmap(QPixmap(":/images/images/pocisk/gora.png"));


    if(zwrot1==1)
    {
        setPixmap(QPixmap(":/images/images/pocisk/gora.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch1()));
        timer->start(30);
    }
    else if(zwrot1==2)
    {
        setPixmap(QPixmap(":/images/images/pocisk/prawo.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch2()));
        timer->start(30);
    }
    else if(zwrot1==3)
    {
        setPixmap(QPixmap(":/images/images/pocisk/dol.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch3()));
        timer->start(30);
    }
    else if(zwrot1==4)
    {
        setPixmap(QPixmap(":/images/images/pocisk/lewo.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch4()));
        timer->start(30);
    }
}
void Bullet_enemy::move()
{
    if(zwrot1==1)
    {
        ruch1();
    }
    else if(zwrot1==2)
    {
        ruch2();
    }

    else if(zwrot1==3)
    {
        ruch3();
    }

    else if(zwrot1==4)
    {
        ruch4();
    }
}
void Bullet_enemy::ruch1()
{
        QList<QGraphicsItem *> kolizje1 = collidingItems();
        for(int i = 0,  n = kolizje1.size(); i<n; i++)
        {
            if(typeid(*(kolizje1[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
        }
        setPos(x(),y()-10);
        if (pos().y() < 0)
        {
            scene()->removeItem(this);
            delete this;
            pociski_enemy=pociski_enemy-1;
        }
}
void Bullet_enemy::ruch2()
{
        QList<QGraphicsItem *> kolizje2 = collidingItems();
        for(int i = 0,  n = kolizje2.size(); i<n; i++)
        {
            if(typeid(*(kolizje2[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
        }
        setPos(x()+10,y());
        if (pos().x() > 747)
        {
            scene()->removeItem(this);
            delete this;
            pociski_enemy=pociski_enemy-1;
        }
}
void Bullet_enemy::ruch3()
{
        QList<QGraphicsItem *> kolizje3 = collidingItems();
        for(int i = 0,  b = kolizje3.size(); i<b; i++)
        {
            if(typeid(*(kolizje3[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
        }
        setPos(x(),y()+10);
        if (pos().y() > 560)
        {
            scene()->removeItem(this);
            delete this;
            pociski_enemy=pociski_enemy-1;
        }
}
void Bullet_enemy::ruch4()
{
        QList<QGraphicsItem *> kolizje4 = collidingItems();
        for(int i = 0,  n = kolizje4.size(); i<n; i++)
        {
            if(typeid(*(kolizje4[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Player))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    pociski_enemy=pociski_enemy-1;
                    return;
            }
        }
        setPos(x()-10,y());
        if (pos().x() < 20)
        {
            scene()->removeItem(this);
            delete this;
            pociski_enemy=pociski_enemy-1;
        }
}
