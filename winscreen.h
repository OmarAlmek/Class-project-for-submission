#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <QWidget>
#include <QDialog>
#include <QGraphicsView>
#include <QMediaPlayer>


namespace Ui {
class winscreen;
}

class winscreen : public QWidget
{
    Q_OBJECT

public:
    explicit winscreen(QWidget *parent = nullptr);
    ~winscreen();

private:
    Ui::winscreen *ui;
};

#endif // WINSCREEN_H
