#include "eagle.h"
extern Game * game;
Eagle::Eagle(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/images/tlo/eagle.png"));
    timerr = new QTimer();
    connect(timerr,SIGNAL(timeout()),this,SLOT(colision()));
    timerr->start(10);

}

void Eagle::colision()
{
    QList<QGraphicsItem *> kolizje1 = collidingItems();
    for(int i = 0,  n = kolizje1.size(); i<n; i++)
    {
        if(typeid(*(kolizje1[i])) == typeid(Bullet))
        {
                game->gam = new QGraphicsTextItem(QString("GAME"));
                game->over = new QGraphicsTextItem(QString("OVER"));
                game->gam->setPos(380,600);
                game->gam->setDefaultTextColor(Qt::red);
                game->over->setDefaultTextColor(Qt::red);
                game->gam->setScale(1);
                game->over->setScale(1);
                game->over->setPos(380,620);
                game->scene->addItem(game->gam);
                game->scene->addItem(game->over);
                game->iglo->play();
                game->endo->play();
                setPixmap(QPixmap(":/images/images/tlo/deagle.png"));
                game->scene->removeItem(kolizje1[i]);
                delete kolizje1[i];
                game->pociski_gracz=game->pociski_gracz-1;
                game->timer->start(10);
                this->setFocus();
                return;
        }
        else if(typeid(*(kolizje1[i])) == typeid(Bullet_enemy))
        {

                game->gam = new QGraphicsTextItem(QString("GAME"));
                game->over = new QGraphicsTextItem(QString("OVER"));
                game->gam->setPos(380,600);
                game->gam->setDefaultTextColor(Qt::red);
                game->over->setDefaultTextColor(Qt::red);
                game->gam->setScale(1);
                game->over->setScale(1);
                game->over->setPos(380,620);
                game->scene->addItem(game->gam);
                game->scene->addItem(game->over);

                game->iglo->play();

                game->endo->play();
                setPixmap(QPixmap(":/images/images/tlo/deagle.png"));
                game->scene->removeItem(kolizje1[i]);
                delete kolizje1[i];
                this->setFocus();
                game->timer->start(10);

                return;
        }
    }
}
Eagle::~Eagle()
{
    delete timerr;
    qDebug()<<"EAGLE Deleted";
}
