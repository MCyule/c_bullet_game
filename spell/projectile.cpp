#include "projectile.h"
#include "component/animatedspritecomponent.h"
#include "gameobject.h"
#include "globals.h"
#include "qdatetime.h"


Projectile::Projectile(GameObject *parent)
    : GameObject{parent}
    ,motion(new MotionComponent())
    ,sprite(new AnimatedSpriteComponent())
    ,healthComponent(new HealthComponent())
    ,motionpath(new MotionPath(this))
{

    healthComponent->health = 600;
    healthComponent->couldHurt = false;
    healthComponent->attackArea = new QVector2D(16,16);
    healthComponent->layer[2] = 1;
    connect(healthComponent,&HealthComponent::collied,this,[this](){
        onHitEnemy();
    });

    sprite->append(new QPixmap(":/bullet"),1,"bullet");
    sprite->name = "bullet_component";
    sprite->play("bullet",4);
    sprite->append(new QPixmap(":/arrow_bullet"),1,"arrow_bullet");
    sprite->append(new QPixmap(":/little_bullet"),1,"little_bullet");
    sprite->append(new QPixmap(":/circle_bullet"),1,"circle_bullet");
    sprite->append(new QPixmap(":/hurt_bullet"),1,"hurt_bullet");
    sprite->append(new QPixmap(":/auto_bullet1"),1,"auto1");
    sprite->append(new QPixmap(":/auto_bullet2"),1,"auto2");


    addComponent(motion);
    addComponent(sprite);
    addComponent(healthComponent);
    connect(healthComponent,&HealthComponent::collied,this,[this](){
        Globals::instance()->window->freeList->append(new FreeTimer(this,0));
    });

}
void Projectile::loadRes(const ProjectileConfig* res)
{
    if (!res) {
        return;
    }
    shootSpeed = res->shootSpeed;
    maxLifetime = res->maxLifetime;
    healthComponent->attack = res->attackPower;
    healthComponent->couldAttack = healthComponent->attack != 0;
    damp = res->damp;
    passCount = res->passCount;
    if(res->aniScale != -1 && res->aniName != ""){
        sprite->play(res->aniName,res->aniScale);
    }
}

void Projectile::setup(const ProjectileConfig* res, const QVector2D& start, const QVector2D& oriDirection, Spell** triggerSpells)
{
    loadRes(res);
    startDir = oriDirection;
    motion->startDirection = startDir;
    position = start;
    isAlive = true;
    for (int i=0;i<4;i++) {
        spells.append(triggerSpells[i]);
    }
    emit setuped();
}

void Projectile::shoot()
{
    isShooted = true;
    triggerTime = QTime::currentTime().msecsSinceStartOfDay();
    motion->speed = shootSpeed;
    motion->direction = startDir;
    emit shooted();
}

void Projectile::update(int delta)
{
    if(!shouldUpdate)
        return;
    if(preparedTime >0){
        preparedTime -= delta;
        return;
    }
    GameObject::update(delta);
    if (!isAlive) {
        return;
    }
    int currentTime = QTime::currentTime().msecsSinceStartOfDay();
    maxLifetime -= delta;
    if (maxLifetime <0) {
        onLifetimeTimeout();
        return;
    }
    if (currentTime - triggerTime >= maxTriggerTime) {
        if (triggerCount <= 3) {
            onTriggerTimeTimeout();
        }
        triggerTime = currentTime;
        triggerCount++;
    }
    if (motionpath != nullptr) {
       motionpath->update(motion, delta);
    }
    //qDebug()<<"能否攻击："<<healthComponent->couldAttack;
}

void Projectile::onHitEnemy()
{
    // 空实现
}

void Projectile::onTriggerTimeTimeout()
{
    //qDebug()<<"触发时间";
    // 空实现
}

void Projectile::onDeath(bool)
{
    // 空实现
}
void Projectile::onLifetimeTimeout(){
    Globals::instance()->window->freeList->append(new FreeTimer(this,0));
    onDeath(false);
    shouldUpdate = false;
    //qDebug()<<"死亡";
}


void Projectile::dealDeath()
{
    if (!isAlive) {
        return;
    }
    //isAlive = false;
}
Projectile::~Projectile(){
    spells.clear();
    delete motionpath;
}
