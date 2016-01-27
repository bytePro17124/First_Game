#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <health.h>
#include "game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    int random_number = rand() % 720;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/baddie.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{

    setPos(x(), y()+5);
    if (this->pos().y() > scene()->height() ) {
        game->health->decrease();
        delete this;
    }

}

