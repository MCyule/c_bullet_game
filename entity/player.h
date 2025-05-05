#ifndef PLAYER_H
#define PLAYER_H

#include "component/animatedspritecomponent.h"
#include "component/healthcomponent.h"
#include"gameobject.h"
#include "spell/normalspell.h"

#include <QObject>

class Player : public GameObject
{
    Q_OBJECT
public:
    explicit Player(GameObject *parent = nullptr);
    void update(int)override;
    void shoot();
    void cancelShoot();
    void setMana(int);
    AnimatedSpriteComponent *smile;
    AnimatedSpriteComponent* eye;
    AnimatedSpriteComponent *body;
    QTimer *consumeTimer;
    QTimer *hurtTimer;
    HealthComponent* healthComponent;
    NormalSpell *spell;
    NormalSpell *hurtSpell;
    NormalSpell *autoSpell1;
    NormalSpell *autoSpell2;
    int maxMana = 200;
    int mana=200;
    bool isShotting = false;
    bool recoverHealth = false;
    bool hasInvinTime = false;
    bool hasHurtSpell = false;
signals:
    void manaChanged(int);
    void shooted(QVector2D);
};

#endif // PLAYER_H
