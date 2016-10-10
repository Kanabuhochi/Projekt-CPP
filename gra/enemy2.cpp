#include "enemy2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <typeinfo>
#include <wall.h>
#include "bullet_enemy2.h"
#include <stdlib.h>
#include "change.h"
#include <time.h>
#include <qdebug.h>
extern int zwrot2;
extern int pociski_enemy2;

Enemy2::Enemy2(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
        srand (time(NULL));
        setPixmap(QPixmap(":/images/images/enemy/enemy_up.png"));

        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(30);

        QTimer * timer1 = new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(change()));
        timer1->start(300);

        QTimer * timer2 = new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(str()));
        timer2->start(500);

}



void Enemy2::str()
{


    if(zwrot2 == 1)
    {
        if (pociski_enemy2==0)
        {
            Bullet_enemy2 * bullet_enemy2 = new Bullet_enemy2();
            bullet_enemy2->setPos(x()-7,y()-20);
            bullet_enemy2->setScale(0.7);
            scene()->addItem(bullet_enemy2);
            pociski_enemy2=pociski_enemy2+1;
        }
        else if(pociski_enemy2!=0)
        {

        }
     }
    else if(zwrot2 == 2)
    {
        if(pociski_enemy2==0)
        {
            Bullet_enemy2 * bullet_enemy2 = new Bullet_enemy2();
            bullet_enemy2->setPos(x()+20,y()-7);
            bullet_enemy2->setScale(0.7);
            scene()->addItem(bullet_enemy2);
            pociski_enemy2=pociski_enemy2+1;
        }
        else if(pociski_enemy2!=0)
        {

        }
    }
    else if(zwrot2 == 3)
    {
        if(pociski_enemy2==0)
        {
            Bullet_enemy2 * bullet_enemy2 = new Bullet_enemy2();
            bullet_enemy2->setPos(x()-7,y()+20);
            bullet_enemy2->setScale(0.7);
            scene()->addItem(bullet_enemy2);
            pociski_enemy2=pociski_enemy2+1;
        }
        else if(pociski_enemy2!=0)
        {

        }
    }
    else if(zwrot2 == 4)
    {
        if(pociski_enemy2==0)
        {
            Bullet_enemy2 * bullet_enemy2 = new Bullet_enemy2();
            bullet_enemy2->setPos(x()-20,y()-7);
            bullet_enemy2->setScale(0.7);
            scene()->addItem(bullet_enemy2);
            pociski_enemy2=pociski_enemy2+1;
        }
        else if(pociski_enemy2!=0)
        {

        }
    }
}


void Enemy2::change()
{
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Change))
        {
                zwrot2= rand() % 4 + 1;
        }

    }
}
void Enemy2::move()
{
    if(zwrot2==1)
    {
        setPixmap(QPixmap(":/images/images/enemy/up.png"));
        ruch1();
    }
    else if(zwrot2==2)
    {
        setPixmap(QPixmap(":/images/images/enemy/right.png"));
        ruch2();
    }

    else if(zwrot2==3)
    {
        setPixmap(QPixmap(":/images/images/enemy/down.png"));
        ruch3();
    }

    else if(zwrot2==4)
    {
        setPixmap(QPixmap(":/images/images/enemy/left.png"));
        ruch4();
    }
}


void Enemy2::ruch1()//gora
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_up.png"));

    if (pos().y() > 29)
    {
        setPos(x(),y()-3);
    }
    else if (pos().y() <= 29)
    {
        zwrot2 = rand() % 4 + 1;
        //ruch4();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x(),y()+4);
                zwrot2= rand() % 4 + 1;
        }

    }
}

void Enemy2::ruch2()//prawo
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_right.png"));

    if (pos().x() < 746)
    {
        setPos(x()+3,y());
    }
    else if (pos().x() >= 746)
    {
        zwrot2 = rand() % 4 + 1;
        //ruch1();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x()-4,y());
                zwrot2= rand() % 4 + 1;
        }

    }
}

void Enemy2::ruch3()//dol
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_down.png"));

    if (pos().y() < 549)
    {
        setPos(x(),y()+3);
    }
    else if (pos().y() > 547)
    {
        zwrot2 = rand() % 4 + 1;
        //ruch2();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x(),y()-4);
                zwrot2= rand() % 4 + 1;
        }

    }
}

void Enemy2::ruch4()//lewo
{
    setPixmap(QPixmap(":/images/images/enemy/enemy_left.png"));

    if (pos().x() > 50)
    {
        setPos(x()-3,y());

    }
    else if (pos().x() <= 50)
    {
        zwrot2 = rand() % 4 + 1;
        //ruch3();
    }
    QList<QGraphicsItem *> kolizje_sciana = collidingItems();
    for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
    {

        if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
        {
                setPos(x()+4,y());
                zwrot2= rand() % 4 + 1;
        }

    }
}
/*void Enemy::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_A)
    {
        if (pos().x() > 48)
        {
            setPos(x()-3,y());
            zwrot1 = 4;
        }
        setPixmap(QPixmap(":/images/images/enemy/enemy_left.png"));
        QList<QGraphicsItem *> kolizje_sciana = collidingItems();
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
            {
                    setPos(x()+4,y());
            }
            else if (pos().x() < 48)
            {

            }
        }
     }

    else if(event->key() == Qt::Key_D)
    {
        if (pos().x() < 747)
        {
            setPos(x()+3,y());
            zwrot1 = 2;
        }
        setPixmap(QPixmap(":/images/images/enemy/enemy_right.png"));
        QList<QGraphicsItem *> kolizje_sciana = collidingItems();
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
            {
                    setPos(x()-4,y());
            }
            else if (pos().x() > 747)
            {

            }
        }
     }

    else if(event->key() == Qt::Key_W)
    {
        if (pos().y() > 21)
        {
            setPos(x(),y()-3);
            zwrot1 = 1;
        }
        setPixmap(QPixmap(":/images/images/enemy/enemy_up.png"));
        QList<QGraphicsItem *> kolizje_sciana = collidingItems();
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
            {
                    setPos(x(),y()+4);
            }
            else if (pos().y() < 21)
            {

            }
        }
     }

    else if(event->key() == Qt::Key_S)
    {
        if (pos().y() < 550)
        {
            setPos(x(),y()+3);
            zwrot1 = 3;
        }
        setPixmap(QPixmap(":/images/images/enemy/enemy_down.png"));
        QList<QGraphicsItem *> kolizje_sciana = collidingItems();
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Wall))
            {
                    setPos(x(),y()-4);
            }
            else if (pos().y() > 550)
            {

            }
        }
     }
    else if (event->key() == Qt::Key_F)
    {
        if(zwrot1 == 1)
        {
            if (pociski_enemy==0)
            {
                Bullet_enemy * bullet_enemy = new Bullet_enemy();
                bullet_enemy->setPos(x()-7,y()-20);
                bullet_enemy->setScale(0.7);
                scene()->addItem(bullet_enemy);
                pociski_enemy=pociski_enemy+1;
            }
            else if(pociski_enemy!=0)
            {

            }
         }
        else if(zwrot1 == 2)
        {
            if(pociski_enemy==0)
            {
                Bullet_enemy * bullet_enemy = new Bullet_enemy();
                bullet_enemy->setPos(x()+20,y()-7);
                bullet_enemy->setScale(0.7);
                scene()->addItem(bullet_enemy);
                pociski_enemy=pociski_enemy+1;
            }
            else if(pociski_enemy!=0)
            {

            }
        }
        else if(zwrot1 == 3)
        {
            if(pociski_enemy==0)
            {
                Bullet_enemy * bullet_enemy = new Bullet_enemy();
                bullet_enemy->setPos(x()-7,y()+20);
                bullet_enemy->setScale(0.7);
                scene()->addItem(bullet_enemy);
                pociski_enemy=pociski_enemy+1;
            }
            else if(pociski_enemy!=0)
            {

            }
        }
        else if(zwrot1 == 4)
        {
            if(pociski_enemy==0)
            {
                Bullet_enemy * bullet_enemy = new Bullet_enemy();
                bullet_enemy->setPos(x()-20,y()-7);
                bullet_enemy->setScale(0.7);
                scene()->addItem(bullet_enemy);
                pociski_enemy=pociski_enemy+1;
            }
            else if(pociski_enemy!=0)
            {

            }
        }
    }
}
*/
