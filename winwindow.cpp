#include "winwindow.h"
#include "ui_winwindow.h"

WinWindow::WinWindow(QWidget *parent, QGraphicsView* view1, QGraphicsScene* scene1) :
    QMainWindow(parent),
    ui(new Ui::WinWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image : url(C:/Users/wifi/Downloads/winning.jpg)");
    view=view1;
    scene=scene1;
}

WinWindow::~WinWindow()
{
    delete ui;
}

void WinWindow::on_pushButton_clicked()
{
    view->setScene(scene);
    view->show();
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/sound/gametheme2.mp3"));
    musicaudio->setVolume(50);
    music->setAudioOutput(musicaudio);
    music->play();
    this->close();
}


void WinWindow::on_pushButton_3_clicked()
{
    view->hide();
    this->close();
}

