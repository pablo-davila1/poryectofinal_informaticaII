#ifndef PLAYER2_H
#define PLAYER2_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject> //siempre que halla un slots
#include "boss.h"


class player2:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    player2(QGraphicsItem * parent2 = 0);
    void keyPressEvent(QKeyEvent * event2);

};

#endif // PLAYER2_H
