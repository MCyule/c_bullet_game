#include "motionpath.h"
#include"globals.h"

MotionPath::MotionPath(QObject *parent)
    : QObject{parent},speed(0)
{
    path.append(QVector2D(0,0));
    path.append(QVector2D(1,0));
}

void MotionPath::setPath(const QVector<QVector2D>& p){
    path=p;

}
// 设置路径长度
void MotionPath::setPathLength(float length){
    path_length = length;

}

// 设置是否循环路径
void MotionPath::setPathCyclic(bool cyclic){
    path_cyclic = cyclic;
}

// 路径更新
void MotionPath::update(MotionComponent* motion, int delta){
    if (moved_path_length >= path_length) {
        next_direction = getNextDirection(motion);
        moved_path_length = 0;
    }
    motion->direction = next_direction;
    moved_path_length +=motion->speed * delta;
}

// 获取下次运动的方向
QVector2D MotionPath::getNextDirection(MotionComponent* motion){
    if (next_index >= path.size()) {
        return next_direction;
    }
    next_direction = Globals::instance()->rotated((path[next_index] - path[next_index - 1]).normalized(),std::atan2(motion->startDirection.y(),motion->startDirection.x()));
    next_index++;
    if (next_index >= path.size() && path_cyclic) {
        next_index = 1;
    }
    return next_direction;
}



MotionPath* MotionPath::duplicate(){
    MotionPath* uu = new MotionPath();
    uu->speed = speed;
    return uu;
}

void MotionPath::copy(MotionPath* mo){
    mo->path_length = path_length;
    mo->path = path;
    mo->path_cyclic = path_cyclic;
}
