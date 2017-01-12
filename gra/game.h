#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "wall.h"
#include "brick.h"
#include "brick_corner.h"
#include "brickhitdown.h"
#include "brickhitup.h"
#include "brickhitright.h"
#include "brickhitleft.h"
#include "bullet_enemy.h"
#include "tree.h"
#include "ice.h"
#include "water.h"
#include "eagle.h"
#include "change.h"
#include "cursor.h"
#include <QList>
#include <QGraphicsTextItem>
#include "remaining.h"
#include <level1.h>
#include <QMediaPlayer>
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QTimer * timer5;
    QTimer * checker;
    QTimer * timer;
    QTimer * timer2;
    QTimer * menus;
    QTimer * nexto;
    QTimer * rst;
    QTimer * scoring;
    QGraphicsScene * scene;
    QGraphicsPixmapItem * beg;
    int enemies = 0;
    int move = 0;
    int score = 0;
    int newscore = 0;
    int total = 20;
    int stage = 0;
    int normal = 0;
    int fast = 0;
    int pancer = 0;
    int players = 0;
    int pociski_gracz = 0;
    int cont = 1;
    void menu();
    void play();
    void endmusic();
    QGraphicsTextItem* normalo;
    QGraphicsTextItem* fasto;
    QGraphicsTextItem* pancero;
    QGraphicsTextItem* nn;
    QGraphicsTextItem* ff;
    QGraphicsTextItem* pp;
    QGraphicsTextItem* sco;
    QGraphicsTextItem* totalo;
    QGraphicsTextItem* high;
    QVector<QObject*> klocki;
    QList<Remaining *> remains;
    QGraphicsTextItem * gam;
    QGraphicsTextItem * over;
    QMediaPlayer * tank;
    QMediaPlayer * wall;
    QMediaPlayer * bhit;
    QMediaPlayer * shot;
    QMediaPlayer * iglo;
    QMediaPlayer * endo;
public slots:
    void spawn();
    void check();
    void gover();
    void endscreen();
    void start();
    void reset();
    void scores();
    void next();
};

#endif // GAME_H
