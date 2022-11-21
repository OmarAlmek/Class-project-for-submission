#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H
#include <QThread>
#include "player.h"

class Playerthread : public QThread
{
    Q_OBJECT
private:
    Player* p;
public:
    Playerthread(Player *p);
    void run() override{
        QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuff.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        p->setPixmap(image);
        p->powered =true;
        qDebug("cleararwarawrqwerqwrqw");
    }
};

#endif // PLAYERTHREAD_H
