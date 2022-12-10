#ifndef LOSSWINDOW_H
#define LOSSWINDOW_H

#include "qaudiooutput.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class LossWindow;
}

class LossWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LossWindow(QWidget *parent = nullptr, QGraphicsView* view1=nullptr, QGraphicsScene* scene1=nullptr);
    ~LossWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LossWindow *ui;
    QGraphicsView*view;
    QGraphicsScene*scene;
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
};

#endif // LOSSWINDOW_H
