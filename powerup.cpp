
#include "powerup.h"

Powerup::Powerup()
    {
        // Set Image
       QPixmap image("C:/Users/wifi/Downloads/My project(6).png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);
        // Set Position
        setPos(50 + 10 * 50, 50 + 5 * 50);
    }
