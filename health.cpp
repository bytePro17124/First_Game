#include "health.h"
#include <QFont>

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
    }
}

int Health::getHealth()
{
    return health;
}
