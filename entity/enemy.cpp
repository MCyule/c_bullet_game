#include "enemy.h"
#include "gameobject.h"
#include"globals.h"

Enemy::Enemy(GameObject *parent)
    : GameObject{parent},motion(new MotionComponent()),healthComponent(new HealthComponent())
{
    healthComponent->isEnemy = true;
    healthComponent->health = 10;
    healthComponent->attack = 5;
    healthComponent->couldAttack = true;
    healthComponent->couldHurt = true;
    healthComponent->layer[1] = 1;

    addComponent(motion);
    addComponent(healthComponent);
    connect(this,&GameObject::died,this,[this](){
        healthComponent->couldAttack = false;
        Globals::instance()->window->freeList->append(new FreeTimer(this,10));
    });
}

void Enemy::run(){}


Enemy::~Enemy(){
   // healthComponent->deleteLater();
    //motion->deleteLater();
}
