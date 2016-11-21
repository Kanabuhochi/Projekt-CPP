#include "cursor.h"
#include <QKeyEvent>
#include <Qdebug.h>
//#include "menu.h"
#include "game.h"
#include "level1.h"

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
        qDebug()<<"Move="<<game->move;
        if (game->move == -1)
        {
            setPos(x(),y()+150);
            game->move = 2;
            qDebug()<<"Move="<<game->move;
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+50);
        game->move += 1;
        qDebug()<<"Move="<<game->move;
        if (game->move == 3)
        {
            setPos(x(),y()-150);
            game->move = 0;
            qDebug()<<"Move="<<game->move;
        }
    }  
    else if(event->key() == Qt::Key_Space)
    {
        if(game->move == 0)
        {
            Level1 * level1 = new Level1();
        }
        else if(game->move == 1)
        {

        }
        else if(game->move == 2)
        {

        }
    }
}
