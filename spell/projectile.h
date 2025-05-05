#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "component/animatedspritecomponent.h"
#include "component/healthcomponent.h"
#include "component/motioncomponent.h"
#include "gameobject.h"
#include "spell/motionpath.h"
#include "spell/projectileconfig.h"
#include <QObject>
#include"spell/spell.h"

class Projectile : public GameObject
{
    Q_OBJECT
public:
    explicit Projectile(GameObject *parent = nullptr);
    MotionComponent *motion;
    AnimatedSpriteComponent *sprite;
    HealthComponent *healthComponent;
    void loadRes(const ProjectileConfig* res);
    void setup(const ProjectileConfig* res, const QVector2D& start, const QVector2D& oriDirection, Spell** triggerSpells);
    void shoot();

    virtual void update(int delta);
signals:
    void setuped();
    void shooted();
    void enemyPassed(HealthComponent* area);
public slots:
    virtual void onTriggerTimeTimeout();
    void onLifetimeTimeout();
    virtual void onDeath(bool isHit = false);
    void dealDeath();
    virtual void onHitEnemy();
public:
    static constexpr int maxTriggerTime = 1000;
    float triggerTime = 0;
    int triggerCount = 1;
    QVector2D startPos;
    QVector2D startDir;
    bool isShooted = false;
    QList<Spell*> spells;
    float damp = 0;
    MotionPath* motionpath;
    qreal shootSpeed = 100;
    int maxLifetime = 3000;
    int passCount = 1;
    float waitTime = 0;
    int preparedTime = 0;
    bool shouldUpdate = true;

    ~Projectile();
};

#endif // PROJECTILE_H
