#include "bullet.h"

Bullet::Bullet()
{
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/bullet.png");
    image = image.scaledToWidth(40);
    image = image.scaledToHeight(30);
    setPixmap(image);

    // Set Position
    setPos(50 + 1 * 50, 50 + 1 * 50);
}
