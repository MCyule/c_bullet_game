#include "player.h"
#include"gameobject.h"
#include"component/motioncomponent.h"
#include<globals.h>
#include"component/animatedspritecomponent.h"

Player::Player(GameObject *parent)
    : GameObject{parent},
    smile(new AnimatedSpriteComponent())
    , eye(new AnimatedSpriteComponent())
    ,body(new AnimatedSpriteComponent())
    ,consumeTimer(new QTimer(this))
    ,hurtTimer(new QTimer())
    ,healthComponent(new HealthComponent())
    ,spell(new NormalSpell())
    ,hurtSpell(new NormalSpell())
    ,autoSpell1(new NormalSpell())
    ,autoSpell2(new NormalSpell())
{
    consumeTimer->setInterval(100);
    connect(consumeTimer,&QTimer::timeout,this,[this](){
        if(!isShotting)
            setMana(mana+1);
        if(recoverHealth)
            healthComponent->health+=1;
    });
    hurtTimer->setInterval(500);
    hurtTimer->setSingleShot(true);
    connect(hurtTimer,&QTimer::timeout,this,[this](){
        healthComponent->couldHurt = true;
    });
    connect(healthComponent,&HealthComponent::healthChanged,this,[this](int hurt){
        if(hurt<=0){
            return;
        }
        if(hasInvinTime){
            healthComponent->couldHurt = false;
        }
        if(hasHurtSpell){
            hurtSpell->release(QVector2D(1,0),position);
        }
        hurtTimer->start();
    });
    MotionComponent *motionComponent= new MotionComponent();

    body->append(new QPixmap(":/rect"),1,"rect");
    body->setScale(6);
    body->name = "rect_component";
    body->setRotation(0);
    body->play("rect");

    eye->append(new QPixmap(":/shark"),1,"shark");
    eye->append(new QPixmap(":/eyes"),1,"eyes");
    eye->setScale(6);
    eye->setRotation(0);
    eye->play("eyes");
    eye->name = "eye_component";


    smile->append(new QPixmap(":/smile"),1,"smile");
    smile->setScale(6);
    smile->setRotation(0);
    smile->play("smile");
    smile->append(new QPixmap(":/mouse"),1,"mouse");
    smile->setScale(6);
    smile->setRotation(0);


    healthComponent->health = 10000;
    healthComponent->couldHurt = true;
    healthComponent->couldAttack = false;
    healthComponent->touchArea = new QVector2D(256,256);
    healthComponent->attackArea = new QVector2D(300,300);
    healthComponent->layer[0] = 1;


    addComponent(motionComponent);
    addComponent(body);
    addComponent(eye);
    addComponent(smile);
    addComponent(healthComponent);

    position = QVector2D(Globals::centerPos.x()-60,Globals::centerPos.y()-60);


    ProjectileConfig *config = new ProjectileConfig();
    config->attackPower = 20;
    spell->projectileConfig = config;
    spell->mana_consume = 2;
    spell->cooldown_time = 150;



    config = new ProjectileConfig();
    config->attackPower = 4;
    config->maxLifetime += 1000;
    hurtSpell->projectile_amount += 17;
    hurtSpell->projectileConfig = config;
    hurtSpell->projectileConfig->aniName = "hurt_bullet";
    hurtSpell->projectileConfig->aniScale = 1;
    hurtSpell->recover_angle *= 2;





    consumeTimer->start();
}


void Player::update(int delta){
    GameObject::update(delta);
    QVector2D direction =QVector2D(Globals::mousePos.x() - Globals::centerPos.x(),Globals::mousePos.y()-Globals::centerPos.y()).normalized();
    Globals::player_direction = direction;
    //qDebug()<<"目标方向"<<Globals::player_direction;
    eye->position = Globals::lerp(QVector2D(0,0),eye->position + 30*direction,0.5);
    //qDebug()<<"受击框"<<healthComponent->touchArea->toPoint();
    if(spell->wait_time>0){
        spell->wait_time -= delta;
    }else{
        spell->could_emit = true;
        spell->wait_time = 0;
    }

}


void Player::shoot(){
   isShotting = true;
    if(smile->current_ani->name == "smile"){
        smile->play("mouse");
    }
    if(eye->current_ani->name == "eyes"){
        eye->play("shark");
    }
    if(mana <= spell->get_total_mana_consume()){
        return;
    }
    if(!spell->could_emit){
        return;
    }
    setMana(mana - spell->get_total_mana_consume());
    spell->release(Globals::player_direction,QVector2D(Globals::centerPos.x(),Globals::centerPos.y()));
    spell->wait_time = spell->get_total_cooldown_time();
}


void Player::cancelShoot(){
    if(smile->current_ani->name == "mouse"){
        smile->play("smile");
    }
    if(eye->current_ani->name == "shark"){
        eye->play("eyes");
    }
    isShotting = false;
}


void Player::setMana(int _mana){
    if(_mana <= 0){
        mana = 0;
    }
    else if(_mana>maxMana){
        mana=maxMana;
    }else{
        mana=_mana;
    }
    emit manaChanged(mana);
}
