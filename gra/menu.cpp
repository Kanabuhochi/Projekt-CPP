#include "menu.h"
#include <QKeyEvent>
#include "cursor.h"
#include "game.h"



Menu::Menu()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/images/tlo/menu2.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    cursor = new Cursor();
    cursor->setScale(1);
    cursor->setPos(235,290);
    cursor->setFlag(QGraphicsItem::ItemIsFocusable);
    cursor->setFocus();
    scene->addItem(cursor);
}

