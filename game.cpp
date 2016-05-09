#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>
#include <QMediaPlaylist>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    setScene(scene);
    setFixedSize(1210,905);
    scene->setSceneRect(0,0,1200,900);
    setBackgroundBrush(QBrush(QImage(":/images/background1.png")));

    player = new Player();

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y()+35);
    scene->addItem(health);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player->setPos(width()/2 - player->pixmap().width()/2, height() - player->pixmap().height()-5);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    QMediaPlaylist * bgmusiclist = new QMediaPlaylist;
    bgmusiclist->setPlaybackMode(QMediaPlaylist::Loop);
    bgmusiclist->addMedia(QUrl("qrc:bgmusic/PowerPunch_80-1.wav"));
    bgmusiclist->setCurrentIndex(1);

    QMediaPlayer * music = new QMediaPlayer();
    music->setPlaylist(bgmusiclist);
    music->setVolume(88);
    music->play();

}

