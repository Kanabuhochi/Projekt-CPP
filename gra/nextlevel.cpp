#include "nextlevel.h"

extern Game * game;


Nextlevel::Nextlevel()
{

    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/floor.jpg")));
    game->setScene(game->scene);
    game->klocki.clear();
   // top->setPos(0,0);
  //  top->setPixmap(QPixmap(":/images/images/enemy/enemy_left.jpg"));
//    bottom->setRect(0,600,500,500);
    timer = new QTimer();
    timer2 = new QTimer();

    QString s = QString("%1").arg(game->stage);
    stage = new QGraphicsTextItem(QString("Stage ")+s);
    stage->setPos(400,300);



    top = new QGraphicsPixmapItem();
    bottom = new QGraphicsPixmapItem();
    top->setPos(0,-300);
    top->setPixmap(QPixmap(":/images/images/tlo/anim.png"));

    bottom->setPos(0,600);
    bottom->setPixmap(QPixmap(":/images/images/tlo/anim.png"));


    game->scene->addItem(top);
    game->scene->addItem(bottom);


    connect(timer,SIGNAL(timeout()),this,SLOT(anim()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(level()));

    timer->start(10);

}


void Nextlevel::anim()
{
    if(top->pos().y()<0)
    {
        top->setPos(top->x(),top->y()+10);
        bottom->setPos(bottom->x(),bottom->y()-10);
    }
    else if(top->pos().y() == 0)
    {
        timer->stop();
        game->scene->addItem(stage);
        timer2->start(3000);
    }


}

void Nextlevel::level()
{
    timer2->stop();
    delete this;
    Level1 * level1 = new Level1();
}

Nextlevel::~Nextlevel()
{
    qDebug()<<" NEXTLEVEL DELETED";
    delete timer;
    delete timer2;
    delete stage;
    delete top;
    delete bottom;
}
