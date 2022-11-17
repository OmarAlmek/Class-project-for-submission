#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "powerup.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[10][15];
    int health;
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
public:
    Player(int boardData[10][15]);
public slots:
    void keyPressEvent(QKeyEvent* event);
};

#endif // PLAYER_H
