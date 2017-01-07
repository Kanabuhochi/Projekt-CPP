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
    tree.cpp \
    water.cpp \
    ice.cpp \
    cursor.cpp \
    level1.cpp \
    brick.cpp \
    brickhitdown.cpp \
    brickhitup.cpp \
    brickhitleft.cpp \
    brickhitright.cpp \
    brick_corner.cpp \
    enemy_fast.cpp \
    panzer.cpp \
    remaining.cpp \
    nextlevel.cpp \
    mapeditor.cpp

HEADERS  += \
    bullet.h \
    player.h \
    game.h \
    wall.h \
    enemy.h \
    bullet_enemy.h \
    tree.h \
    water.h \
    ice.h \
    cursor.h \
    level1.h \
    brick.h \
    brickhitdown.h \
    brickhitup.h \
    brickhitleft.h \
    brickhitright.h \
    brick_corner.h \
    enemy_fast.h \
    panzer.h \
    remaining.h \
    nextlevel.h \
    mapeditor.h

FORMS    +=

RESOURCES += \
    resources.qrc
