#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QElapsedTimer>
#include "health.h"
#include <unistd.h>
#include "powerup.h"
#include "enemy.h"
#include "bullet.h"
#include "enemy2.h"
#include "health.h"
#include <QTime>
#include "winwindow.h"
#include "losswindow.h"
#include "door.h"


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[12][12];
    int health;
    int x=1;
    int y=1;
    int z=1;
    bool alive = true;
     int timecount;
        int timecount2;
       int i=0; // for timer on bottom right of display
       int k =0;
    Enemy1 *enemy1;
    Enemy2 *enemy2;
    Health * htprr1,* htprr2,* htprr3;
    Bullet * bul1,* bul2,* bul3,* bul4;
    Powerup * pow1, * pow2;
    Door *door;
    QGraphicsScene *sptr;
    QGraphicsView *vptr;
    QGraphicsTextItem *text[5];
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
    QTimer *t;
    QTimer *dt;
    WinWindow*w1;
    LossWindow*l1;
    QTimer*powerupt;
    QTimer*movingTimer;
    QTimer*timer;
    QTimer*shotTimer;
    QTimer*enemyhurt;

public:
    Player(int boardData[12][12], Enemy1* ptrenemy1, Enemy2* ptrenemy2, Powerup* fptr,
    QGraphicsScene *sptrr , Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *viewptr, Bullet *b1,
    Bullet *b2, Bullet *b3, Bullet *b4, Powerup* pu1, Powerup *pu2,  Door* dr, WinWindow* w, LossWindow*l);
    int gethealth();
    bool powered = false;
    bool getstatus();
    void setstatus();
    int decreasehealth();
    void sethealth(int hp);
    void time();



public slots:
   void keyPressEvent(QKeyEvent* event);
   void empower();
   void nopower();
   void resetpos();
   void shoot();
   void reducecount();
   void reducecount2();
   void r();
   void l();
   void noshoot();
   void enemy1norm();
   void enemy2norm();
/*   void resetGame(int boardData[12][12], Enemy1* ptrenemy1, Enemy2 *ptrenemy2, QGraphicsScene *sptrr,
   Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *viewptr,
   Bullet *b1, Bullet *b2, Bullet *b3, Bullet *b4, Powerup* pu1, Powerup *pu2, Door* dr);*/
};

#endif // PLAYER_H
