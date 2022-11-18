#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>

class Enemy: public QObject, public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[12][12];
    int health;
public:
    Enemy(int boardData[12][12]);
};

#endif // ENEMY_H
