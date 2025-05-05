#include "normalprojectile.h"
#include"globals.h"
NormalProjectile::NormalProjectile(Projectile *parent)
    : Projectile{parent}
{


}

void NormalProjectile::loadRes(const ProjectileConfig* res)
{
    Projectile::loadRes(res);
    if (!res) {
        return;
    }
}

void NormalProjectile::update(int delta)
{
    if(!shouldUpdate)
        return;
    if(preparedTime >0){
        preparedTime -= delta;
        return;
    }
    Projectile::update(delta);
    if (!isAlive) {
        return;
    }
    //qDebug()<<"motion类型<"<<(motionpath->metaObject()->className());
}

void NormalProjectile::onDeath(bool isHit)
{
    Projectile::onDeath(isHit);
    if (!spells[3]) {
        return;
    }
    if (spells[3]->spellType == 0) {
        spells[3]->release(Globals::instance()->generateRandomUnitVector(),position,100);
    }
}

void NormalProjectile::onHitEnemy()
{
    Projectile::onHitEnemy();
    if (!spells[0]) {
        return;
    }
    if (spells[0]->spellType == 0) {
        spells[0]->release(Globals::instance()->generateRandomUnitVector(),position,100);
        //qDebug()<<"触发子法术";
    }
}

void NormalProjectile::onTriggerTimeTimeout()
{
    Projectile::onTriggerTimeTimeout();
    if (triggerCount != 1 ||spells[1] == nullptr) {
        return;
    }
    if (spells[1]->spellType == 0) {
        spells[1]->release(Globals::instance()->generateRandomUnitVector(),position,100);
    }
}
