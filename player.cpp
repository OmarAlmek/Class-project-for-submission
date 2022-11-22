#include "player.h"
#include "qobjectdefs.h"
#include <QDebug>


Player::Player(int boardData[12][12], Enemy1* ptrenemy1, Enemy2 *ptrenemy2, Powerup* fptr, QGraphicsScene *sptrr,
Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *viewptr, Bullet *b1, Bullet *b2, Bullet *b3, Bullet *b4, Powerup* pu1, Powerup *pu2)
{
    health = 3;
    // Set Image
    QPixmap image("C:/Users/wifi/Downloads/My project-1(1).png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
    row = 7;
    column = 4;
    setPos(50 + column * 50, 50 + row * 50);
        sptr = sptrr;
        htprr1 =hptr1;
        htprr2 = hptr2;
        htprr3 = hptr3;
        enemy1 = ptrenemy1;
        enemy2 = ptrenemy2;
        vptr= viewptr;
        bul1=b1;
        bul2=b2;
        bul3=b3;
        bul4=b4;
        pow1= pu1;
        pow2= pu2;
        win = new WinLoss(true);
        loss= new WinLoss(false);

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set timer
t= new QTimer(this);

//set music theme
    music->setSource(QUrl::fromLocalFile("file:///C:/Users/wifi/OneDrive/Documents/projectresourse/sound/gametheme.mp3"));
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
        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net)(1).mp3"));
        audioOutput->setVolume(50);
        player->play();
//move the player
        row--;

    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
    {
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net)(2).mp3"));
        audioOutput->setVolume(50);
        player->play();
        row++;
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
    { // changing character model when moving to right
        if (powered != true){
            QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/nerddefault.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        QTransform tr;
            tr.scale(1, 1);
          image= image.transformed(tr);
           setPixmap(image);
           player->setAudioOutput(audioOutput);
           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
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
               player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
               audioOutput->setVolume(50);
               player->play();
            column++;
    }}
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    { // changing character model when moving to left
         if (powered != true){
        QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/nerddefault.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        QTransform tr;
            tr.scale(-1, 1);
          image= image.transformed(tr);
           setPixmap(image);
           player->setAudioOutput(audioOutput);
           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
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
                player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
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
                                   player->setAudioOutput(audioOutput);
                                   player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/Takedamagesound.mp3"));
                                   audioOutput->setVolume(50);
                                   player->play();
                                resetpos();
                               }

                          else if (health == 1)
                               {
                                   sptr->removeItem(htprr2);
                                   player->setAudioOutput(audioOutput);
                                   player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/Takedamagesound.mp3"));
                                   audioOutput->setVolume(50);
                                   player->play();
                                 resetpos();
                               }
                          else {
                              sptr->removeItem(htprr1);
                              player->setAudioOutput(audioOutput);
                              player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/Takedamagesound.mp3"));
                              audioOutput->setVolume(50);
                              player->play();
                              sptr->addItem(loss);
                              music->stop();
                              player->setAudioOutput(audioOutput);
                              player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/losesound.mp3"));
                              audioOutput->setVolume(50);
                              player->play();
                }
         }}}

{QList<QGraphicsItem*> bullets = collidingItems();
       for (int i = 0; i < bullets.size(); i++)
       {
           if (typeid(*bullets[i]) == typeid(Bullet) && enemy1->alive==true){
               shoot();
               t->start(500);
               t->setSingleShot(true);
               connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                scene()->removeItem(bullets[i]);
                    if(enemy1->gethealth()!=1){
                        enemy1->losehealth();
                        if(powered == true){
                            shootpower();
                            t->start(500);
                            t->setSingleShot(true);
                            connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                            sptr->removeItem(enemy1);
                            enemy1->alive=false;
                            enemy1->losehealth();
                            enemy1->losehealth();
//                            sptr->addItem(win);
                        }
                    }
                    else {
                        sptr->removeItem(enemy1);
                        enemy1->alive=false;
                        }
            }
           else
           {
               if (typeid(*bullets[i])== typeid(Bullet))
               {
                   shoot();
                   t->start(500);
                   t->setSingleShot(true);
                   connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                   QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdshootnobuff.png");
                   image = image.scaledToWidth(50);
                   image = image.scaledToHeight(50);
                   setPixmap(image);
                   scene()->removeItem(bullets[i]);
                   if(enemy2->gethealth()!=1)
                   {
                       shoot();
                       t->start(500);
                       t->setSingleShot(true);
                       connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                       enemy2->losehealth();
                       if(powered == true)
                       {                        shootpower();
                           t->start(500);
                           t->setSingleShot(true);
                           connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                           sptr->removeItem(enemy2);
                           enemy2->losehealth();
                           enemy2->losehealth();
                           sptr->addItem(win);
                           music->stop();
                           player->setAudioOutput(audioOutput);
                           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/winsound.mp3"));
                           audioOutput->setVolume(50);
                           player->play();
                       }
                   }
                   else
                   {
                       shootpower();
                       t->start(500);
                       t->setSingleShot(true);
                       connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                       music->stop();
                       player->setAudioOutput(audioOutput);
                       player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/winsound.mp3"));
                       audioOutput->setVolume(50);
                       player->play();
                       sptr ->removeItem(enemy2);
                       sptr->addItem(win);
                       sptr->removeItem(htprr1);
                       sptr->removeItem(htprr2);
                       sptr->removeItem(htprr3);
                   }
               }
           }
        }
    }
}


void Player::empower(){
    QMediaPlayer *player = new QMediaPlayer;
         QAudioOutput *audioOutput = new QAudioOutput;
    QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuff.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/reloadsound.mp3"));
    audioOutput->setVolume(50);
    player->play();
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
    QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerddefault.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    powered = false;
}
void Player::resetpos(){
    enemy1->reset_health();
    enemy2->reset_health();
    row = 7;
    column =4;
    setPos(50 + column * 50, 50 + row * 50);
    enemy1->set_column(6);
    enemy2->set_column(5);
    enemy1->set_row(10);
    enemy2->set_row(10);
    enemy1->setPos(50 + 6 * 50, 50 + 10 * 50);
    enemy2->setPos(50 + 5 *50, 50+ 10 * 50 );
    sptr->addItem(enemy1);
    sptr->addItem(enemy2);
    sptr->addItem(bul1);
    sptr->addItem(bul2);
    sptr->addItem(bul3);
    sptr->addItem(bul4);
    sptr->addItem(pow1);
    sptr->addItem(pow2); 
}
void Player::shoot(){
    QMediaPlayer *player = new QMediaPlayer;
         QAudioOutput *audioOutput = new QAudioOutput;
    QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdshootnobuff.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/normalshootsound.mp3"));
    audioOutput->setVolume(50);
    player->play();
}
void Player::shootpower(){
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    QPixmap image ("C:/Users/wifi/OneDrive/Documents/projectresourse/nerdbuffshoot.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/powershotsound.mp3"));
    audioOutput->setVolume(50);
    player->play();
}
void Player::norm(){
    QPixmap image("C:/Users/wifi/OneDrive/Documents/projectresourse/nerddefault.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
}
