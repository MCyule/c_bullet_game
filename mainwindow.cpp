#include "mainwindow.h"
#include "entity/card.h"
#include "entity/dotenemy.h"
#include "scene/hud.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QTimer>
#include"globals.h"

#include"entity/player.h"
#include<QLabel>
#include<QMovie>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,freeList(new QList<FreeTimer*>())
    ,objects (new QVector<GameObject*>())
    ,enemys(new QVector<Enemy*>)
    ,timer(new QTimer(this))
    ,scene(new QGraphicsScene(this))
    ,view(new GameView(scene,this))
    ,hud(new HUD(this))
   ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Globals::instance()->window = this;
    setCentralWidget(view);

    //模拟帧
    timer->setInterval(17);
    timer->setTimerType(Qt::TimerType::PreciseTimer);
    connect(timer,&QTimer::timeout,this,&MainWindow::update_world);

    Player *player = new Player();



    Globals::instance()->setplayer(player);
    objects->append(player);
    timer->start();
}


void MainWindow::update_world(){
    //qDebug()<<enemys->size();
    scene->update();
    if(objects->size()==0) return;
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) != nullptr && objects->at(i)->isAlive){
            objects->at(i)->update(17);
            continue;
        }
    }
   spawn();
    for(int i =0;i<freeList->size();i++){
        freeList->at(i)->time -= 17;
        if(freeList->at(i)->time <= 0 && freeList->at(i)->obj != nullptr && freeList->at(i)->obj->isAlive){
            freeList->at(i)->obj->isAlive = false;
            freeList->at(i)->obj->deleteLater();
        }
    }
    objects->erase(
        std::remove_if(objects->begin(),objects->end(),[](const auto &obj){
            return obj == nullptr || !obj->isAlive;
        }),objects->end());
    enemys->erase(
        std::remove_if(enemys->begin(),enemys->end(),[](const auto &obj){
            return obj == nullptr || !obj->isAlive;
        }),enemys->end());
    freeList->erase(
        std::remove_if(freeList->begin(),freeList->end(),[](const auto &timer){
            return timer == nullptr || timer->time <= 0 || timer->obj == nullptr || !timer->obj->isAlive;
        }),freeList->end());
}

int k=0;

void MainWindow::spawn(){
    k+=17;
    if(k<= 1000){
        return;
    }
    k=0;
    DotEnemy* dot = new DotEnemy();
    connect(dot,&GameObject::died,this,[](){
        Globals::instance()->player->setMana(Globals::instance()->player->mana + 20);
    });
    dot->position = Globals::randomPoitOutside();
    objects->append(dot);
    enemys->append(dot);
    dot->run();
}

void MainWindow::spawnCard(){
    if(cardIndex >= 13){
        cardIndex = 0;
    }
    Card *card1 = new Card();
    card1->id = cardIndex;
    card1->position = QVector2D(-100,150);
    card1->motion->direction = QVector2D(1,0);
    card1->motion->speed = 200;
    objects->append(card1);
    enemys->append(card1);
    freeList->append(new FreeTimer(card1,16000));
    cardIndex++;
    card1 = new Card();
    card1->id = cardIndex;
    card1->position = QVector2D(1600,800);
    card1->motion->direction = QVector2D(-1,0);
    card1->motion->speed = 200;
    objects->append(card1);
    enemys->append(card1);
    freeList->append(new FreeTimer(card1,16000));
    cardIndex++;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objects;
}

