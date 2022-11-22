#include "t.h"

T::T()
{
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/heart.png");
    image = image.scaledToWidth(40);
    image = image.scaledToHeight(40);
}
