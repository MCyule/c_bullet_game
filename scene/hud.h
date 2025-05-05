#ifndef HUD_H
#define HUD_H

#include <QWidget>

namespace Ui {
class HUD;
}

class HUD : public QWidget
{
    Q_OBJECT

public:
    explicit HUD(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent*)override;
    void mousePressEvent(QMouseEvent*)override;
    void mouseReleaseEvent(QMouseEvent*)override;
    QTimer *timer;
    float currentTime =0;
    int levelTime = 0;
    ~HUD();
Ui::HUD *ui;
private:

};

#endif // HUD_H
