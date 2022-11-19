#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>

#include <algorithm>

#include <QPainter>

#include <chrono>
#include <memory>
#include <random>
#include <utility>
#include <vector>

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
