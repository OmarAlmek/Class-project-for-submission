#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "powerup.h"
#include "enemy.h"
#include "enemy2.h"
#include "health.h"
#include "bullet.h"
#include <QDir>
#include <QDebug>
#include <QImage>
#include <QMediaPlayer>
#include "door.h"
#include "mainwindow.h"
#include <QGraphicsTextItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView *view= new QGraphicsView;
    QGraphicsScene *scene= new QGraphicsScene;

    view->setFixedSize(800, 700);
    view->setWindowTitle("GTA");
    QBrush brush(Qt::black);
    view->setBackgroundBrush(brush);

    QFile file("C:/Users/wifi/Downloads/mapaux.txt"); // parse the text file
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int boardData[12][12];
    QString temp;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap roadImage("C:/Users/wifi/OneDrive/Documents/projectresourse/road.png"); // create road image object
    QTransform tr; // qtransform object just to rotate the road 90 degrees , was too lazy to rotate it using another app
        tr.rotate(90);
       roadImage = roadImage.transformed(tr);
    roadImage = roadImage.scaledToWidth(60);
    roadImage = roadImage.scaledToHeight(60);

    QPixmap carsImage("C:/Users/wifi/OneDrive/Documents/projectresourse/car2.png"); // create car image object
      carsImage = carsImage.transformed(tr);
    carsImage= carsImage.scaledToWidth(60);
    carsImage= carsImage.scaledToHeight(60);


    QPixmap buildingImage1("C:/Users/wifi/Downloads/building1sky.jpg"); // create building object
    buildingImage1 = buildingImage1.scaledToWidth(50);
     buildingImage1 = buildingImage1.scaledToHeight(50);

     QPixmap buildingImage2("C:/Users/wifi/OneDrive/Documents/projectresourse/building2sky.jpg"); // create another building object
     buildingImage2 = buildingImage2.scaledToWidth(50);
      buildingImage2 = buildingImage2.scaledToHeight(50);

      QPixmap building1pav("C:/Users/wifi/OneDrive/Documents/projectresourse/building1pav.jpg"); // create another building object
      building1pav = building1pav.scaledToWidth(50);
       building1pav = building1pav.scaledToHeight(50);


       QPixmap building2pav("C:/Users/wifi/OneDrive/Documents/projectresourse/building2sky.jpg"); // create another building object
       building2pav = building2pav.scaledToWidth(50);
        building2pav = building2pav.scaledToHeight(50);

      QPixmap pavementImage("C:/Users/wifi/OneDrive/Documents/projectresourse/pavement.jpeg"); // create pavement object, next to the buildings at the top of the board
      pavementImage = pavementImage.scaledToWidth(50);
      pavementImage = pavementImage.scaledToHeight(50);

    QPixmap houseImage("C:/Users/wifi/OneDrive/Documents/projectresourse/house1.png"); // house object
    houseImage = houseImage.scaledToWidth(50);
    houseImage = houseImage.scaledToHeight(50);
    QPixmap grassImage("C:/Users/wifi/OneDrive/Documents/projectresourse/grass (2).png"); // grass object
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);
    QPixmap treeImage("C:/Users/wifi/Downloads/TreeDirt-Block.jpg"); // tree object
    treeImage = treeImage.scaledToWidth(50);
    treeImage = treeImage.scaledToHeight(50);
    QPixmap treeskyeImage("C:/Users/wifi/OneDrive/Documents/projectresourse/treeskye.jpg"); // tree object
    treeskyeImage = treeskyeImage.scaledToWidth(50);
    treeskyeImage = treeskyeImage.scaledToHeight(50);
    QPixmap stopsignImage("C:/Users/wifi/OneDrive/Documents/projectresourse/stopsignpav.jpg"); // tree object
    stopsignImage = stopsignImage.scaledToWidth(50);
    stopsignImage = stopsignImage.scaledToHeight(50);
    stopsignImage = stopsignImage.transformed(tr);
    QPixmap coneImage("C:/Users/wifi/OneDrive/Documents/projectresourse/conepav.jpg"); // tree object
    coneImage = coneImage.scaledToWidth(50);
    coneImage = coneImage.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[12][12]; // creating board
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            // Set Image

            if(((i == 0) &&  (j > 7 || j == 0))){
                boardItems[i][j].setPixmap(treeskyeImage); //set pavement tile next to buildings

            }
            else if((i ==2) && (j > 2 && j < 10)){
                 boardItems[i][j].setPixmap(pavementImage); //set pavement tile next to buildings

             }
            else if((i ==4 && j==6)){
                boardItems[i][j].setPixmap(stopsignImage); //set pavement tile next to buildings
            }
            else if((i ==6 && (j < 4 && j > 0))){
                boardItems[i][j].setPixmap(coneImage); //set pavement tile next to buildings
            }
            else if((i ==9 && j==3)){
                boardItems[i][j].setPixmap(carsImage); //set pavement tile next to buildings
            }
            else if((i ==10 && (j==3 || (j > 3 && j < 5)))){
                boardItems[i][j].setPixmap(carsImage); //set pavement tile next to buildings
            }
            else if((i ==3 || i==4) && (j==3)){
                boardItems[i][j].setPixmap(carsImage); //set pavement tile next to buildings
            }
            else if(i ==4 && j > 5){
                boardItems[i][j].setPixmap(building1pav); //set pavement tile next to buildings
            }
            else if((i == 5) && (j==6)){
                boardItems[i][j].setPixmap(houseImage); //set pavement tile next to buildings
            }
            else if((i == 6) && (j==6)){
                boardItems[i][j].setPixmap(grassImage); //set pavement tile next to buildings
            }
            else if (boardData[i][j] == -1 && (!((i == 0) &&  (j > 7))))
                boardItems[i][j].setPixmap(treeImage);
            else if (boardData[i][j]== 1)
                boardItems[i][j].setPixmap(roadImage);
            else if (boardData[i][j]== -2)
                boardItems[i][j].setPixmap(buildingImage1);
            else if (boardData[i][j]== -3)
                boardItems[i][j].setPixmap(buildingImage2);
            else if(boardData[i][j]== -4){
                boardItems[i][j].setPixmap(pavementImage); //set pavement tile next to buildings
            }

          // Set Position
          boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene->addItem(&boardItems[i][j]);
        }


    Powerup powerup1, powerup2;
    scene->addItem(&powerup1);
    powerup2.setPos(50 + 1 * 50, 50 + 7 * 50);// set position for second banana
    scene->addItem(&powerup2);



Bullet bullet1, bullet2, bullet3, bullet4;
bullet2.setPos(50 + 10 * 50, 50 + 1 * 50);
bullet3.setPos(50 +  1 * 50, 50 + 10 * 50);
bullet4.setPos(50 +  10 * 50, 50 + 10 * 50);
  scene->addItem(&bullet1);
  scene->addItem(&bullet2);
  scene->addItem(&bullet3);
  scene->addItem(&bullet4);


   Health heart1, heart2, heart3;
   heart1.setPos(50 +0 * 50, 50 + 13 * 50 );
   heart2.setPos(50 + 1 * 50, 50 + 13 * 50);
   heart3.setPos(50 + 2 * 50, 50 + 13 * 50);
   scene->addItem(&heart1);
   scene->addItem(&heart2);
   scene->addItem(&heart3);


    Enemy1 enemy1(boardData);
    Enemy2 enemy2(boardData);
    enemy2.setPos(50 +1* 50, 50 + 10 * 50);
    scene->addItem(&enemy1);
    scene->addItem(&enemy2);

    Door door;
QGraphicsTextItem *textconst = scene->addText("Time remaining:");
    textconst->setDefaultTextColor(QColorConstants::White);
    textconst->setPos(50+9*50, 50 +13 * 50);

    WinWindow w(nullptr,view,scene);
    LossWindow L(nullptr, view,scene);

    Player player(boardData, &enemy1, &enemy2, &powerup1, scene, &heart1, &heart2, &heart3,
                  view, &bullet1, &bullet2, &bullet3, &bullet4, &powerup1, &powerup2, &door, &w, &L);
    scene->addItem(&player);

    player.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player.setFocus();

    MainWindow m(nullptr,view,scene);
    m.show();
    return a.exec();
}
