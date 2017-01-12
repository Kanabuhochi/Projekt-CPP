#include "exp.h"
extern Game * game;
Exp::Exp(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/exp/images/explode/ex1.png"));
    timer = new QTimer();
    timer2 = new QTimer();
    timer->start(20);
    connect(timer,SIGNAL(timeout()),this,SLOT(anim1()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(anim2()));
    game->tank->play();

}

void Exp::anim1()
{
    timer->stop();
    setPixmap(QPixmap(":/exp/images/explode/ex2.png"));
    timer2->start(20);
}

void Exp::anim2()
{
   timer2->stop();
   setPixmap(QPixmap(":/exp/images/explode/ex3.png"));
   delete this;
}


Exp::~Exp()
{
    delete timer;
    delete timer2;
}
