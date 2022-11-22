#ifndef ENEMY2_H
#define ENEMY2_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QImage>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
class Enemy2: public QObject, public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[12][12];
    int health;
public:
    Enemy2(int boardData[12][12]);
    void losehealth();
    int gethealth();
    void set_row(int r);
    void set_column(int c);
    void reset_health();

public slots:
    void movingenemy ();
};

#endif // ENEMY_H
