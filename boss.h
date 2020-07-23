#ifndef BOSS_H
#define BOSS_H
#include <QGraphicsRectItem>

class boss :  public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    boss();
public slots:
    void show_boss();

};

#endif // BOSS_H
