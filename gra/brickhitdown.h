#ifndef BRICKHITDOWN_H
#define BRICKHITDOWN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Brickhitdown: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brickhitdown(QGraphicsItem * parent=0);
    ~Brickhitdown();
};


#endif // BRICKHITDOWN_H
