#ifndef MOTIONCOMPONENT_H
#define MOTIONCOMPONENT_H
#include"component.h"
#include <QObject>
#include<QVector4D>

class MotionComponent : public Component
{
    Q_OBJECT
public:
    void move(qreal,qreal)override;
    explicit MotionComponent(Component *parent = nullptr);
    void update(int)override;
    void enter()override;
    //速度
    qreal speed;
    QVector2D startDirection = QVector2D(0,0);
    //方向
    QVector2D direction;

signals:
};

#endif // MOTIONCOMPONENT_H
