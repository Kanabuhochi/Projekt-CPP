#include "level1.h"
#include <QBrush>
extern Game * game;
Level1::Level1()
{
    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg9.jpg")));
    game->setScene(game->scene);
    game->total = 20;
    game->enemies = 0;
    game->pociski_gracz = 0;
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

        game->iglo = new QMediaPlayer();
        game->iglo->setMedia(QUrl("qrc:/sound/sounds/DESTROYEAGLE.wav"));
        game->iglo->setVolume(100);
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
                    else if (line == "u")
                    {
                        Brickhitup *brickhitup = new Brickhitup();
                        brickhitup->setPos(i,j);
                        game->scene->addItem(brickhitup);
                        game->klocki.insert(0,brickhitup);
                    }
                    else if (line == "d")
                    {
                        Brickhitdown *brickhitdown= new Brickhitdown();
                        brickhitdown->setPos(i,j+20);
                        game->scene->addItem(brickhitdown);
                        game->klocki.insert(0,brickhitdown);

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
                    else if (line == "e")
                    {
                        Eagle * eagle = new Eagle();
                        eagle->setFlag(QGraphicsItem::ItemIsFocusable);
                        game->klocki.insert(0,eagle);
                        eagle->setPos(380,520);
                        game->scene->addItem(eagle);

                        game->iglo = new QMediaPlayer();
                        game->iglo->setMedia(QUrl("qrc:/sound/sounds/DESTROYEAGLE.wav"));
                        game->iglo->setVolume(100);
                    }
                }
        }
        level.close();
        Player * player = new Player();
        game->klocki.insert(0,player);
        player->setScale(1);
        player->setPos(305,525);
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        game->scene->addItem(player);
        player->setFocus();
        QMediaPlayer * move = new QMediaPlayer;
        move->setMedia(QUrl("qrc:/sound/sounds/MOVING.wav"));
        move->setVolume(30);
        move->play();
        Brickhitleft * bb = new Brickhitleft();
        game->klocki.insert(0,bb);
        bb->setPos(360,520);
        game->scene->addItem(bb);
        Brickhitleft * bc = new Brickhitleft();
        game->klocki.insert(0,bc);
        bc->setPos(420,520);
        game->scene->addItem(bc);
        Brickhitup * by = new Brickhitup();
        game->klocki.insert(0,by);
        by->setPos(380,500);
        game->scene->addItem(by);
        Brick_corner * l = new Brick_corner();
        game->klocki.insert(0,l);
        l->setPos(360,500);
        game->scene->addItem(l);
        Brick_corner * r = new Brick_corner();
        game->klocki.insert(0,r);
        r->setPos(420,500);
        game->scene->addItem(r);
        game->show();
        game->play();
        delete this;
    }
}

Level1::~Level1()
{
}





