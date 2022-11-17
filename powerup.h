#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>
class Powerup : public QGraphicsPixmapItem
{
public:
    Powerup();
    int duration;
};

#endif // POWERUP_H
