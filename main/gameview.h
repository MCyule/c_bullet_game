#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include<QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameView(QGraphicsScene *scene,QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent*)override;
    void mousePressEvent(QMouseEvent*)override;
    void keyPressEvent(QKeyEvent*)override;
    void keyReleaseEvent(QKeyEvent*)override;
private:
    QSet<int> keysPressed; // 存储当前按下的键
signals:
};

#endif // GAMEVIEW_H
