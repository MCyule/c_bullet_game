#ifndef ANIMATEDSPRITECOMPONENT_H
#define ANIMATEDSPRITECOMPONENT_H
#include<gameobject.h>
#include <QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>


//存储动画
struct Animation
{

    //名称
    QString name;
    //纹理
    QPixmap *texture;
    //有几帧
    int length;
    //当前帧
    int frame;
    //每帧大小
    QSize frame_size;
    Animation(QPixmap* _texture,int _length,QString _name):name(_name),texture(_texture),length(_length),frame(0) {
        frame_size = QSize(texture->size().width()/length,texture->size().height());

    }
    ~Animation(){
        delete texture;
    }
};


class AnimatedSpriteComponent :public Component, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //动画更新
    void update_animation();
    //计时器
    Animation *current_ani;
    int count;

    //当前动画；
    void move(qreal,qreal)override;
public:
    QMap<QString,Animation*> animations;
    //存储动画；
    void enter()override;
    void update(int)override;
    void exit()override;
    explicit AnimatedSpriteComponent(QGraphicsPixmapItem *parent = nullptr);
    //添加动画
    void append(QPixmap*,int,QString);
    //播放动画
    void play(QString name, int scale=-1);
    ~AnimatedSpriteComponent();
};

\

#endif // ANIMATEDSPRITECOMPONENT_H
