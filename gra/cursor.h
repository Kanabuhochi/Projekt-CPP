#ifndef CURSOR_H
#define CURSOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
class Cursor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Cursor(QGraphicsItem * parent=0);
    ~Cursor();
    void keyPressEvent(QKeyEvent * event);
};

#endif // CURSOR_H
