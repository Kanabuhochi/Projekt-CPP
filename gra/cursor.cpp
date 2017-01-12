#include "cursor.h"
#include <QKeyEvent>
#include <Qdebug.h>
//#include "menu.h"
#include "level1.h"

#include "nextlevel.h"

//extern Menu * menu;
extern Game * game;

Cursor::Cursor(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/gracz/gracz_prawo.png"));
}



void Cursor::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        setPos(x(),y()-50);
        game->move -= 1;
        //qDebug<<"Move="<<game->move;
        if (game->move == -1)
        {
            setPos(x(),y()+150);
            game->move = 2;
            //qDebug<<"Move="<<game->move;
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+50);
        game->move += 1;
        //qDebug<<"Move="<<game->move;
        if (game->move == 3)
        {
            setPos(x(),y()-150);
            game->move = 0;
            //qDebug<<"Move="<<game->move;
        }
    }  
    else if(event->key() == Qt::Key_Return)
    {
        if(game->move == 0)
        {
            game->stage = 1;
            delete this;

            //Level1 * level1 = new Level1();
            Nextlevel * nextlevel = new Nextlevel();


        }
        else if(game->move == 1)
        {

        }
        else if(game->move == 2)
        {
            game->stage = 0;
            delete this;
            Nextlevel * nextlevel = new Nextlevel();

        }
    }
}

Cursor::~Cursor()
{
    //delete click;
}
