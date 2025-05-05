#include "dotenemy.h"
#include"component/animatedspritecomponent.h"
#include"globals.h"

DotEnemy::DotEnemy(Enemy *parent)
    : Enemy{parent}
{

    motion->speed = 300;

    AnimatedSpriteComponent *body = new AnimatedSpriteComponent();
    body->append(new QPixmap(":/dotenemy"),4,"dotenemy");
    body->setScale(4);
    body->name = "rect_component";
    body->play("dotenemy");

    addComponent(body);

    healthComponent->touchArea = new QVector2D(64,64);
    healthComponent->attackArea = new QVector2D(81,81);

}

void DotEnemy::run(){
    Enemy::run();
    motion->direction = QVector2D(Globals::instance()->centerPos.x() - position.x(),Globals::instance()->centerPos.y()-position.y());
}

void DotEnemy::update(int delta){
    GameObject::update(delta);
    if(QVector2D(position.x()-Globals::centerPos.x(),position.y()-Globals::centerPos.y()).length() <= 150){
        motion->speed = 0;
    }

}


DotEnemy::~DotEnemy(){

}
