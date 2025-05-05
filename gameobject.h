#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include"component.h"

#include <QWidget>

/**
 * @brief The GameObject class
 * 游戏世界的基类
 */

class GameObject : public QObject{
    Q_OBJECT
protected:

    QMap<QString,Component*>* components;
public:
    explicit GameObject(QObject *parent = nullptr);
    bool isAlive = true;
    //帧更新
    virtual void update(int);
    //添加组件
    void addComponent(Component*);
    //移除组件
    void removeComponent(Component*);
    //获得组件  
    Component* getComponent(QString);
    //位置
    QVector2D position;
    ~GameObject();
signals:
    void died();
};

#endif // GAMEOBJECT_H
