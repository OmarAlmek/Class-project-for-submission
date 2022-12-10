#include "player.h"
#include "qobjectdefs.h"
#include <QDebug>


Player::Player(int boardData[12][12], Enemy1* ptrenemy1, Enemy2 *ptrenemy2, Powerup* fptr, QGraphicsScene *sptrr,
Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *viewptr,
Bullet *b1, Bullet *b2, Bullet *b3, Bullet *b4, Powerup* pu1, Powerup *pu2, Door* dr, WinWindow*w,LossWindow*l)
{
    w1=w;
    l1=l;
    health = 3;
    // Set Image
    QPixmap image("C:/Users/wifi/Downloads/My project-1(1).png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
    row = 6;
    column = 6;
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
        //win = new WinLoss(true);
        //loss= new WinLoss(false);
        door = dr;
        timecount =5;
        for (int f = 0; f < 5; f++){
            text[i]= new QGraphicsTextItem;
        }
    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set timer
t= new QTimer(this);
dt= new QTimer(this);
et= new QTimer(this);
e2t = new QTimer (this);
//set music theme
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/sound/gametheme2.mp3"));
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
    Pair pos = {row, column};
    Pair enemy1pos= {enemy1->row, enemy1->column};
    Pair enemy2pos= {enemy2->row, enemy2->column};
//    if (enemy1->alive == true){
//       enemy1->movingenemy(enemy1pos, pos);}

    if (enemy2->alive == true){
        enemy2->movingenemy(enemy2pos, pos);}
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
                if ((typeid(*enemies[i]) == typeid(Enemy1) || typeid(*enemies[i])== typeid(Enemy2)) && powered == false){

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
                              this->resetpos();
                              this->health=3;
                              sptr->addItem(htprr1);
                              sptr->addItem(htprr2);
                              sptr->addItem(htprr3);
                              vptr->hide();
                              music->stop();
                              l1->show();
                              music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/losesound.mp3"));
                              musicaudio->setVolume(50);
                              music->setAudioOutput(musicaudio);
                              music->play();
                }
         }}}

    int enemy1dis= ((enemy1->row- row) * (enemy1->row -row) + (enemy1->column- column) * (enemy1->column- column));
    int enemy2dis= ((enemy2->row- row) * (enemy2->row -row) + (enemy2->column- column) * (enemy2->column- column));
{QList<QGraphicsItem*> bullets = collidingItems();
       for (int i = 0; i < bullets.size(); i++)
       {
           if (typeid(*bullets[i])== typeid(Bullet)){
               scene()->removeItem(bullets[i]);
                  if(enemy1->alive == true){
                      if (enemy1dis < enemy2dis && enemy1->gethealth() > 1){
                          shoot();
                          t->start(500);
                          t->setSingleShot(true);
                          connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                          enemy1->losehealth();
                          if (powered == true){
                              shootpower();
                              t->start(500);
                              t->setSingleShot(true);
                              connect(t, SIGNAL(timeout()),this, SLOT (norm()));
                              enemy1->alive = false;
                              sptr->removeitem(enemy1);
                          }

                      }
                      else if(enemy1dis < enemy2dis && enemy1->gethealth()==1){
                          shoot();
                          t->start(500);
                          t->setSingleShot(true);
                          connect(t, SIGNAL(timeout()), this, SLOT (norm()));
                          enemy1->losehealth();
                          enemy1->alove = false;
                          sptr->removeItem(enemy1);
                      }
                  }
       }
    }

    { QList<QGraphicsItem*> doorc = collidingItems();
         for (int i = 0; i < doorc.size(); i++)
         {
             if (typeid(*doorc[i]) == typeid(Door)){
                 this->health=3;
                 sptr->addItem(htprr1);
                 sptr->addItem(htprr2);
                 sptr->addItem(htprr3);
                 sptr->removeItem(door);
                 this->resetpos();
                 vptr->hide();
                 music->stop();
                 w1->show();
                 music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/winsound.mp3"));
                 musicaudio->setVolume(50);
                 music->setAudioOutput(musicaudio);
                 music->play();
                 }
         }}
}

void Player::empower(){
    i=0;
    timecount = 5;
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
    dt->start(1000);
    dt->setSingleShot(false);
    connect(dt, SIGNAL(timeout()), this, SLOT (reducecount()));
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
    row = 6;
    column =6;
    setPos(50 + column * 50, 50 + row * 50);
    enemy1->set_column(6);
    enemy2->set_column(5);
    enemy1->set_row(10);
    enemy2->set_row(10);
    enemy1->setPos(50 + 6 * 50, 50 + 10 * 50);
    enemy2->setPos(50 + 1 *50, 50+ 10 * 50 );
    sptr->addItem(enemy1);
    sptr->addItem(enemy2);
    sptr->addItem(bul1);
    sptr->addItem(bul2);
    sptr->addItem(bul3);
    sptr->addItem(bul4);
    sptr->addItem(pow1);
    sptr->addItem(pow2); 
    nopower();
    enemy1->alive = true;
    enemy2->alive = true;
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
void Player::reducecount(){
    sptr->removeItem(text[i]);
    text[i] = sptr->addText(QString::number(timecount));
    text[i]->setDefaultTextColor(QColorConstants::White);
    text[i]->setPos(50+11*50, 50 +13 * 50);
    text[i]->setTextWidth(50);
    timecount--;
    if (timecount ==-1){
        dt->stop();}
}

/*void Player::resetGame(int boardData[12][12], Enemy1* ptrenemy1, Enemy2 *ptrenemy2, QGraphicsScene *sptrr,
Health* hptr1,Health* hptr2, Health* hptr3,QGraphicsView *viewptr,
Bullet *b1, Bullet *b2, Bullet *b3, Bullet *b4, Powerup* pu1, Powerup *pu2, Door* dr){
    this->resetpos();
    health = 3;
    // Set Image
    QPixmap image("C:/Users/wifi/Downloads/My project-1(1).png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
    row = 6;
    column = 6;
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
        door = dr;
        timecount =5;
        for (int f = 0; f < 5; f++){
            text[i]= new QGraphicsTextItem;
        }
    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set timer
t= new QTimer(this);
dt= new QTimer(this);

//set music theme
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/sound/gametheme2.mp3"));
    musicaudio->setVolume(5);
    music->setAudioOutput(musicaudio);
    music->play();
}*/
