#include "gameview.h"
#include "qevent.h"
#include"globals.h"

GameView::GameView(QGraphicsScene *scene,QWidget *parent)
    : QGraphicsView(scene,parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFocusPolicy(Qt::StrongFocus);
    //初始化屏幕
    scene->setSceneRect(0,0,4096,4096);
    Globals::instance()->game_scene = scene;
    Globals::instance()->game_view = this;
    // 始终获取鼠标
    setMouseTracking(true);
    // 中心位置
    setBackgroundBrush(Qt::black);
}

void GameView::mouseMoveEvent(QMouseEvent* event){
    Globals::instance()->mousePos = event->pos();
    //qDebug()<< event->pos();
}


void GameView::mousePressEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
       // Globals::instance()->player->shoot();
    }
}
void GameView::keyPressEvent(QKeyEvent*event){
    if(event->key()==Qt::Key_K){
        Globals::instance()->player->shoot();
    }
}
void GameView::keyReleaseEvent(QKeyEvent*event){
    if(event->key()==Qt::Key_K){
        Globals::instance()->player->cancelShoot();
    }
}
