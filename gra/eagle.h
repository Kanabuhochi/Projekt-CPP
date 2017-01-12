#ifndef EAGLE_H
#define EAGLE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>
#include <QMediaPlayer>
#include "game.h"

class Eagle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Eagle(QGraphicsItem * parent=0);
    ~Eagle();
    QTimer * timerr;


public slots:
        void colision();

};


#endif // EAGLE_H
