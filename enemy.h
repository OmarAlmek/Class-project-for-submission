#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>

class Enemy1: public QObject, public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[12][12];
    int health;
    QTimer *timerenemy;
public:
    Enemy1(int boardData[12][12]);
    void losehealth();
    int gethealth();
public slots:
    void movingenemy();
};

#endif // ENEMY_H
