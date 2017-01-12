#include "bullet.h"
#include "exp.h"
extern Game * game;
Panzer * panzer;
Player * player;

Bullet::Bullet(int zwrot): QObject(), QGraphicsPixmapItem()
{
    timer = new QTimer();
    timer->setTimerType(Qt::PreciseTimer);
    if(zwrot==1)
    {
        setPixmap(QPixmap(":/images/images/pocisk/gora.png"));

        //connect(timer, &QTimer::timeout, [=](){ruch1(game->pociski_gracz);});
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch1()));
        timer->start(30);
    }
    else if(zwrot==2)
    {
        setPixmap(QPixmap(":/images/images/pocisk/prawo.png"));

       // connect(timer, &QTimer::timeout, [=](){ruch2(game->pociski_gracz);});
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch2()));

        timer->start(30);
    }
    else if(zwrot==3)
    {
        setPixmap(QPixmap(":/images/images/pocisk/dol.png"));

      //  connect(timer, &QTimer::timeout, [=](){ruch3(game->pociski_gracz);});
        connect(timer,SIGNAL(timeout()),this,SLOT(ruch3()));

        timer->start(30);
    }
    else if(zwrot==4)
    {
        setPixmap(QPixmap(":/images/images/pocisk/lewo.png"));

      //  connect(timer, &QTimer::timeout, [=](){ruch4(game->pociski_gracz);});
       connect(timer,SIGNAL(timeout()),this,SLOT(ruch4()));
        timer->start(30);
    }



}

void Bullet::ruch1()
{
        setPos(x(),y()-10);
        QList<QGraphicsItem *> kolizje1 = collidingItems();
        for(int i = 0,  n = kolizje1.size(); i<n; i++)
        {
            if(typeid(*(kolizje1[i])) == typeid(Wall))
            {
                    game->wall->play();
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Enemy))
            {

                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje1[i]->pos().x(),kolizje1[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 100;
                    game->newscore += 100;
                    game->normal += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Enemy_fast))
            {

                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje1[i]->pos().x(),kolizje1[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    game->newscore += 200;

                    game->fast += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brick))
            {

                    game->bhit->play();
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

                    game->bhit->play();
                    game->scene->removeItem(kolizje1[i]);
                    game->scene->removeItem(this);
                    delete kolizje1[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitright))
            {

                game->bhit->play();
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

                game->bhit->play();
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

                    game->bhit->play();
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

            game->wall->play();
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
                    game->wall->play();
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Enemy))
            {

                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje2[i]->pos().x(),kolizje2[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 100;
                    game->newscore += 100;
                    game->normal += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Enemy_fast))
            {

                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje2[i]->pos().x(),kolizje2[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    game->newscore += 200;

                    game->fast += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje2[i])) == typeid(Brick))
            {

                    game->bhit->play();
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

                    game->bhit->play();
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

                    game->bhit->play();
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

                    game->bhit->play();
                    game->scene->removeItem(kolizje2[i]);
                    game->scene->removeItem(this);
                    delete kolizje2[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje2[i])) == typeid(Brick_corner))
            {

                    game->bhit->play();
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
            game->wall->play();
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
                    game->wall->play();
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Enemy))
            {

                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje3[i]->pos().x(),kolizje3[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 100;
                    game->newscore += 100;

                    game->normal += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Enemy_fast))
            {


                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje3[i]->pos().x(),kolizje3[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    game->newscore += 200;

                    game->fast += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }

            else if(typeid(*(kolizje3[i])) == typeid(Brick))
            {

                    game->bhit->play();
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

                    game->bhit->play();
                    game->scene->removeItem(kolizje3[i]);
                    game->scene->removeItem(this);
                    delete kolizje3[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje3[i])) == typeid(Brickhitright))
            {

                    game->bhit->play();
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

                    game->bhit->play();
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

                    game->bhit->play();
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
            game->wall->play();
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
                    game->wall->play();
                    game->scene->removeItem(this);
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Enemy))
            {


                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje4[i]->pos().x(),kolizje4[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 100;
                    game->newscore += 100;

                    game->normal += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Enemy_fast))
            {


                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);
                    Exp *exp = new Exp();
                    exp->setPos(kolizje4[i]->pos().x(),kolizje4[i]->pos().y());
                    game->scene->addItem(exp);
                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    game->enemies -= 1;
                    game->score += 200;
                    game->newscore += 200;

                    game->fast += 1;
                    if(game->enemies == 0 && game->total==0)
                    {
                        game->stage += 1;
                        game->scoring->start(3000);
                       // Level2 * level2 = new Level2();
                    }
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brick))
            {

                    game->bhit->play();
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

                    game->bhit->play();
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

                    game->bhit->play();
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

                    game->bhit->play();
                    game->scene->removeItem(kolizje4[i]);
                    game->scene->removeItem(this);
                    delete kolizje4[i];
                    delete this;
                    game->pociski_gracz=game->pociski_gracz-1;
                    return;
            }
            else if(typeid(*(kolizje4[i])) == typeid(Brickhitright) || typeid(*(kolizje4[i])) == typeid(Brickhitleft))
            {

                    game->bhit->play();
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
            game->wall->play();
            game->scene->removeItem(this);
            delete this;
            game->pociski_gracz=game->pociski_gracz-1;
        }
}
