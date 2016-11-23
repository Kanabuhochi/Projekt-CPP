#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "cursor.h"



class Menu: public QGraphicsView
{
public:
    Menu();
    QGraphicsScene * scene;
    Cursor * cursor;
   // int move = 0;
};

#endif // MENU_H
