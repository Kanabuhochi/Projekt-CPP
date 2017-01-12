#include "mapeditor.h"

extern Game * game;

Mapeditor::Mapeditor(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setZValue(2);
    setPixmap(QPixmap(":/images/images/gracz/gracz_up.png"));
    game->scene->clear();
   // top->setPos(0,0);
  //  top->setPixmap(QPixmap(":/images/images/enemy/enemy_left.jpg"));
//    bottom->setRect(0,600,500,500);
    Eagle * eagle = new Eagle();
    eagle->setFlag(QGraphicsItem::ItemIsFocusable);
    game->klocki.insert(0,eagle);
    eagle->setPos(380,520);
    game->scene->addItem(eagle);

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

                    Brickhitleft *brickhitleft = new Brickhitleft();
                    brickhitleft->setPos(pos().x()+20,pos().y());
                    game->scene->addItem(brickhitleft);
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitleft))
            {
                    scene()->removeItem(kolizje1[i]);
                    delete kolizje1[i];

                    Brickhitup *brickhitup = new Brickhitup();
                    brickhitup->setPos(pos().x(),pos().y()+20);
                    game->scene->addItem(brickhitup);
                    return;
            }
            if(typeid(*(kolizje1[i])) == typeid(Brickhitup))
            {
                    scene()->removeItem(kolizje1[i]);
                    delete kolizje1[i];

                    Brickhitright *brickhitright = new Brickhitright();
                    brickhitright->setPos(pos().x(),pos().y());
                    game->scene->addItem(brickhitright);
                    return;
            }
            if(typeid(*(kolizje1[i])) == typeid(Brickhitright))
            {
                    scene()->removeItem(kolizje1[i]);
                    delete kolizje1[i];

                    Brickhitdown *brickhitdown = new Brickhitdown();
                    brickhitdown->setPos(pos().x(),pos().y());
                    game->scene->addItem(brickhitdown);
                    return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Brickhitdown))
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

                Eagle *eagle = new Eagle();
                eagle->setPos(pos().x(),pos().y());
                game->scene->addItem(eagle);

                return;
            }
            else if(typeid(*(kolizje1[i])) == typeid(Eagle))
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
        QMediaPlayer * click = new QMediaPlayer();
        click->setMedia(QUrl("qrc:/sound/sounds/START.wav"));
        click->setVolume(100);
        click->play();
        Player * player = new Player();
        player->setScale(1);
        player->setPos(300,520);
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        game->scene->addItem(player);
        player->setFocus();
        QMediaPlayer * move = new QMediaPlayer;
        move->setMedia(QUrl("qrc:/sound/sounds/MOVING.wav"));
        move->setVolume(30);
        move->play();
        game->show();
        game->play();
    }
}
