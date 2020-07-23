#ifndef BULLET_ENEMY_H
#define BULLET_ENEMY_H
#include <QGraphicsRectItem>


class bullet_enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet_enemy();

public slots:
    void move();
};

#endif // BULLET_ENEMY_H
