#ifndef TREE_H
#define TREE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Tree: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tree(QGraphicsItem * parent=0);
};

#endif // TREE_H
