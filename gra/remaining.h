#ifndef REMAINING_H
#define REMAINING_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Remaining: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Remaining(QGraphicsItem * parent=0);
    ~Remaining();
};

#endif // REMAINING_H
