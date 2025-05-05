#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include<QVector2D>

class Component : public QObject
{
    Q_OBJECT
public:
    bool isAlive = true;
    QString name;
    //相对父节点的位置
    QVector2D position;
    explicit Component(QString = "",QObject *parent = nullptr);
    //获得组件
    virtual void enter();
    //更新组件
    virtual void update(int);
    //移除组件
    virtual void exit();
    //全局坐标
    QVector2D global_position();
    virtual void move(qreal,qreal);
signals:
};

#endif // COMPONENT_H
