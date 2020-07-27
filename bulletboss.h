#ifndef BULLETBOSS_H
#define BULLETBOSS_H
#include <QGraphicsRectItem>
#include <QObject>

class bulletboss : public QGraphicsRectItem , public QObject
{
    Q_OBJECT
public:
    bulletboss();

public slots:
    void movebull();
};

#endif // BULLETBOSS_H
