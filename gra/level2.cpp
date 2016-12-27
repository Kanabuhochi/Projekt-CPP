#include "level2.h"
#include <QBrush>
extern Game * game;
Level2::Level2()
{

    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg9.jpg")));
    game->setScene(game->scene);
    //game->bricks.clear();
    Player * player = new Player();
    player->setScale(1);
    player->setPos(405,520);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    game->scene->addItem(player);
    player->setFocus();



  //  Enemy * enemy = new Enemy();
  //  enemy->setScale(1);
  //  enemy->setPos(50,25); // 400 i 745
  //  game->scene->addItem(enemy);

    int i=0;
    int j=0;
    for(i=140;i<660;i=i+80)
    {
        for(j=40;j<80;j=j+80)
        {
            Wall *wall = new Wall();
            wall->setPos(i,j);
            game->scene->addItem(wall);
            //game->bricks.append(brick);
        }
        for(j=120;j<160;j=j+80)
        {
            Tree *tree = new Tree();
            tree->setPos(i,j);
            game->scene->addItem(tree);
            //game->bricks.append(brick);
        }
        for(j=200;j<240;j=j+80)
        {
            Water *water = new Water();
            water->setPos(i,j);
            game->scene->addItem(water);
            //game->bricks.append(brick);
        }
        for(j=280;j<320;j=j+80)
        {
            Ice *ice = new Ice();
            ice->setPos(i,j);
            game->scene->addItem(ice);
            //game->bricks.append(brick);
        }
        for(j=360;j<400;j=j+80)
        {
            Brick *brick = new Brick();
            brick->setPos(i,j);
            game->scene->addItem(brick);
            //game->bricks.append(brick);
        }
    }

   /* for(i=65;i<800;i=i+99)
    {
        for(j=45;j<600;j=j+87)
        {
            Change * change = new Change();
            change->setPos(i,j);
            game->scene->addItem(change);
        }
    }*/

    game->show();
    game->play();
}






