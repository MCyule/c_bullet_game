#include "dotenemy.h"
#include"component/animatedspritecomponent.h"
#include"globals.h"

DotEnemy::DotEnemy(Enemy *parent)
    : Enemy{parent}
{

    motion->speed = 300;

    sprite = new AnimatedSpriteComponent();
    sprite->append(new QPixmap(":/dotenemy"),4,"0");
    for(int i=1;i<17;i++){
        sprite->append(new QPixmap(":/" + QString::number(i)),1,QString::number(i));
    }
    sprite->append(new QPixmap(":/ene2"),1,"boss");
    sprite->setScale(4);
    sprite->name = "rect_component";
    sprite->play("0");

    addComponent(sprite);

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
