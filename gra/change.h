#ifndef CHANGE_H
#define CHANGE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include "game.h"
#include "player.h"

class Change: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Change(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
};

#endif // CHANGE_H
