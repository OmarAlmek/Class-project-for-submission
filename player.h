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


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[12][12];
    int health;
    bool collision;
    bool alive = true;
    bool powered = false;
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
    QTimer *timer;
public:
    Player(int boardData[12][12]);
    int gethealth();
    bool getstatus();
    void setstatus();
    int decreasehealth();
    bool getcol();
    void fixcol();
    void collide();


public slots:
    void keyPressEvent(QKeyEvent* event);
    void empower();

};

#endif // PLAYER_H
