#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include "health.h"
#include <unistd.h>
#include "powerup.h"
#include "enemy.h"
#include "bullet.h"
#include "enemy2.h"
#include "health.h"
#include"win.h"


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[12][12];
    int health;
    bool *collision;
    bool alive = true;
    bool powered = false;
    int count = 0;
    Enemy1 *enemy1;
    Enemy2 *enemy2;
    Health * htprr1,* htprr2,* htprr3;
     QGraphicsScene *sptr;
     QGraphicsView *vptr;
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
    QTimer *timer;
    Win *win1;
public:
    Player(int boardData[12][12], Enemy1* ptrenemy1, Enemy2* ptrenemy2, Powerup* fptr, QGraphicsScene *sptrr , Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *vptr, Win *win1);
    int gethealth();
    bool getstatus();
    void setstatus();
    int decreasehealth();
    bool* getcol();
    void fixcol();
    void collide();
    void sethealth(int hp);



public slots:
    void keyPressEvent(QKeyEvent* event);
    void empower();

};

#endif // PLAYER_H
