#include "motioncomponent.h"
#include"gameobject.h"


MotionComponent::MotionComponent(Component *parent)
    : Component{"MotionComponent",parent},speed(0),direction(QVector2D(0,0))
{}


void MotionComponent::update(int delta){
    qobject_cast<GameObject*>(parent())->position += direction.normalized() * speed * float(delta) /1000;
}


void MotionComponent::enter(){}


void MotionComponent::move(qreal x, qreal y){
    Component::move(x,y);
}
