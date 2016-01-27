#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    setScene(scene);
    setFixedSize(810,605);
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    player = new Player();


    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player->setPos(width()/2 - player->pixmap().width()/2, height() - player->pixmap().height()-5);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

//    QMediaPlaylist * bgmusic = new QMediaPlaylist();
//    bgmusic->addMedia(QUrl("qrc:sounds/bgmusic.wav"));
//    bgmusic->setCurrentIndex(1);
//    bgmusic->PlaybackMode(Qt::Loop);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:sounds/bgmusic.wav"));
    music->play();
}

