#include "health.h"
#include <QLabel>

Health::Health()
{
// set picture
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/heart.png");
    image = image.scaledToWidth(40);
    image = image.scaledToHeight(40);
    setPixmap(image);

    // Set Position
    setPos(50 + 1 * 50, 50 + 13 * 50);
}
