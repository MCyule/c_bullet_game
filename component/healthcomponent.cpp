#include "healthcomponent.h"

#include <Globals.h>

HealthComponent::HealthComponent(Component *parent)
    : Component{"HealthComponent",parent},isEnemy(false),health(1),attack(0),couldAttack(false),couldHurt(false),touchArea(new QVector2D()),attackArea(new QVector2D())
{}


void HealthComponent::update(int delta){
    Component::update(delta);
    if(health < 0){
        if(dynamic_cast<GameObject*>(parent())->isAlive){
            //dynamic_cast<GameObject*>(parent())->isAlive = false;
            emit dynamic_cast<GameObject*>(parent())->died();
        }
        return;
    }
    if(cooldownTime > 0){
        cooldownTime -= delta;
        return;
    }
    if(layer[1]){
        Player* player = Globals::instance()->player;
        if(player->healthComponent != nullptr && player->healthComponent->couldHurt && couldAttack){
            if(attackCollide(player->healthComponent)){
                player->healthComponent->takeDamage(attack);
                cooldownTime = maxCooldownTime;
                emit collied();
            }
        }
    }
    if(layer[2] && couldAttack){
        QList<Enemy*> *enemys  = Globals::instance()->window->enemys;
        for(int i=0;i<enemys->size();i++){
            if(attackCollide(enemys->at(i)->healthComponent) && enemys->at(i)->isAlive){
                enemys->at(i)->healthComponent->takeDamage(attack);
                emit collied();
            }
        }
    }
}


bool HealthComponent::hurtCollide(HealthComponent* target){
    QRect rect1 = QRect(global_position().x(),global_position().y(),touchArea->x(),touchArea->y());
    QRect rect2 = QRect(target->global_position().x(),target->global_position().y(),target->touchArea->x(),target->touchArea->y());
    return rect1.intersects(rect2);
}

bool HealthComponent::attackCollide(HealthComponent* target){
    QRect rect1 = QRect(global_position().x(),global_position().y(),attackArea->x(),attackArea->y());
    QRect rect2 = QRect(target->global_position().x(),target->global_position().y(),target->touchArea->x(),target->touchArea->y());
    return rect1.intersects(rect2);
}

void HealthComponent::takeDamage(int damage){
    health -= damage;
    emit healthChanged(health);
}

HealthComponent::~HealthComponent(){
    delete touchArea;
    delete attackArea;
}
