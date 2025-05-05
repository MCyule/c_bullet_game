#ifndef CARD_H
#define CARD_H

#include "component/animatedspritecomponent.h"
#include "entity/enemy.h"
#include <QObject>

class Card : public Enemy
{
    Q_OBJECT
public:
    explicit Card(Enemy *parent = nullptr);
    AnimatedSpriteComponent *sprite;

    int id = 0;

signals:
};

#endif // CARD_H
