#include "mapeditor.h"

extern Game * game;

Mapeditor::Mapeditor(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setZValue(2);
    setPixmap(QPixmap(":/images/images/gracz/gracz_up.png"));
    game->scene->clear();
    game->setScene(game->scene);
   // top->setPos(0,0);
  //  top->setPixmap(QPixmap(":/images/images/enemy/enemy_left.jpg"));
//    bottom->setRect(0,600,500,500);
    game->show();
}

void Mapeditor::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if (pos().x() > 141)
        {
            setPos(x()-40,y());
        }
    }

    else if(event->key() == Qt::Key_Right)
    {
        if (pos().x() < 589)
        {
            setPos(x()+40,y());
        }
    }
    else if(event->key() == Qt::Key_Up)
    {
        if (pos().y() > 41)
        {
            setPos(x(),y()-40);
        }

    }


    else if(event->key() == Qt::Key_Down)
    {
        if (pos().y() < 490)
        {
            setPos(x(),y()+40);
        }
     }
    else if (event->key() == Qt::Key_Space)
    {
        QList<QGraphicsItem *> kolizje1 = collidingItems();
        for(int i = 0,  n = kolizje1.size(); i<n; i++)
        {
            if(typeid(*(kolizje1[i])) == typeid(Brick))
            {
                    scene()->removeItem(kolizje1[i]);
                    delete kolizje1[i];

                    Wall *wall = new Wall();
                    wall->setPos(pos().x(),pos().y());
                    game->scene->addItem(wall);
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Wall))
            {
                scene()->removeItem(kolizje1[i]);
                delete kolizje1[i];

                Tree *tree = new Tree();
                tree->setPos(pos().x(),pos().y());
                game->scene->addItem(tree);
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Tree))
            {
                scene()->removeItem(kolizje1[i]);
                delete kolizje1[i];

                Water *water = new Water();
                water->setPos(pos().x(),pos().y());
                game->scene->addItem(water);
                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Water))
            {
                scene()->removeItem(kolizje1[i]);
                delete kolizje1[i];
                return;
            }
        }
            Brick *brick = new Brick();
            brick->setPos(pos().x(),pos().y());
            game->scene->addItem(brick);

    }
    else if (event->key() == Qt::Key_Return)
    {
        delete this;
        Player * player = new Player();
        player->setScale(1);
        player->setPos(405,520);
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        game->scene->addItem(player);
        player->setFocus();
        game->show();
        game->play();
    }
}
