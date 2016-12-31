#include "bullet.h"
extern Game * game;
Player * player;
Panzer * panzer;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

   // setPixmap(QPixmap(":/images/images/pocisk/gora.png"));


    if(player->zwrot==1)
    {
        setPixmap(QPixmap(":/images/images/pocisk/gora.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch1()));
        timer->start(30);
    }
    else if(player->zwrot==2)
    {
        setPixmap(QPixmap(":/images/images/pocisk/prawo.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch2()));
        timer->start(30);
    }
    else if(player->zwrot==3)
    {
        setPixmap(QPixmap(":/images/images/pocisk/dol.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch3()));
        timer->start(30);
    }
    else if(player->zwrot==4)
    {
        setPixmap(QPixmap(":/images/images/pocisk/lewo.png"));
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch4()));
        timer->start(30);
    }
}
/*
void Bullet::move()
{
    if(zwrot==1)
    {
        ruch1();
    }
    else if(zwrot==2)
    {
        ruch2();
    }

    else if(zwrot==3)
    {
        ruch3();
    }

    else if(zwrot==4)
    {
        ruch4();
    }
}
*/
void Bullet::ruch1()
{
        setPos(x(),y()-10);
        QList<QGraphicsItem *> kolizje1 = collidingItems();
        for(int i = 0,  n = kolizje1.size(); i<n; i++)
        {
            if(typeid(*(kolizje1[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Enemy) || typeid(*(kolizje1[i])) == typeid(Enemy_fast))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    qDebug()<<"Enemies = "<<game->enemies;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick))
            {
                    int x = kolizje1[i]->pos().x();
                    int y = kolizje1[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brickhitdown *brickhitdown = new Brickhitdown();
                    brickhitdown->setPos(x,y);
                    game->scene->addItem(brickhitdown);
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);

                    delete kolizje1[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitdown))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitright))
            {
                int x = kolizje1[i]->pos().x();
                int y = kolizje1[i]->pos().y();
                qDebug()<<"x"<<x<<"y"<<y;
                Brick_corner *brick_corner = new Brick_corner();
                brick_corner->setPos(x,y);
                game->scene->addItem(brick_corner);
                scene()->removeItem(kolizje1[i]);
                scene()->removeItem(this);

                delete kolizje1[i];
                delete this;
                player->pociski_gracz=player->pociski_gracz-1;
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitleft))
            {
                int x = kolizje1[i]->pos().x();
                int y = kolizje1[i]->pos().y();
                qDebug()<<"x"<<x<<"y"<<y;
                Brick_corner *brick_corner = new Brick_corner();
                brick_corner->setPos(x,y);
                game->scene->addItem(brick_corner);
                scene()->removeItem(kolizje1[i]);
                scene()->removeItem(this);

                delete kolizje1[i];
                delete this;
                player->pociski_gracz=player->pociski_gracz-1;
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje1[i]);
                    scene()->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
        }
        if (pos().y() < 20)
        {
            scene()->removeItem(this);
            delete this;
            player->pociski_gracz=player->pociski_gracz-1;
        }
}
void Bullet::ruch2()
{
        QList<QGraphicsItem *> kolizje2 = collidingItems();
        for(int i = 0,  n = kolizje2.size(); i<n; i++)
        {
            if(typeid(*(kolizje2[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Enemy) || typeid(*(kolizje2[i])) == typeid(Enemy_fast))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    qDebug()<<"Enemies = "<<game->enemies;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje2[i])) == typeid(Brick))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brickhitleft *brickhitleft = new Brickhitleft();
                    brickhitleft->setPos(x,y);
                    game->scene->addItem(brickhitleft);
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitup))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitdown))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitleft))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje2[i]);
                    scene()->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
        }
        setPos(x()+10,y());
        if (pos().x() > 635)
        {
            scene()->removeItem(this);
            delete this;
            player->pociski_gracz=player->pociski_gracz-1;
        }
}
void Bullet::ruch3()
{
        QList<QGraphicsItem *> kolizje3 = collidingItems();
        for(int i = 0,  b = kolizje3.size(); i<b; i++)
        {
            if(typeid(*(kolizje3[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Enemy) || typeid(*(kolizje3[i])) == typeid(Enemy_fast))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    qDebug()<<"Enemies = "<<game->enemies;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje3[i])) == typeid(Brick))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brickhitup *brickhitup = new Brickhitup();
                    brickhitup->setPos(x,y);
                    game->scene->addItem(brickhitup);
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitup))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitright))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitleft))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje3[i]);
                    scene()->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
        }
        setPos(x(),y()+10);
        if (pos().y() > 535)
        {
            scene()->removeItem(this);
            delete this;
            player->pociski_gracz=player->pociski_gracz-1;
        }
}
void Bullet::ruch4()
{
        QList<QGraphicsItem *> kolizje4 = collidingItems();
        for(int i = 0,  n = kolizje4.size(); i<n; i++)
        {
            if(typeid(*(kolizje4[i])) == typeid(Wall))
            {
                    scene()->removeItem(this);
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Enemy) || typeid(*(kolizje4[i])) == typeid(Enemy_fast))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    qDebug()<<"Enemies = "<<game->enemies;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje4[i])) == typeid(Brick))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brickhitright *brickhitright = new Brickhitright();
                    brickhitright->setPos(x,y);
                    game->scene->addItem(brickhitright);
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitup))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitdown))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    qDebug()<<"x"<<x<<"y"<<y;
                    Brick_corner *brick_corner = new Brick_corner();
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brick_corner))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitright))
            {
                    scene()->removeItem(kolizje4[i]);
                    scene()->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    player->pociski_gracz=player->pociski_gracz-1;
                    return;
            }
        }
        setPos(x()-10,y());
        if (pos().x() < 120)
        {
            scene()->removeItem(this);
            delete this;
            player->pociski_gracz=player->pociski_gracz-1;
        }
}
