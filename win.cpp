#include "win.h"
#include "ui_win.h"

Win::Win(QGraphicsView *ptrview, QGraphicsScene *ptrscene, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
    sceneptr= ptrscene;
    viewptr= ptrview;
    viewptr->setScene(sceneptr);
}

Win::~Win()
{
    delete ui;
}
