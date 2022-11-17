#include "powerup.h"

Powerup::Powerup()
    {
        // Set Image
        QPixmap image("C:/Users/wifi/Downloads/My project(6).png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);
        duration = 5;

        // Set Position
        setPos(50 + 5 * 50, 50 + 5 * 50);
    }
