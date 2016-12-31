#include "level1.h"
#include <QBrush>
extern Game * game;
Level1::Level1()
{
    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg9.jpg")));
    game->setScene(game->scene);

    QFile level(":/levels/levels/level1.txt");
    level.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream levele(&level);
    QChar c;
    int z = 1;
    while (!levele.atEnd())
    {

      //  levele >> c;
      //  qDebug() << c;
        for(int j = 520; j > 0; j -= 40)
            for(int i = 620; i > 100; i -= 40)

            {
                QString line = levele.readLine();
                qDebug() <<"Line = " <<line;
                qDebug() <<"Z = " <<z;
                if (line == "b")
                {
                    Brick *brick = new Brick();
                    brick->setPos(i,j);
                    game->scene->addItem(brick);
                }
                z+=1;
            }

    }

    level.close();
    Player * player = new Player();
    player->setScale(1);
    player->setPos(405,520);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    game->scene->addItem(player);
    player->setFocus();

    game->show();
    game->play();
}

Level1::~Level1()
{
    delete this;
}




