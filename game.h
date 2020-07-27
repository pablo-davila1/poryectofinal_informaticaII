#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "myrect.h"
#include "score.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <helath.h>


class Game : public QGraphicsView
{
public:
    Game(QWidget *parents = 0);

    QGraphicsScene * scene;
    MyRect * player;
    score * Score;
    Health * health;
};

#endif // GAME_H
