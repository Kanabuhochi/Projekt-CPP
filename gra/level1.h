#ifndef LEVEL1_H
#define LEVEL1_H

#include "game.h"
#include "player.h"
#include "ice.h"
#include "mapeditor.h"
#include "brick.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <time.h>
#include <stdlib.h>
#include <QChar>
#include <QTextStream>
#include <QFile>


class Level1
{
public:
    Level1();
    ~Level1();
    void keyPressEvent(QKeyEvent * event);

};

#endif // LEVEL1_H
