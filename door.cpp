#include "door.h"

Door::Door()
{
    QPixmap image("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/door.png");
    image = image.scaledToWidth(60);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    setPos(50 + 7 * 50, 50 + 5 * 50);
}
