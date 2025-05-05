#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entity/enemy.h"
#include"gameobject.h"
#include"main/gameview.h"
#include "scene/hud.h"

#include <QMainWindow>
#include<QPaintEvent>
#include<QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


struct FreeTimer{
    GameObject* obj;
    qreal time;
    FreeTimer(GameObject* _obj,qreal _time):obj(_obj),time(_time){}
};


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    //世界跟新
    void update_world();
    QList<FreeTimer*> *freeList;
    //游戏对象
    QVector<GameObject*> *objects;
    QVector<Enemy*> *enemys;
    //游戏计时器
    QTimer *timer;
    //渲染
    QGraphicsScene *scene;
    //渲染
    GameView *view;
    // ui
    HUD *hud;
    void spawn();
    void spawnCard();
    int cardIndex = 0;
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
