#ifndef DOTENEMY_H
#define DOTENEMY_H

#include <QObject>
#include "entity/enemy.h"

class DotEnemy : public Enemy
{
    Q_OBJECT
public:
    explicit DotEnemy(Enemy *parent = nullptr);
    void run()override;
    void update(int)override;
    ~DotEnemy();
signals:
};

#endif // DOTENEMY_H
