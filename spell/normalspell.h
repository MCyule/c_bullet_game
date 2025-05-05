#ifndef NORMALSPELL_H
#define NORMALSPELL_H

#include "spell/motionpath.h"
#include "spell/spell.h"
#include <QObject>

class NormalSpell : public Spell
{
    Q_OBJECT
public:
    explicit NormalSpell(Spell *parent = nullptr);
    // 多子弹恢复角度
    qreal recover_angle = 3.14159/18;
    // 发射范围半径
    int emit_range_radius = 32;
    // 发射散射角度  >0
    qreal emit_angle = 0;
    MotionPath *motions;
    void release(QVector2D, QVector2D, int prepareTime=0)override;
    void release_projectile(QVector2D,QVector2D ,int,int);
signals:
};

#endif // NORMALSPELL_H
