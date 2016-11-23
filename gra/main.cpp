#include <QApplication>
#include "game.h"
#include "menu.h"
#include "player.h"
#include "enemy.h"
#include <time.h>
#include <stdlib.h>
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
