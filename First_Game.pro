#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T00:58:36
#
#-------------------------------------------------

QT += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = First_Game
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    health.cpp

HEADERS += game.h \
    player.h \
    bullet.h \
    enemy.h \
    score.h \
    health.h

FORMS    +=

RESOURCES += res.qrc
