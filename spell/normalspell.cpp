#include "normalspell.h"
#include "qvectornd.h"
#include "spell/normalprojectile.h"
#include "spell/spell.h"
#include"globals.h"

NormalSpell::NormalSpell(Spell *parent)
    : Spell{parent}
    ,motions(new MotionPath(this))
{
    spellType = 0;
}
void NormalSpell::release(QVector2D dir,QVector2D pos,int prepareTime){
    Spell::release(dir,pos,prepareTime);
    if(projectile_amount <= 0){
        return;
    }
    //qDebug()<<"子弹位置"<<pos;
    release_projectile(dir,pos,projectile_amount,prepareTime);
}

void NormalSpell::release_projectile(QVector2D dir,QVector2D pos ,int amount,int pre){
    qreal shoot_offset_angle = -((projectile_amount-1)*recover_angle)/2;
    int toward = dir.x() >= 0 ? 1 : -1;
    NormalProjectile *projectile ;
    for(int index =0;index<amount;index++){
        projectile = new NormalProjectile();
        projectile->preparedTime = pre;
        if(motions != nullptr)
            motions->copy(projectile->motionpath);
        // 处理子弹散射
        // 处理子弹散射
        projectile->startDir = Globals::rotated(dir,toward * shoot_offset_angle);
                             //.rotated(randf_range(-emit_angle,emit_angle));
        //qDebug()<<"子弹方向"<<projectile->startDir;
       projectile->setup(projectileConfig,pos,projectile->startDir,trigger_spells);
       projectile->shoot();
    Globals::instance()->window->objects->append(projectile);
    //qDebug()<<"发射";
    // 角度修正
        if(!is_child_spell)
            shoot_offset_angle += recover_angle;
        else
            shoot_offset_angle += 3.14159 * 2 / amount;
    }
}
