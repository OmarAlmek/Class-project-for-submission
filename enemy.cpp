#include "enemy.h"

Enemy::Enemy(int boardData[12][12])
{
    // Set Image
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/enemy.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 8;
    column = 7;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set health
    health = 2;
}
