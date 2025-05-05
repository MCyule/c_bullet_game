#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "component.h"
#include <QObject>

class HealthComponent : public Component
{
    Q_OBJECT
public:
    explicit HealthComponent(Component *parent = nullptr);
    void update(int)override;
    bool hurtCollide(HealthComponent*);
    bool attackCollide(HealthComponent*);
    void takeDamage(int);
    // 是否时敌人
    bool isEnemy;
    // 生命值
    int health;
    // 攻击力
    int attack;
    // 攻击冷却时间
    int maxCooldownTime = 1000;
    int cooldownTime = 0;
    // 能否攻击
    bool couldAttack;
    // 能否受伤
    bool couldHurt;
    // TouchComponent
    QVector2D* touchArea;
    // AttackComponent
    QVector2D* attackArea;
    // 所在层 玩家 敌人 玩家子弹 敌人子弹
    int layer[4] = {0,0,0,0};
    ~HealthComponent();

signals:
    void collied();
    void healthChanged(int);
};

#endif // HEALTHCOMPONENT_H
