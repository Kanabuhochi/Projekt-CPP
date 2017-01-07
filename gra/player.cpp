#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <typeinfo>
#include <wall.h>
#include <ice.h>
#include <water.h>
#include "bullet.h"
#include "game.h"
#include "brickhitdown.h"
#include "brickhitleft.h"
#include "brickhitright.h"
#include "brickhitup.h"
#include "brick_corner.h"
#include <Qdebug.h>
//extern int pociski_enemy=0;
extern Game * game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/gracz/gracz_up.png"));
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if (pos().x() > 141)
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
            else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner))
            {
                    setPos(x()+4,y());
            }

            else if (pos().x() > 660)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Water))
            {
                    setPos(x()+4,y());
            }
            else if (pos().x() > 660)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Ice))
            {
                    setPos(x()-6,y());
            }
            else if (pos().x() > 660)
            {

            }
        }
     }

    else if(event->key() == Qt::Key_Right)
    {
        if (pos().x() < 630)
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
            else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner))
            {
                    setPos(x()-4,y());
            }
            else if (pos().x() > 630)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Water))
            {
                    setPos(x()-4,y());
            }
            else if (pos().x() > 630)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Ice))
            {
                    setPos(x()+6,y());
            }
            else if (pos().x() > 630)
            {

            }
        }
     }

    else if(event->key() == Qt::Key_Up)
    {
        if (pos().y() > 40)
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
            else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner))
            {
                    setPos(x(),y()+4);
            }
            else if (pos().y() < 40)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Water))
            {
                    setPos(x(),y()+4);
            }
            else if (pos().y() < 40)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Ice))
            {
                    setPos(x(),y()-6);
            }
            else if (pos().y() < 40)
            {

            }
        }
     }

    else if(event->key() == Qt::Key_Down)
    {
        if (pos().y() < 530)
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
            else if(typeid(*(kolizje_sciana[i])) == typeid(Brick) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitleft) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitright) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitup) || typeid(*(kolizje_sciana[i])) == typeid(Brickhitdown) || typeid(*(kolizje_sciana[i])) == typeid(Brick_corner))
            {
                    setPos(x(),y()-4);
            }
            else if (pos().y() > 530)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Water))
            {
                    setPos(x(),y()-4);
            }
            else if (pos().y() > 530)
            {

            }
        }
        for(int i = 0,  n = kolizje_sciana.size(); i<n; i++)
        {

            if(typeid(*(kolizje_sciana[i])) == typeid(Ice))
            {
                    setPos(x(),y()+6);
            }
            else if (pos().y() > 530)
            {

            }
        }

     }
    else if (event->key() == Qt::Key_Space)
    {
        if(zwrot == 1)
        {

            if (game->pociski_gracz==0)
            {
                Bullet * bullet = new Bullet(zwrot);
                bullet->setPos(x()-7,y()-20);
                bullet->setScale(0.7);
                game->scene->addItem(bullet);
                game->pociski_gracz=game->pociski_gracz+1;
            }
            else if(game->pociski_gracz!=0)
            {

            }
         }
        else if(zwrot == 2)
        {
            if(game->pociski_gracz==0)
            {
                Bullet * bullet = new Bullet(zwrot);
                bullet->setPos(x()+20,y()-7);
                bullet->setScale(0.7);
                game->scene->addItem(bullet);
                game->pociski_gracz=game->pociski_gracz+1;
            }
            else if(game->pociski_gracz!=0)
            {

            }
        }
        else if(zwrot == 3)
        {
            if(game->pociski_gracz==0)
            {
                Bullet * bullet = new Bullet(zwrot);
                bullet->setPos(x()-7,y()+20);
                bullet->setScale(0.7);
                game->scene->addItem(bullet);
                game->pociski_gracz=game->pociski_gracz+1;
            }
            else if(game->pociski_gracz!=0)
            {

            }
        }
        else if(zwrot == 4)
        {
            if(game->pociski_gracz==0)
            {
                Bullet * bullet = new Bullet(zwrot);
                bullet->setPos(x()-20,y()-7);
                bullet->setScale(0.7);
                game->scene->addItem(bullet);
                game->pociski_gracz=game->pociski_gracz+1;
            }
            else if(game->pociski_gracz!=0)
            {

            }
        }
    }
}

Player::~Player()
{
    qDebug()<<" PLAYER DELETED";
}
