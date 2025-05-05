#include "animatedspritecomponent.h"
#include"globals.h"

#include<QGraphicsPixmapItem>
#include<QObject>

AnimatedSpriteComponent::AnimatedSpriteComponent(QGraphicsPixmapItem *parent)
    :Component{}, QGraphicsPixmapItem{parent},count(0)
{
    Component::name = "AnimatedSpriteComponent";
}


void AnimatedSpriteComponent::append(QPixmap* texture,int length,QString name){
    if(texture->isNull()){
        qDebug()<<"不存在";
    }
    animations.insert(name,new Animation(texture,length,name));
}


void AnimatedSpriteComponent::update_animation(){
    if(current_ani->frame >= current_ani->length){
        current_ani->frame = 0;
    }
    QPixmap child = current_ani->texture->copy(current_ani->frame_size.width()*current_ani->frame,0,current_ani->frame_size.width(),current_ani->frame_size.height());
    setPixmap(child);
    current_ani->frame++;
}


void AnimatedSpriteComponent::play(const QString name,int scale){
    current_ani = *animations.find(name);
    if(scale != -1){
        setScale(scale);
    }
}


void AnimatedSpriteComponent::enter(){
    Globals::instance()->game_scene->addItem(this);
}


void AnimatedSpriteComponent::update(int delta){
    Component::update(delta);
    if (current_ani == nullptr) {
        return;
    }
    if(count >= 100){
        update_animation();
        count =0;
    }
    count += delta;
}


void AnimatedSpriteComponent::exit(){
    Globals::instance()->game_scene->removeItem(this);
}


void AnimatedSpriteComponent::move(qreal x, qreal y){
    Component::move(x,y);
    setPos(QPointF(global_position().x(),global_position().y()));
}



AnimatedSpriteComponent::~AnimatedSpriteComponent(){
   delete current_ani;
    animations.clear();
}
