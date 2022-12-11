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
    QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/standing.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    // Set Position
    row = 6;
    column = 6;
    setPos(50 + column * 50, 50 + row * 50);
        sptr = sptrr;
        htprr1 = hptr1;
        htprr2 = hptr2;
        htprr3 = hptr3;
        enemy1 = ptrenemy1;
        enemy2 = ptrenemy2;
        vptr = viewptr;
        bul1 = b1;
        bul2 = b2;
        bul3 = b3;
        bul4=b4;
        pow1= pu1;
        pow2= pu2;
        //win = new WinLoss(true);
        //loss= new WinLoss(false);
        door = dr;
        timecount =4;
        timecount2 = 4;
        for (int f = 0; f < 5; f++){
            text[f]= new QGraphicsTextItem;
        }
    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];
    //set timer
    t = new QTimer(this);
    dt = new QTimer(this);
    powerupt = new QTimer(this);
    movingTimer = new QTimer(this);
    movingTimer->start(200);
    timer = new QTimer(this);
    shotTimer = new QTimer(this);
    enemyhurt = new QTimer(this);
//set music theme
    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/GTA/projectresourse/sound/gametheme2.mp3"));
    musicaudio->setVolume(5);
    music->setAudioOutput(musicaudio);
    music->play();
}
void Player::keyPressEvent(QKeyEvent* event)
{  QMediaPlayer *player = new QMediaPlayer;
     QAudioOutput *audioOutput = new QAudioOutput;
Pair enemy2pos= {enemy2->row, enemy2->column};
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
           player->setAudioOutput(audioOutput);
           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
           audioOutput->setVolume(50);
           player->play();
           column++;
           connect(movingTimer,SIGNAL(timeout()),this,SLOT(r()));
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    { // changing character model when moving to left
           player->setAudioOutput(audioOutput);
           player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/steps/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
           audioOutput->setVolume(50);
           player->play();
           column--;
           connect(movingTimer,SIGNAL(timeout()),this,SLOT(l()));
    }
    setPos(50 + column * 50, 50 + row * 50);
    Pair enemy1pos= {enemy1->row, enemy1->column};

    Pair pos = {row, column};

    if (enemy1->alive == true){
     enemy1->movingenemy(enemy1pos, pos);}

    if (enemy2->alive == true){
        enemy2->movingenemy(enemy2pos, pos);}
    //power up
   { QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(Powerup)){
                if (k ==0){
                dt->start(1000);
                connect(dt, SIGNAL(timeout()), this, SLOT(reducecount()));
                scene()->removeItem(items[i]);
                empower();
                powerupt->start(5000);
                powerupt->setSingleShot(true);
                connect(powerupt,SIGNAL(timeout()),this,SLOT(nopower()));
                k++;}
                else if (k==1){
                    dt->start(1000);
                    connect(dt, SIGNAL(timeout()), this, SLOT(reducecount2()));
                    scene()->removeItem(items[i]);
                    empower();
                    powerupt->start(5000);
                    powerupt->setSingleShot(true);
                    connect(powerupt,SIGNAL(timeout()),this,SLOT(nopower()));}
                }
            }}
        //losing health when touching enemy
   { QList<QGraphicsItem*> enemies = collidingItems();
         for (int i = 0; i < enemies.size(); i++)
            {
                if ((typeid(*enemies[i]) == typeid(Enemy1) || typeid(*enemies[i])== typeid(Enemy2)) && powered == false){
                          if (health==3)
                               {        
                                       health--;
                                       sptr->removeItem(htprr3);
                                       player->setAudioOutput(audioOutput);
                                       player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/Takedamagesound.mp3"));
                                       audioOutput->setVolume(50);
                                       player->play();
                                   resetpos();
                               }

                          else if (health == 2)
                               {
                                       health--;
                                       sptr->removeItem(htprr2);
                                       player->setAudioOutput(audioOutput);
                                       player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/Takedamagesound.mp3"));
                                       audioOutput->setVolume(50);
                                       player->play();
                                   resetpos();
                               }
                          else {
                                  health--;
                                  sethealth(decreasehealth());
                                  sptr->removeItem(htprr1);
                                  player->setAudioOutput(audioOutput);
                                  player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/Takedamagesound.mp3"));
                                  audioOutput->setVolume(50);
                                  player->play();
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
                              this->resetpos();
                }}
         }}
    int enemy1dis= ((enemy1->row- row) * (enemy1->row -row) + (enemy1->column- column) * (enemy1->column- column));
    int enemy2dis= ((enemy2->row- row) * (enemy2->row -row) + (enemy2->column- column) * (enemy2->column- column));
{QList<QGraphicsItem*> bullets = collidingItems();
       for (int i = 0; i < bullets.size(); i++)
       {
           if (typeid(*bullets[i])== typeid(Bullet)){
               scene()->removeItem(bullets[i]);
               if (enemy1->alive && enemy2->alive && enemy1dis == enemy2dis){
                   shotTimer->start(200);
                   connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                   timer->start(1000);
                   timer->setSingleShot(true);
                   connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                     enemy1->losehealth();
                     if (powered == true){
                         enemy1->alive = false;
                         sptr->removeItem(enemy1);
                     }}
                    else if(enemy1->alive == true && enemy2->alive == true){
                      if (enemy1dis < enemy2dis && enemy1->gethealth() > 1){
                        shotTimer->start(200);
                        connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                        timer->start(1000);
                        timer->setSingleShot(true);
                        connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                          enemy1->losehealth();
                          if (powered == true){
                              enemy1->alive = false;
                              sptr->removeItem(enemy1);
                          }
                          enemy1->hurt();
                          enemyhurt->start(500);
                          enemyhurt->setSingleShot(true);
                          connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy1norm()));
                      }
                      else if(enemy1dis < enemy2dis && enemy1->gethealth()==1){
                          shotTimer->start(200);
                          connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                          timer->start(1000);
                          timer->setSingleShot(true);
                          connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                          enemy1->losehealth();
                          enemy1->alive = false;
                          sptr->removeItem(enemy1);
                          if (powered == true){
                              enemy1->alive = false;
                              sptr->removeItem(enemy1);
                          }
                          enemy1->hurt();
                          enemyhurt->start(500);
                          enemyhurt->setSingleShot(true);
                          connect(enemyhurt,SIGNAL(timeout()),enemy1,SLOT(enemy1norm()));
                      }
                      else if(enemy1dis > enemy2dis && enemy2->gethealth()> 1){
                          shotTimer->start(200);
                          connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                          timer->start(1000);
                          timer->setSingleShot(true);
                          connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                              enemy2->losehealth();
                              if (powered == true){
                                  enemy2->alive = false;
                                  sptr->removeItem(enemy2);
                              }
                              enemy2->hurt();
                              enemyhurt->start(500);
                              enemyhurt->setSingleShot(true);
                              connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy2norm()));
                          }
                       else if(enemy1dis > enemy2dis && enemy2-> gethealth() ==1){
                          shotTimer->start(200);
                          connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                          timer->start(1000);
                          timer->setSingleShot(true);
                          connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                              enemy2->losehealth();
                              enemy2->alive = false;
                              sptr->removeItem(enemy2);
                              if (powered == true){
                                  enemy2->alive = false;
                                  sptr->removeItem(enemy2);
                              }
                              enemy2->hurt();
                              enemyhurt->start(500);
                              enemyhurt->setSingleShot(true);
                              connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy2norm()));
                          }
                  }
                      else if(enemy1->alive == true && enemy2->alive == false){
                          if (enemy1->gethealth()>1){
                              shotTimer->start(200);
                              connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                              timer->start(1000);
                              timer->setSingleShot(true);
                              connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                              enemy1->losehealth();
                              if (powered == true){
                                  enemy1->alive = false;
                                  sptr->removeItem(enemy1);
                                  sptr->addItem(door);
                                  sptr->removeItem(htprr1);
                                  sptr->removeItem(htprr2);
                                  sptr->removeItem(htprr3);
                              }
                              enemy1->hurt();
                              enemyhurt->start(500);
                              enemyhurt->setSingleShot(true);
                              connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy1norm()));
                          }
                              else if(enemy1->gethealth() == 1){
                                  shotTimer->start(200);
                                  connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                                  timer->start(1000);
                                  timer->setSingleShot(true);
                                  connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                                  enemy1->losehealth();
                                  enemy1->alive = false;
                                  sptr->removeItem(enemy1);
                                  sptr->addItem(door);
                                  sptr->removeItem(htprr1);
                                  sptr->removeItem(htprr2);
                                  sptr->removeItem(htprr3);
                                  if (powered == true){
                                      enemy1->alive = false;
                                      sptr->removeItem(enemy1);
                                      sptr->addItem(door);
                                      sptr->removeItem(htprr1);
                                      sptr->removeItem(htprr2);
                                      sptr->removeItem(htprr3);
                              }
                                  enemy1->hurt();
                                  enemyhurt->start(500);
                                  enemyhurt->setSingleShot(true);
                                  connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy1norm()));
                          }

                          }
                      else if(enemy2->alive == true && enemy1->alive == false){
                          if(enemy2->gethealth()>1) {
                              shotTimer->start(200);
                              connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                              timer->start(1000);
                              timer->setSingleShot(true);
                              connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                          enemy2->losehealth();
                          if (powered == true){
                              enemy2->alive = false;
                              sptr->removeItem(enemy2);
                              sptr->addItem(door);
                              sptr->removeItem(htprr1);
                              sptr->removeItem(htprr2);
                              sptr->removeItem(htprr3);
                          }
                          enemy2->hurt();
                          enemyhurt->start(500);
                          enemyhurt->setSingleShot(true);
                          connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy2norm()));
                          }
                          else if(enemy2->gethealth() == 1){
                              shotTimer->start(200);
                              connect(shotTimer,SIGNAL(timeout()),this,SLOT(shoot()));
                              timer->start(1000);
                              timer->setSingleShot(true);
                              connect(timer,SIGNAL(timeout()),this,SLOT(noshoot()));
                              enemy2->losehealth();
                              enemy2->alive = false;
                              sptr->removeItem(enemy2);
                              sptr->addItem(door);
                              sptr->removeItem(htprr1);
                              sptr->removeItem(htprr2);
                              sptr->removeItem(htprr3);
                              if (powered == true){
                                  enemy2->alive = false;
                                  sptr->removeItem(enemy2);
                                  sptr->addItem(door);
                                  sptr->removeItem(htprr1);
                                  sptr->removeItem(htprr2);
                                  sptr->removeItem(htprr3);
                              }
                              enemy2->hurt();
                              enemyhurt->start(500);
                              enemyhurt->setSingleShot(true);
                              connect(enemyhurt,SIGNAL(timeout()),this,SLOT(enemy2norm()));
                }
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

void Player::resetpos(){
    enemy1->reset_health();
    enemy2->reset_health();
    row = 6;
    column =6;
    setPos(50 + column * 50, 50 + row * 50);
    enemy1->set_column(6);
    enemy2->set_column(1);
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
    k=0;
    timecount = 4;
    timecount2= 4;
}

void Player::reducecount(){
    sptr->removeItem(text[i]);
    text[i] = sptr->addText(QString::number(timecount));
    text[i]->setDefaultTextColor(QColorConstants::White);
    text[i]->setPos(50+11*50, 50 +13 * 50);
    text[i]->setTextWidth(50);
    timecount--;
    if (timecount == -1){
        dt->stop();
        sptr->removeItem(text[i]);
        timecount = 4;
                i++;}
}
void Player::reducecount2(){
    sptr->removeItem(text[i]);
    text[i] = sptr->addText(QString::number(timecount2));
    text[i]->setDefaultTextColor(QColorConstants::White);
    text[i]->setPos(50+11*50, 50 +13 * 50);
    text[i]->setTextWidth(50);
    timecount2--;
    if (timecount2 == -1){
        dt->stop();
        sptr->removeItem(text[i]);
}
}
void Player::r(){
    if (x==1){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run1.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            setPixmap(image);
        }
        else
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun1.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            setPixmap(image);
        }
        x=2;
    }
    else if(x==2){
        if(!powered){
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run2.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            setPixmap(image);
        }
        else{
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun2.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            setPixmap(image);
        }
        x=3;
    }
    else if(x==3){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run3.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            setPixmap(image);
        }
        else
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun3.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            setPixmap(image);
        }
        x=4;
    }
    else if(x==4){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run4.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            setPixmap(image);
        }
        else
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun4.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            setPixmap(image);
        }
        x=5;
    }
    else if(x==5){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run5.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            setPixmap(image);
        }
        else
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun5.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            setPixmap(image);
        }
        x=6;
    }
    else{
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run6.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            setPixmap(image);
        }
        else
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun6.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            setPixmap(image);
        }
        x=1;
    }
}
void Player::l(){
    if (y==1){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run1.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        else{
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun1.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        y=2;
    }
    else if(y==2){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run2.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        else{
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun2.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        y=3;
    }
    else if(y==3){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run3.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        else{
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun3.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        y=4;
    }
    else if(y==4){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run4.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        else{
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun4.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        y=5;
    }
    else if(y==5){
        if(!powered)
        {
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run5.png");
            image=image.scaledToWidth(50);
            image=image.scaledToHeight(50);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        else{
            QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun5.png");
            image=image.scaledToWidth(60);
            image=image.scaledToHeight(60);
            QTransform tr;
            tr.scale(-1, 1);
            image=image.transformed(tr);
            setPixmap(image);
        }
        y=6;
    }
    else{
            if(!powered)
            {
                QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/run6.png");
                image=image.scaledToWidth(50);
                image=image.scaledToHeight(50);
                QTransform tr;
                tr.scale(-1, 1);
                image=image.transformed(tr);
                setPixmap(image);
            }
            else{
                QPixmap image("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Running/prun6.png");
                image=image.scaledToWidth(60);
                image=image.scaledToHeight(60);
                QTransform tr;
                tr.scale(-1, 1);
                image=image.transformed(tr);
                setPixmap(image);
            }
            y=1;
        }
    }
    void Player::shoot(){
        QMediaPlayer *player = new QMediaPlayer;
        QAudioOutput *audioOutput = new QAudioOutput;
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/normalshootsound.mp3"));
        audioOutput->setVolume(50);
        player->play();
        if(z==1){
            if(!powered)
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/att1.png");
                image=image.scaledToWidth(50);
                image=image.scaledToHeight(50);
                setPixmap(image);
            }
            else
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/patt1.png");
                image=image.scaledToWidth(60);
                image=image.scaledToHeight(60);
                setPixmap(image);
            }
            z=2;
        }
        else if(z==2){
            if(!powered)
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/att2.png");
                image=image.scaledToWidth(50);
                image=image.scaledToHeight(50);
                setPixmap(image);
            }
            else
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/patt2.png");
                image=image.scaledToWidth(60);
                image=image.scaledToHeight(60);
                setPixmap(image);
            }
            z=3;
        }
        else if(z==3){
            if(!powered)
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/att3.png");
                image=image.scaledToWidth(50);
                image=image.scaledToHeight(50);
                setPixmap(image);
            }
            else
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/patt3.png");
                image=image.scaledToWidth(60);
                image=image.scaledToHeight(60);
                setPixmap(image);
            }
            z=4;
        }
        else if(z==4){
            if(!powered)
            {
                QPixmap image ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/att4.png");
                image=image.scaledToWidth(50);
                image=image.scaledToHeight(50);
                setPixmap(image);
            }
            else{
                QPixmap image2 ("C:/Users/wifi/Downloads/Criminal Pixels/Criminal Pixels/Attack/patt4.png");
                image2=image2.scaledToWidth(50);
                image2=image2.scaledToHeight(50);
                setPixmap(image2);
            }
            z=1;
        }

    }
    void Player::noshoot(){
        shotTimer->stop();
    }
    void Player::nopower(){
        powered=false;
    }
    void Player::enemy1norm(){
        QPixmap image("C:/Users/wifi/Downloads/en1.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        enemy1->setPixmap(image);
    }
    void Player::enemy2norm(){
        QPixmap image("C:/Users/wifi/Downloads/en2.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        enemy2->setPixmap(image);
    }
