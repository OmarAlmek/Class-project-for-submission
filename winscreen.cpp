#include "winscreen.h"
#include "ui_winscreen.h"

winscreen::winscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winscreen)
{
    ui->setupUi(this);
}

winscreen::~winscreen()
{
    delete ui;
}
