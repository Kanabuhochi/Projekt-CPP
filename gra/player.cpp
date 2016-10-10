#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <typeinfo>
#include <wall.h>
#include "bullet.h"
#include <Qdebug.h>

extern int zwrot=1;
extern int zwrot2=4;
extern int pociski_gracz=0;
extern int zwrot1=3;
extern int pociski_enemy=0;
extern int pociski_enemy2=0;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/gracz/gracz_up.png"));
}
void Player::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
    {
        qDebug()<<"X="<<pos().x()<<"Y="<<pos().y();
        if (pos().x() > 48)
        {
            setPos(x()-3,y());
            zwrot = 4;
        }
        setPixmap(QPixmap(":/images/images/gracz/gracz_lewo.png"));
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

    else if(event->key() == Qt::Key_Right)
    {
        qDebug()<<"X="<<pos().x()<<"Y="<<pos().y();
        if (pos().x() < 747)
        {
            setPos(x()+3,y());
            zwrot = 2;
        }
        setPixmap(QPixmap(":/images/images/gracz/gracz_prawo.png"));
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

    else if(event->key() == Qt::Key_Up)
    {
        qDebug()<<"X="<<pos().x()<<"Y="<<pos().y();
        if (pos().y() > 21)
        {
            setPos(x(),y()-3);
            zwrot = 1;
        }
        setPixmap(QPixmap(":/images/images/gracz/gracz_up.png"));
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

    else if(event->key() == Qt::Key_Down)
    {
        qDebug()<<"X="<<pos().x()<<"Y="<<pos().y();
        if (pos().y() < 550)
        {
            setPos(x(),y()+3);
            zwrot = 3;
        }
        setPixmap(QPixmap(":/images/images/gracz/gracz_dol.png"));
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
    else if (event->key() == Qt::Key_Space)
    {
        if(zwrot == 1)
        {
            if (pociski_gracz==0)
            {
                Bullet * bullet = new Bullet();
                bullet->setPos(x()-7,y()-20);
                bullet->setScale(0.7);
                scene()->addItem(bullet);
                pociski_gracz=pociski_gracz+1;
            }
            else if(pociski_gracz!=0)
            {

            }
         }
        else if(zwrot == 2)
        {
            if(pociski_gracz==0)
            {
                Bullet * bullet = new Bullet();
                bullet->setPos(x()+20,y()-7);
                bullet->setScale(0.7);
                scene()->addItem(bullet);
                pociski_gracz=pociski_gracz+1;
            }
            else if(pociski_gracz!=0)
            {

            }
        }
        else if(zwrot == 3)
        {
            if(pociski_gracz==0)
            {
                Bullet * bullet = new Bullet();
                bullet->setPos(x()-7,y()+20);
                bullet->setScale(0.7);
                scene()->addItem(bullet);
                pociski_gracz=pociski_gracz+1;
            }
            else if(pociski_gracz!=0)
            {

            }
        }
        else if(zwrot == 4)
        {
            if(pociski_gracz==0)
            {
                Bullet * bullet = new Bullet();
                bullet->setPos(x()-20,y()-7);
                bullet->setScale(0.7);
                scene()->addItem(bullet);
                pociski_gracz=pociski_gracz+1;
            }
            else if(pociski_gracz!=0)
            {

            }
        }
    }
}
