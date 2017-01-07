#include "level1.h"
#include <QBrush>
extern Game * game;
Level1::Level1()
{
    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg9.jpg")));
    game->setScene(game->scene);
    game->total = 1;
    if (game->stage == 0)
    {
        int i = game->stage;
        QString s = QString::number(i);
        QFile level(":/levels/levels/editor.txt");
        level.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream levele(&level);
        QChar c;
        while (!levele.atEnd())
        {

            for(int j = 520; j > 0; j -= 40)
                for(int i = 620; i > 100; i -= 40)

                {
                    QString line = levele.readLine();
                    if (line == "b")
                    {
                        Brick *brick = new Brick();
                        brick->setPos(i,j);
                        game->scene->addItem(brick);
                        game->klocki.insert(0,brick);
                    }
                }

        }
        level.close();
        Mapeditor * mapeditor = new Mapeditor();
        mapeditor->setScale(1);
        mapeditor->setPos(140,40);
        mapeditor->setFlag(QGraphicsItem::ItemIsFocusable);
        game->scene->addItem(mapeditor);
        mapeditor->setFocus();
        game->show();
        delete this;

    }
    else if (game->stage != 0)
    {
        int i = game->stage;
        QString s = QString::number(i);
        QFile level(":/levels/levels/level"+s+".txt");
        level.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream levele(&level);
        QChar c;
        while (!levele.atEnd())
        {
            for(int j = 520; j > 0; j -= 40)
                for(int i = 620; i > 100; i -= 40)

                {
                    QString line = levele.readLine();
                    if (line == "b")
                    {
                        Brick *brick = new Brick();
                        brick->setPos(i,j);
                        game->scene->addItem(brick);
                        game->klocki.insert(0,brick);


                    }
                    else if (line == "c")
                    {
                        Wall *wall = new Wall();
                        wall->setPos(i,j);
                        game->scene->addItem(wall);
                        game->klocki.insert(0,wall);
                    }
                    else if (line == "t")
                    {
                        Tree *tree = new Tree();
                        tree->setPos(i,j);
                        game->scene->addItem(tree);
                        game->klocki.insert(0,tree);
                    }
                    else if (line == "w")
                    {
                        Water *water = new Water();
                        water->setPos(i,j);
                        game->scene->addItem(water);
                        game->klocki.insert(0,water);
                    }
                }

        }
        level.close();
        Player * player = new Player();
        game->klocki.insert(0,player);
        player->setScale(1);
        player->setPos(405,520);
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        game->scene->addItem(player);
        player->setFocus();
        game->show();
        game->play();
        delete this;
    }
}

Level1::~Level1()
{
    qDebug()<<"LEVEL 1 Deleted";
}





