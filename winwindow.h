#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class WinWindow;
}

class WinWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WinWindow(QWidget *parent = nullptr, QGraphicsView* view1=nullptr, QGraphicsScene* scene1=nullptr);
    ~WinWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::WinWindow *ui;
    QGraphicsView*view;
    QGraphicsScene*scene;
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * musicaudio = new QAudioOutput();
};

#endif // WINWINDOW_H
