#include "level1.h"
#include <QBrush>
extern Game * game;

Level1::Level1()
{
    game->scene->clear();
    game->setBackgroundBrush(QBrush(QImage(":/images/images/tlo/bg9.jpg")));
    game->setScene(game->scene);

  //  Enemy * enemy = new Enemy();
  //  enemy->setScale(1);
  //  enemy->setPos(50,25); // 400 i 745
  //  game->scene->addItem(enemy);

    int i=0;
    int j=0;
    for(i=140;i<660;i=i+40)
    {
        for(j=40;j<530;j=j+40)
        {
            Tree *tree = new Tree();
            tree->setPos(i,j);
           game->scene->addItem(tree);
       }
    }
    Player * player = new Player();
    player->setScale(1);
    player->setPos(405,520);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    game->scene->addItem(player);
    player->setFocus();
    for(i=65;i<800;i=i+99)
    {
        for(j=45;j<600;j=j+87)
        {
            Change * change = new Change();
            change->setPos(i,j);
            game->scene->addItem(change);
        }
    }

    game->show();
 //   game->play();
}






