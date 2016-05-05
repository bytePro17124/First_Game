#include "player.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy.h"
#include <QDebug>


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:soundeffects/shot1-1.wav"));

    setPixmap(QPixmap(":/images/turret.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        if (this->pos().x() > 25)
            this->setPos(x()-20, y());
    }
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right) {
        if (this->pos().x() + this->pixmap().width() < 1175)
            this->setPos(x()+20, y());
    }
    else if (event->key() == Qt::Key_Space) {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + this->pixmap().width()/2, y());
        this->scene()->addItem(bullet);




//        if (bulletsound->state() == QMediaPlayer::PlayingState){

        if (bulletsound->state() == QMediaPlayer::StoppedState){
            qDebug() << "attempted to play bulletsound from stopped state" << bulletsound->state() << bulletsound->error() << bulletsound->mediaStatus();
            bulletsound->play();
        }
        else
        {
            qDebug() << "attempted to play bulletsound otherwise " << bulletsound->state() << bulletsound->error() << bulletsound->mediaStatus();
            bulletsound->stop();
        }

    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

