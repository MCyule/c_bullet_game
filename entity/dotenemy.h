#ifndef DOTENEMY_H
#define DOTENEMY_H

#include <QObject>
#include "component/animatedspritecomponent.h"
#include "entity/enemy.h"

class DotEnemy : public Enemy
{
    Q_OBJECT
public:
    explicit DotEnemy(Enemy *parent = nullptr);
    AnimatedSpriteComponent *sprite;
    void run()override;
    void update(int)override;
    ~DotEnemy();
signals:
};

#endif // DOTENEMY_H
