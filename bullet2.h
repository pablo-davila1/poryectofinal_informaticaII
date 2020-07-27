#ifndef BULLET2_H
#define BULLET2_H
#include <QGraphicsRectItem>


class bullet2 : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet2();

private slots:
    void move2();

};

#endif // BULLET2_H
