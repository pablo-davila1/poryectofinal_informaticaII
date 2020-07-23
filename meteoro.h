#ifndef METEORO_H
#define METEORO_H
#include <QGraphicsRectItem>
#include <QObject>


class meteoro :  public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    meteoro();
    float get_Vida();

private:
    int vida = 0;

public slots:
    void move();
};

#endif // METEORO_H
