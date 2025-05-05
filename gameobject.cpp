#include "gameobject.h"
#include"component.h"

#include<QObject>

GameObject::GameObject(QObject *parent)
    : QObject{parent},components(new QMap<QString,Component*>())
{
}


void GameObject::update(int delta){
    if(!isAlive){
        return;
    }
    Q_FOREACH(QString key,components->keys()){
        components->value(key)->move(position.x(),position.y());
        components->value(key)->update(delta);
    }
}


void GameObject::addComponent(Component* c){
    c->setParent(this);
    components->insert(c->name,c);
    c->enter();
}


void GameObject::removeComponent(Component* c){
    c->exit();
    c->setParent(nullptr);
    components->remove(c->name);
}


Component* GameObject::getComponent(QString key){
    return components->value(key);
}


GameObject::~GameObject(){
    Q_FOREACH(QString key,components->keys()){
        components->value(key)->exit();
    }
    components->clear();
}
