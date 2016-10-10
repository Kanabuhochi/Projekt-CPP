#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T13:15:03
#
#-------------------------------------------------

QT       += core gui

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
    bullet_enemy2.cpp \
    enemy2.cpp

HEADERS  += \
    bullet.h \
    player.h \
    game.h \
    wall.h \
    enemy.h \
    bullet_enemy.h \
    change.h \
    bullet_enemy2.h \
    enemy2.h

FORMS    +=

RESOURCES += \
    resources.qrc