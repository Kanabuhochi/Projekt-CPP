#include "bullet.h"
#include "nextlevel.h"
extern Game * game;
Panzer * panzer;
Player * player;

Bullet::Bullet(int zwrot): QObject(), QGraphicsPixmapItem()
{
    if(zwrot==1)
    {
        setPixmap(QPixmap(":/images/images/pocisk/gora.png"));
        QTimer * timer = new QTimer(this);
        //connect(timer, &QTimer::timeout, [=](){ruch1(game->pociski_gracz);});
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch1()));
        timer->start(30);
    }
    else if(zwrot==2)
    {
        setPixmap(QPixmap(":/images/images/pocisk/prawo.png"));
        QTimer * timer = new QTimer(this);
       // connect(timer, &QTimer::timeout, [=](){ruch2(game->pociski_gracz);});
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch2()));
        timer->start(30);
    }
    else if(zwrot==3)
    {
        setPixmap(QPixmap(":/images/images/pocisk/dol.png"));
        QTimer * timer = new QTimer(this);
      //  connect(timer, &QTimer::timeout, [=](){ruch3(game->pociski_gracz);});
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch3()));
        timer->start(30);
    }
    else if(zwrot==4)
    {
        setPixmap(QPixmap(":/images/images/pocisk/lewo.png"));
        QTimer * timer = new QTimer(this);
      //  connect(timer, &QTimer::timeout, [=](){ruch4(game->pociski_gracz);});
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
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Enemy) || typeid(*(kolizje1[i])) == typeid(Enemy_fast))
            {
                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Nextlevel *nextlevel = new Nextlevel();
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick))
            {
                    int x = kolizje1[i]->pos().x();
                    int y = kolizje1[i]->pos().y();
                    Brickhitdown *brickhitdown = new Brickhitdown();
                    game->klocki.insert(0,brickhitdown);
                    brickhitdown->setPos(x,y);
                    game->scene->addItem(brickhitdown);
                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);

                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitdown) || typeid(*(kolizje1[i])) == typeid(Brickhitup))
            {
                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitright))
            {
                int x = kolizje1[i]->pos().x();
                int y = kolizje1[i]->pos().y();
                Brick_corner *brick_corner = new Brick_corner();
                game->klocki.insert(0,brick_corner);
                brick_corner->setPos(x,y);
                game->scene->addItem(brick_corner);
                game->scene->removeItem(kolizje1[i]);
                game->scene->removeItem(this);

                delete kolizje1[i];
                delete this;
                game->pociski_gracz=game->pociski_gracz-1;
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitleft))
            {
                int x = kolizje1[i]->pos().x();
                int y = kolizje1[i]->pos().y();
                Brick_corner *brick_corner = new Brick_corner();
                game->klocki.insert(0,brick_corner);
                brick_corner->setPos(x,y);
                game->scene->addItem(brick_corner);
                game->scene->removeItem(kolizje1[i]);
                game->scene->removeItem(this);

                delete kolizje1[i];
                delete this;
                game->pociski_gracz=game->pociski_gracz-1;
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick_corner))
            {
                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
        }
        if (pos().y() < 20)
        {
            game->scene->removeItem(this);
            delete this;
            game->pociski_gracz=game->pociski_gracz-1;
        }
}
void Bullet::ruch2()
{
        QList<QGraphicsItem *> kolizje2 = collidingItems();
        for(int i = 0,  n = kolizje2.size(); i<n; i++)
        {
            if(typeid(*(kolizje2[i])) == typeid(Wall))
            {
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Enemy) || typeid(*(kolizje2[i])) == typeid(Enemy_fast))
            {
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Nextlevel * nextlevel = new Nextlevel();
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje2[i])) == typeid(Brick))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    Brickhitleft *brickhitleft = new Brickhitleft();
                    game->klocki.insert(0,brickhitleft);
                    brickhitleft->setPos(x,y);
                    game->scene->addItem(brickhitleft);
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitup))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    Brick_corner *brick_corner = new Brick_corner();
                    game->klocki.insert(0,brick_corner);
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitdown))
            {
                    int x = kolizje2[i]->pos().x()+20;
                    int y = kolizje2[i]->pos().y();
                    Brick_corner *brick_corner = new Brick_corner();
                    game->klocki.insert(0,brick_corner);
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);

                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brickhitleft) || typeid(*(kolizje2[i])) == typeid(Brickhitright))
            {
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brick_corner))
            {
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
        }
        setPos(x()+10,y());
        if (pos().x() > 635)
        {
            game->scene->removeItem(this);
            delete this;
            game->pociski_gracz=game->pociski_gracz-1;
        }
}
void Bullet::ruch3()
{
        QList<QGraphicsItem *> kolizje3 = collidingItems();
        for(int i = 0,  b = kolizje3.size(); i<b; i++)
        {
            if(typeid(*(kolizje3[i])) == typeid(Wall))
            {
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Enemy) || typeid(*(kolizje3[i])) == typeid(Enemy_fast))
            {
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Nextlevel * nextlevel = new Nextlevel();
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje3[i])) == typeid(Brick))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    Brickhitup *brickhitup = new Brickhitup();
                    game->klocki.insert(0,brickhitup);
                    brickhitup->setPos(x,y);
                    game->scene->addItem(brickhitup);
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitup) || typeid(*(kolizje3[i])) == typeid(Brickhitdown))
            {
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitright))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    Brick_corner *brick_corner = new Brick_corner();
                    game->klocki.insert(0,brick_corner);
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitleft))
            {
                    int x = kolizje3[i]->pos().x();
                    int y = kolizje3[i]->pos().y()+20;
                    Brick_corner *brick_corner = new Brick_corner();
                    game->klocki.insert(0,brick_corner);
                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);

                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brick_corner))
            {
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
        }
        setPos(x(),y()+10);
        if (pos().y() > 535)
        {
            game->scene->removeItem(this);
            delete this;
            game->pociski_gracz=game->pociski_gracz-1;
        }
}
void Bullet::ruch4()
{
        QList<QGraphicsItem *> kolizje4 = collidingItems();
        for(int i = 0,  n = kolizje4.size(); i<n; i++)
        {
            if(typeid(*(kolizje4[i])) == typeid(Wall))
            {
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Enemy) || typeid(*(kolizje4[i])) == typeid(Enemy_fast))
            {
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        Nextlevel * nextlevel = new Nextlevel();
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje4[i])) == typeid(Brick))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    Brickhitright *brickhitright = new Brickhitright();
                    game->klocki.insert(0,brickhitright);
                    brickhitright->setPos(x,y);
                    game->scene->addItem(brickhitright);
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitup))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    Brick_corner *brick_corner = new Brick_corner();
                    game->klocki.insert(0,brick_corner);

                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitdown))
            {
                    int x = kolizje4[i]->pos().x();
                    int y = kolizje4[i]->pos().y();
                    Brick_corner *brick_corner = new Brick_corner();
                    game->klocki.insert(0,brick_corner);

                    brick_corner->setPos(x,y);
                    game->scene->addItem(brick_corner);
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);

                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brick_corner))
            {
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitright) || typeid(*(kolizje4[i])) == typeid(Brickhitleft))
            {
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
        }
        setPos(x()-10,y());
        if (pos().x() < 120)
        {
            game->scene->removeItem(this);
            delete this;
            game->pociski_gracz=game->pociski_gracz-1;
        }
}
