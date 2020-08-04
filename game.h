#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "myrect.h"
#include "score.h"
#include "player2.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <helath.h>
#include <QList>
#include <QKeyEvent>
#include <QMainWindow>



class Game : public QGraphicsView
{
public:
    Game(QWidget *parents = nullptr);

    //void keyPressEvent(QKeyEvent * event);


    QGraphicsScene * scene;

    MyRect  *player1;


    score * Score;
    Health * health;





};

#endif // GAME_H
