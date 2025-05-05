#ifndef MOTIONPATH_H
#define MOTIONPATH_H

#include "component/motioncomponent.h"
#include <QObject>

class MotionPath : public QObject
{
    Q_OBJECT
public:
    explicit MotionPath(QObject *parent = nullptr);
    void update(MotionComponent*, int);
    MotionPath* duplicate();
    int speed = 0;
    QVector2D dir;
public:
    float moved_path_length = 0;
    QVector2D next_direction = QVector2D(0, 0);
    int next_index = 1;
    QVector<QVector2D> path;
    float path_length = 60000;
    bool path_cyclic = true;
public:
    // 设置路径
    void setPath(const QVector<QVector2D>& p);
    // 设置路径长度
    void setPathLength(float length);
    // 设置是否循环路径
    void setPathCyclic(bool cyclic);
    // 获取下次运动的方向
    QVector2D getNextDirection(MotionComponent* motio);
    void copy(MotionPath* mo);
signals:
};

#endif // MOTIONPATH_H
