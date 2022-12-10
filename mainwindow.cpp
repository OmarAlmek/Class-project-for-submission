#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,QGraphicsView* view,QGraphicsScene* scene) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image : url(C:/Users/wifi/Downloads/background (1).jpg)");
    view1=view;
    scene1=scene;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    view1->setScene(scene1);
    view1->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

