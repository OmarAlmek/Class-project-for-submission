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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene *scene= new QGraphicsScene;

    view.setFixedSize(800, 700);
    view.setWindowTitle("GTA");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);

    QFile file("C:/Users/wifi/OneDrive/Documents/projectresourse/map.txt"); // parse the text file
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


    QPixmap buildingImage1("C:/Users/wifi/Downloads/Spritesheet_adobe_express.png"); // create building object
    buildingImage1 = buildingImage1.scaledToWidth(50);
     buildingImage1 = buildingImage1.scaledToHeight(50);

     QPixmap buildingImage2("C:/Users/wifi/Downloads/Spritesheet_adobe_express(1).png"); // create another building object
     buildingImage2 = buildingImage2.scaledToWidth(50);
      buildingImage2 = buildingImage2.scaledToHeight(50);

      QPixmap pavementImage("C:/Users/wifi/Downloads/363170d5530e4dff3732c9fac51db744--pixel-art-indie-games_adobe_express.jpeg"); // create pavement object, next to the buildings at the top of the board
      pavementImage = pavementImage.scaledToWidth(50);
      pavementImage = pavementImage.scaledToHeight(50);

    QPixmap houseImage("C:/Users/wifi/OneDrive/Documents/projectresourse/house1.png"); // house object
    houseImage = houseImage.scaledToWidth(50);
    houseImage = houseImage.scaledToHeight(50);
    QPixmap grassImage("C:/Users/wifi/OneDrive/Documents/projectresourse/grass (2).png"); // grass object
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);
    QPixmap treeImage("C:/Users/wifi/OneDrive/Documents/projectresourse/tree.png"); // tree object
    treeImage = treeImage.scaledToWidth(50);
    treeImage = treeImage.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[12][12]; // creating board
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            // Set Image
            if (boardData[i][j] == -1)
                boardItems[i][j].setPixmap(roadImage); // set road position
            else if(i == 6 && j == 4){
                boardItems[i][j].setPixmap(houseImage); //set house image position

            }
            else if(i ==7 && j == 4){
                boardItems[i][j].setPixmap(grassImage); // set grass around house
            }
            else if(i ==6 && j == 5){
                boardItems[i][j].setPixmap(grassImage); // set grass around house
            }
            else if(i ==7 && j == 5){
                boardItems[i][j].setPixmap(grassImage); // set grass around house
            }
            else if(boardData[i][j]== -7){
                boardItems[i][j].setPixmap(treeImage);
            }

            else if(boardData[i][j]== -2){
                boardItems[i][j].setPixmap(buildingImage1); //set buldiing position
            }
            else if(boardData[i][j]== -3){
                boardItems[i][j].setPixmap(buildingImage2); //set buldiing position
            }
            else if(boardData[i][j]== -4){
                boardItems[i][j].setPixmap(pavementImage); //set pavement tile next to buildings
            }
            else if(boardData[i][j]== -5){
                boardItems[i][j].setPixmap(carsImage);} //set cars positions
            else if(i >= 6 ){
                boardItems[i][j].setPixmap(pavementImage);
                //set pavement tile // i was too lazy to summarize them to one if statement so i just kept adding
            }

            else{
            boardItems[i][j].setPixmap(roadImage);
          }

            // Set Position
            boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene->addItem(&boardItems[i][j]);
        }


    Powerup powerup1, powerup2;
    scene->addItem(&powerup1);
    powerup2.setPos(50 + 7 * 50, 50 + 2 * 50);// set position for second banana
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



//   while (player.getstatus() == true && *player.getcol() == true) {
//       switch (player.gethealth()){
//       case 3:
//           scene.removeItem(&heart3);
//      player.fixcol();
//           break;
//       case 2:
//           scene.removeItem(&heart2);
//           player.fixcol();
//           break;
//       case 1:
//           scene.removeItem(&heart1);
//            player.setstatus();
//       default:
//           break;
//       }
//}



    Enemy1 enemy1(boardData);
    Enemy2 enemy2(boardData);
    enemy2.setPos(50 +5* 50, 50 + 10 * 50);
    scene->addItem(&enemy1);
    scene->addItem(&enemy2);

 Win *winscreen = new Win(&view, scene);

    Player player(boardData, &enemy1, &enemy2, &powerup1, scene, &heart1, &heart2, &heart3, view, winscreen);
    scene->addItem(&player);

    player.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player.setFocus();

    view.setScene(scene);
    view.show();
    return a.exec();
}
