#include "powerup2.h"

Powerup2::Powerup2()
{
    QPixmap image("C:/Users/wifi/Downloads/My project(6).png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    duration = 5;

    // Set Position
    setPos(50 + 7 * 50, 50 + 2 * 50);
}
