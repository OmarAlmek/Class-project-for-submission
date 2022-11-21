#include "player.h"
#include "qobjectdefs.h"
#include <QDebug>


Player::Player(int boardData[12][12], Enemy1* ptrenemy1, Enemy2 *ptrenemy2, Powerup* fptr, QGraphicsScene *sptrr , Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *viewptr)
{
    health = 3;
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
        vptr= viewptr;

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set timer
t= new QTimer(this);

//set music theme
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/Downloads/Mission Impossible Theme (Full Theme).mp3"));
    musicaudio->setVolume(5);
    music->setAudioOutput(musicaudio);
    music->play();

   }
void Player::keyPressEvent(QKeyEvent* event)
{  QMediaPlayer *player = new QMediaPlayer;
     QAudioOutput *audioOutput = new QAudioOutput;
     enemy1->movingenemy();
     enemy2->movingenemy();
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
        if (powered != true){
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
        if (powered == true){
            QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuff.png");
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
    }}
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    { // changing character model when moving to left
         if (powered != true){
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
         if (powered == true){
             QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuff.png");
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
    }
    setPos(50 + column * 50, 50 + row * 50);

    //power up
   { QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(Powerup)){
                scene()->removeItem(items[i]);
                powered=true;
                time();
                }
        }}
        //losing health when touching enemy
   { QList<QGraphicsItem*> enemies = collidingItems();
         for (int i = 0; i < enemies.size(); i++)
            {
                if (typeid(*enemies[i]) == typeid(Enemy1) || typeid(*enemies[i])== typeid(Enemy2)){

                    sethealth(decreasehealth());
                          if ( health==2)
                               {
                                   sptr->removeItem(htprr3);
                                //resetpos();
                               }

                          else if (health == 1)
                               {
                                   sptr->removeItem(htprr2);
                                  //  resetpos();
                               }
                          else {
                              sptr->removeItem(htprr1);
                              QPixmap image("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/nerddead.png");
                              image= image.scaledToWidth(50);
                              image= image.scaledToHeight(50);
                          setPixmap(image);
                }
         }}}

{QList<QGraphicsItem*> bullets = collidingItems();
       for (int i = 0; i < bullets.size(); i++)
       {
           if (typeid(*bullets[i]) == typeid(Bullet)){
               scene()->removeItem(bullets[i]);
               if(enemy1->gethealth()!=1){
                    enemy1->losehealth();
                    if(powered == true){
                        sptr->removeItem(enemy1);
                    }
                    }
               else sptr->removeItem(enemy1);}
           if (typeid(*bullets[i])== typeid(Bullet)){
                   scene()->removeItem(bullets[i]);
                   if(enemy2->gethealth()!=1){
                       enemy2->losehealth();
                   if(powered == true){
                       sptr->removeItem(enemy2);
                   }}
                   else sptr ->removeItem(enemy2);}
           }
         }}
            //bullets disappearing when player touches them


void Player::empower(){
    QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuff.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    powered=true;
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
void Player::sethealth(int hp){
    health = hp;
}

void Player::time(){
      empower();
t->start(5000);
t->setSingleShot(true);
connect(t, SIGNAL(timeout()), this, SLOT (nopower()));
}
void Player::nopower(){
    QPixmap image ("C:/Users/wifi/Downloads/My project-1(1).png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    powered = false;
}
void Player::resetpos(){
    this->setPos(50 + 5 * 50, 50 + 5 * 50);
    enemy1->setPos(50 + 10 * 50, 50 + 6 * 50);
    enemy2->setPos(50 + 10 *50, 50+ 5 * 50 );
    sptr->addItem(enemy1);
    sptr->addItem(enemy2);
    //i stopped here
}
