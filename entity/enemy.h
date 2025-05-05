#ifndef ENEMY_H
#define ENEMY_H

#include "component/healthcomponent.h"
#include "component/motioncomponent.h"
#include "gameobject.h"
#include <QObject>

class Enemy : public GameObject
{
    Q_OBJECT
public:
    explicit Enemy(GameObject *parent = nullptr);
    virtual void run();
    MotionComponent *motion;
    HealthComponent *healthComponent;
    ~Enemy();

signals:
};

#endif // ENEMY_H
