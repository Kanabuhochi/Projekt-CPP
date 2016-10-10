#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy2: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent=0);

public slots:
    void move();
    void str();
    void change();
    void ruch1();
    void ruch2();
    void ruch3();
    void ruch4();
   // void keyPressEvent(QKeyEvent * event);

};


#endif // ENEMY2_H
