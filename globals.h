#ifndef GLOBALS_H
#define GLOBALS_H

#include <QObject>
#include<QVector4D>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QMainWindow>
#include"mainwindow.h"
#include"entity/player.h"

class Globals : public QObject
{
    Q_OBJECT
private:
    static Globals* object;
    explicit Globals(QObject *parent = nullptr);
public:
    static Globals* instance();
    static QVector2D randomPoitOutside();
    static QPoint toPoint(const QVector2D);
    static QVector2D toVector2(const QPoint);
    static QVector2D rotated(QVector2D,qreal);
    template<typename T>
    static T lerp(T a,T b,qreal t){
        return a + (b-a)*t;
    }
    // 中心位置
    const static QPoint centerPos;
    const QVector2D leftDownPoint = QVector2D(0,1000);
    const QVector2D rightUpPoint = QVector2D(1800,0);
    const QVector2D rightDownPoint = QVector2D(1800,1000);
    const QRect worldRect = QRect(0,0,1800,1000);
    // 基于玩家中心位置
    static QVector2D player_direction;
    //玩家输入
    QVector4D motion;
    Player *player;
    void setplayer(Player*);
    QVector2D generateRandomUnitVector();
    // 鼠标位置
    static QPoint mousePos;
    //渲染
    QGraphicsScene *game_scene;
    //视图
    QGraphicsView *game_view;
    MainWindow *window;
    HUD *hud;
    int level = 0;
    int cards[12]{1,2,3,4,5,6,7,8,9,10,11};
    void upgrade(int);
    int enemyHealth=0;
    int enemyAttack=0;
    int enemySpeed=0;
    bool isWin = false;
    QSoundEffect *music;

signals:
    void playerLoaded(Player*);
};

#endif // GLOBALS_H
