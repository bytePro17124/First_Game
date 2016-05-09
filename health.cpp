#include "health.h"
#include <QFont>
#include "game.h"
extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Monospace", 12));


}


void Health::decrease()
{
    health--;
    if (health > 0) {
        setPlainText("Health: " + QString::number(health));
    } else {
        setPlainText("You Have NO HP! Game Over!");
        game->score->setPlainText("FINAL Score: " + QString::number(game->score->getScore()));
    }
}

int Health::getHealth()
{
    return health;
}
