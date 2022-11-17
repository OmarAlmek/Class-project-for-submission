#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "powerup.h"
#include "powerup2.h"
#include <QDir>
#include <QDebug>
#include <QImage>
#include <QMediaPlayer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;

    view.setFixedSize(750, 650);
    view.setWindowTitle("GTA");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);

    QFile file("C:/Users/wifi/OneDrive/Documents/projectresourse/map.txt"); // parse the text file
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int boardData[10][15];
    QString temp;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap roadImage("C:/Users/wifi/OneDrive/Documents/projectresourse/road_0.png"); // create road image object
    QTransform tr; // qtransform object just to rotate the road 90 degrees , was too lazy to rotate it using another app
        tr.rotate(90);
       roadImage = roadImage.transformed(tr);
    roadImage = roadImage.scaledToWidth(65);
    roadImage = roadImage.scaledToHeight(75);

    QPixmap carsImage("C:/Users/wifi/Downloads/My project(5).png"); // create car image object
      carsImage = carsImage.transformed(tr);
    carsImage= carsImage.scaledToWidth(50);
    carsImage= carsImage.scaledToHeight(50);


    QPixmap buildingImage1("C:/Users/wifi/Downloads/Spritesheet_adobe_express.png"); // create building object
    buildingImage1 = buildingImage1.scaledToWidth(100);
     buildingImage1 = buildingImage1.scaledToHeight(50);

     QPixmap buildingImage2("C:/Users/wifi/Downloads/Spritesheet_adobe_express(1).png"); // create another building object
     buildingImage2 = buildingImage2.scaledToWidth(100);
      buildingImage2 = buildingImage2.scaledToHeight(50);

      QPixmap pavementImage("C:/Users/wifi/Downloads/363170d5530e4dff3732c9fac51db744--pixel-art-indie-games_adobe_express.jpeg"); // create pavement object, next to the buildings at the top of the board
      pavementImage = pavementImage.scaledToWidth(150);
      pavementImage = pavementImage.scaledToHeight(85);

    QPixmap houseImage("C:/Users/wifi/OneDrive/Documents/projectresourse/house1.png"); // house object
    houseImage = houseImage.scaledToWidth(50);
    houseImage = houseImage.scaledToHeight(50);
    QPixmap grassImage("C:/Users/wifi/OneDrive/Documents/projectresourse/grass (2).png"); // grass object
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[10][15]; // creating board
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
        {
            // Set Image
            if ((boardData[i][j] == -1 && !(i > 6)) || (boardData[i][j] == -1 && (i == 6)))
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
            scene.addItem(&boardItems[i][j]);
        }

    Player player(boardData);
    scene.addItem(&player);

    Powerup1 powerup1; // i made 2 different classes for powerup (banana), each class represents one banana
    scene.addItem(&powerup1);

    Powerup2 powerup2;
    scene.addItem(&powerup2);

    player.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player.setFocus();

    view.setScene(&scene);
    view.show();
    return a.exec();
}
