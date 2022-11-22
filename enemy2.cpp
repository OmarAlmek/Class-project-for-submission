#include "enemy2.h"

Enemy2::Enemy2(int boardData[12][12])
{
    // Set Image
    QPixmap image("C:/Users/wifi/Downloads/enemy1.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 10;
    column = 6;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set health
    health = 2;
}
void Enemy2::movingenemy ()
{
        int n = rand()%4;

        if (n==0 && data[row-1][column]>=0)
        {
            row--;// this is not setting a position
             setPos(50+(50*column),50+(50*row));
        }
            else if (n==1 && data[row+1][column]>=0)
        {
            row++;
              setPos(50+(50*column),50+(50*row));
        }
        else if ((n==2 )&& (data[row][column+1]>=0))
     {
            column++;
           setPos(50+(50*column),50+(50*row));
     }
     else if ( n ==3 &&data[row][column-1]>=0)
    {
         column--;
          setPos(50+(50*column),50+(50*row));
    }
}
void Enemy2::losehealth(){
    health--;
}
int Enemy2::gethealth(){
    return health;
}
void Enemy2::set_row(int r){
    row=r;
}
void Enemy2::set_column(int c){
    column=c;
}
void Enemy2::reset_health(){
    health=2;
}
