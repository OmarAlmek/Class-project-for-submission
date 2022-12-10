#include "losswindow.h"
#include "ui_losswindow.h"

LossWindow::LossWindow(QWidget *parent, QGraphicsView* view1, QGraphicsScene* scene1) :
    QMainWindow(parent),
    ui(new Ui::LossWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image : url(C:/Users/wifi/Downloads/lost (1).jpg)");
    view=view1;
    scene=scene1;
}

LossWindow::~LossWindow()
{
    delete ui;
}

void LossWindow::on_pushButton_clicked()
{
    view->setScene(scene);
    view->show();
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/sound/gametheme2.mp3"));
    musicaudio->setVolume(50);
    music->setAudioOutput(musicaudio);
    music->play();
    this->close();
}


void LossWindow::on_pushButton_2_clicked()
{
    view->hide();
    this->close();
}

