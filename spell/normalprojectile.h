#ifndef NORMALPROJECTILE_H
#define NORMALPROJECTILE_H

#include "spell/projectile.h"
#include <QObject>
#include<QSoundEffect>



class NormalProjectile : public Projectile
{
    Q_OBJECT
public:
    explicit NormalProjectile(Projectile *parent = nullptr);
public slots:
   void onDeath(bool isHit = false)override;
    void onTriggerTimeTimeout()override;
public:
    void loadRes(const ProjectileConfig* res);
    void update(int delta) override;
    void onHitEnemy()override;
};

#endif // NORMALPROJECTILE_H
