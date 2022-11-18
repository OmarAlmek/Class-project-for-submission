#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>

class Health : public QGraphicsPixmapItem
{
public:
    Health();
    void decrease();
    int gethealth();
private:
    int health;
};

#endif // HEALTH_H
