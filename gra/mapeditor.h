#ifndef MAPEDITOR_H
#define MAPEDITOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QTextStream>
#include <QFile>
#include "game.h"

class Mapeditor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Mapeditor(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
};


#endif // MAPEDITOR_H
