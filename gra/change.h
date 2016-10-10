#ifndef CHANGE_H
#define CHANGE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Change: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Change(QGraphicsItem * parent=0);
};

#endif // CHANGE_H
