#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"
#include "score.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/bullet.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(35);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-18);
    if (pos().y() + pixmap().height()/2 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

