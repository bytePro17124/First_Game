#include "score.h"
#include "game.h"
#include <QFont>

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Monospace", 12));
}
void Score::increase()
{
    if (game->health->getHealth() > 0) {
        score++;
        setPlainText("Score: " + QString::number(score));
    } else {
        setPlainText("FINAL Score: " + QString::number(score));
    }
}
int Score::getScore()
{
    return score;
}

