#include "nextlevel.h"

extern Game * game;


Nextlevel::Nextlevel()
{

    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sound/sounds/START.wav"));
    click->setVolume(100);
    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/floor.jpg")));
    game->klocki.clear();
    timer = new QTimer();
    timer2 = new QTimer();

    if (game->stage == 1)
    {
        QString s = QString("%1").arg(game->stage);
        stage = new QGraphicsTextItem(QString("Stage ")+s);
        click->play();

    }
    else if (game->stage > 1)
    {
        QString s = QString("%1").arg(game->stage);
        stage = new QGraphicsTextItem(QString("Stage ")+s);
        click->play();

    }
    else if (game->stage == 0)
    {
        stage = new QGraphicsTextItem(QString("Editor"));

    }
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

    delete timer;
    delete timer2;
    delete stage;
    delete top;
    delete bottom;
}
