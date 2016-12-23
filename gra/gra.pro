#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T13:15:03
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gra
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    player.cpp \
    game.cpp \
    wall.cpp \
    enemy.cpp \
    bullet_enemy.cpp \
    change.cpp \
    tree.cpp \
    water.cpp \
    ice.cpp \
    menu.cpp \
    cursor.cpp \
    level1.cpp \
    brick.cpp \
    brickhitdown.cpp \
    brickhitup.cpp \
    brickhitleft.cpp \
    brickhitright.cpp \
    level2.cpp \
    brick_corner.cpp \
    enemy_fast.cpp \
    panzer.cpp

HEADERS  += \
    bullet.h \
    player.h \
    game.h \
    wall.h \
    enemy.h \
    bullet_enemy.h \
    change.h \
    tree.h \
    water.h \
    ice.h \
    menu.h \
    cursor.h \
    level1.h \
    brick.h \
    brickhitdown.h \
    brickhitup.h \
    brickhitleft.h \
    brickhitright.h \
    level2.h \
    brick_corner.h \
    enemy_fast.h \
    panzer.h

FORMS    +=

RESOURCES += \
    resources.qrc
