#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class win;
}

class Win : public QWidget
{
    Q_OBJECT

public:
    explicit Win(QGraphicsView *ptrview, QGraphicsScene *ptrscene, QWidget *parent = nullptr);
    ~Win();

private:
    Ui::win *ui;
    QGraphicsScene *sceneptr;
    QGraphicsView *viewptr;
};

#endif // WIN_H
