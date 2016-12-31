#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    int zwrot = 1;
    int pociski_gracz = 0;
    void keyPressEvent(QKeyEvent *event);
public slots:
};

#endif // PLAYER_H
