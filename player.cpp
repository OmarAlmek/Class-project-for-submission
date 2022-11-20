#include "player.h"
#include <QDebug>


Player::Player(int boardData[12][12], Enemy1* ptrenemy1, Enemy2 *ptrenemy2, Powerup* fptr, QGraphicsScene *sptrr , Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *vptr, Win *win1)
{
    health = 3;
    collision = new bool;
    *collision = false;
    // Set Image
    QPixmap image("C:/Users/wifi/Downloads/My project-1(1).png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
    row = 4;
    column = 5;
    setPos(50 + column * 50, 50 + row * 50);
        sptr = sptrr;
        htprr1 =hptr1;
        htprr2 = hptr2;
        htprr3 = hptr3;
        enemy1 = ptrenemy1;
        enemy2 = ptrenemy2;
        this->win1= win1;
        this->vptr= vptr;


    timer = new QTimer;

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];

//set music theme
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/Downloads/Mission Impossible Theme (Full Theme).mp3"));
    musicaudio->setVolume(5);
    music->setAudioOutput(musicaudio);
    music->play();

   }
void Player::keyPressEvent(QKeyEvent* event)
{  QMediaPlayer *player = new QMediaPlayer;
     QAudioOutput *audioOutput = new QAudioOutput;
    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
    {

// audio queue for movement

        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net)(1).mp3"));
        audioOutput->setVolume(50);
        player->play();
//move the player
        row--;

    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
    {
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net)(2).mp3"));
        audioOutput->setVolume(50);
        player->play();
        row++;
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
    { // changing character model when moving to right
        QPixmap image("C:/Users/wifi/Downloads/My project-1(1).png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        QTransform tr;
            tr.scale(1, 1);
          image= image.transformed(tr);
           setPixmap(image);
           player->setAudioOutput(audioOutput);
           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
           audioOutput->setVolume(50);
           player->play();
        column++;
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    { // changing character model when moving to left
        QPixmap image("C:/Users/wifi/Downloads/My project-1(1).png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        QTransform tr;
            tr.scale(-1, 1);
          image= image.transformed(tr);
           setPixmap(image);
           player->setAudioOutput(audioOutput);
           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
           audioOutput->setVolume(50);
           player->play();
        column--;
    }
    setPos(50 + column * 50, 50 + row * 50);

    //power up
    QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(Powerup)){
                scene()->removeItem(items[i]);
                connect(timer, SIGNAL(timeout()),this, SLOT(empower()));
                timer->start(10);
                }
            }
        //losing health when touching enemy
    QList<QGraphicsItem*> enemies = collidingItems();
         for (int i = 0; i < enemies.size(); i++)
            {
                if (typeid(*enemies[i]) == typeid(Enemy1) || typeid(*enemies[i])== typeid(Enemy2)){

                    sethealth(decreasehealth());
                    collide();
                          if (health==2)
                               {
                                   sptr->removeItem(htprr3);
                               }

                          else  if (health == 1)
                               {
                                   sptr->removeItem(htprr2);
                               }
                          else {
                              sptr->removeItem(htprr1);
                              QPixmap image("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/nerddead.png");
                              image= image.scaledToWidth(50);
                              image= image.scaledToHeight(50);
                          setPixmap(image);
                          }
                }

            }

QList<QGraphicsItem*> bullets = collidingItems();
       for (int i = 0; i < bullets.size(); i++)
       {
           if (typeid(*bullets[i]) == typeid(Bullet)){
               scene()->removeItem(bullets[i]);
               if(enemy1->gethealth()!=1)
                    enemy1->losehealth();
               else sptr->removeItem(enemy1);}
           if (typeid(*bullets[i])== typeid(Bullet)){
                   scene()->removeItem(bullets[i]);
                   if(enemy2->gethealth()!=1)
                       enemy2->losehealth();
                   else sptr ->removeItem(enemy2);}
           if (enemy1->gethealth()==0 && enemy2->gethealth()==0){
               win1->show();}
           }



         }
            //bullets disappearing when player touches them


void Player::empower(){
    QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuff.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
     count++;
}

int Player::gethealth(){
    return health;
}
bool Player::getstatus(){
    return alive;
}
void Player::setstatus(){
    alive = false;
}
int Player::decreasehealth(){
    return --health;
}
bool* Player::getcol(){
    return collision;
}
void Player::fixcol(){
    *collision = false;
}
void Player::collide(){
    *collision = true;
}
void Player::sethealth(int hp){
    health = hp;
}
