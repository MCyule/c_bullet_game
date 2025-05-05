#include "component.h"
#include"gameobject.h"

Component::Component(QString _name,QObject *parent)
    : QObject{parent},name(_name)
{}

void Component::enter(){}


void Component::update(int){}


void Component::exit(){}


QVector2D Component::global_position(){
    return qobject_cast<GameObject*>(parent())->position + position;
}


void Component::move(qreal, qreal){}
