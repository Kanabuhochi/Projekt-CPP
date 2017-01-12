#ifndef ENEMY_FAST_H
#define ENEMY_FAST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Enemy_fast: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy_fast(QGraphicsItem * parent=0);
    QTimer * timer;
    QTimer * timer1;
    QTimer * timer2;
    int zwrot1 = 3;

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


#endif // ENEMY_FAST_H
