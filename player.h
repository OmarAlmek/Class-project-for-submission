#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "health.h"
#include "powerup.h"
#include "enemy.h"
#include "bullet.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[12][12];
    Health * hp;;
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
public:
    Player(int boardData[12][12]);
public slots:
    void keyPressEvent(QKeyEvent* event);
};

#endif // PLAYER_H
