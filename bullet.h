#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
public slots:
    void move();
private:
    QMediaPlayer * deathsound;
};

#endif // BULLET_H
