#include "player.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:sounds/turret.wav"));

    setPixmap(QPixmap(":/images/turret.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        if (this->pos().x() > 10)
            this->setPos(x()-20, y());
    }
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right) {
        if (this->pos().x() + this->pixmap().width() < 785)
            this->setPos(x()+20, y());
    }
    else if (event->key() == Qt::Key_Space) {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + this->pixmap().width()/2, y());
        this->scene()->addItem(bullet);
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

