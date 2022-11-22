#include "winloss.h"

WinLoss::WinLoss(bool wincon)
{
    if (wincon == true){
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/winScreen (2).jpeg");
    image = image.scaledToWidth(750);
    image = image.scaledToHeight(660);
    setPixmap(image);
   setPos( 1, 1 );
    }
    else  {
        QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/lossScreen.png");
        image = image.scaledToWidth(750);
        image = image.scaledToHeight(660);
    setPixmap(image);
   setPos(1 , 1 );
    }
}
