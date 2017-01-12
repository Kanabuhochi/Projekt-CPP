#ifndef EXP_H
#define EXP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include "game.h"

class Exp: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Exp(QGraphicsItem * parent=0);
    QTimer * timer;
    QTimer * timer2;
    ~Exp();
public slots:
    void anim1();
    void anim2();
};


#endif // EXP_H
