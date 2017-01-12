#ifndef NEXTLEVEL_H
#define NEXTLEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QTimer>
#include "game.h"
#include <QDebug>
#include <QMediaPlayer>

class Nextlevel: public QObject
{
    Q_OBJECT
public:
    Nextlevel();
    QTimer * timer;
    QTimer * timer2;
    QTime * t;
    QGraphicsPixmapItem * top;
    QGraphicsPixmapItem * bottom;
    QGraphicsTextItem * stage;
    ~Nextlevel();
    QMediaPlayer * click;



public slots:
    void anim();
    void level();

};


#endif // NEXTLEVEL_H
