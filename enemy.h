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
#include <vector>
#include <iostream>
#include <QQueue>
#include <stack>
#include <iostream>
#include <set>
#include <stdio.h>
#include <float.h>
using namespace std;
#define ROW 12
#define COL 12

const int N = 12;
const int INF = 99999;
// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;

class Enemy1: public QObject, public QGraphicsPixmapItem
{
private:
    int data[12][12];
    int health;
public:
    int row, column;
    bool alive=true;
    Enemy1(int boardData[12][12]);
    void losehealth();
    int gethealth();
    void set_row(int r);
    void set_column(int c);
    void reset_health();
    void sethealth(int h);
    void hurt();

public slots:
    Pair find(Pair src, Pair des, vector <vector <Pair>> parent);
    void movingenemy(Pair &source, Pair destination);
    Pair bfs(Pair source, Pair des, int matrix[12][12]);
};

#endif // ENEMY_H
