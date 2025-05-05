#include "hud.h"
#include "ui_hud.h"
#include"globals.h"

HUD::HUD(QWidget *parent)
    : QWidget(parent)
    , timer(new QTimer)
    ,ui(new Ui::HUD)
{
    ui->setupUi(this);
    move(600,0);
    setAttribute(Qt::WA_TransparentForMouseEvents,true);
    setStyleSheet("QDialog{"
                  "background-color:black"
                  "}");
    ui->healthBar->setStyleSheet(""
                                 "QProgressBar::Chunk {"
                                 "background-color:white"
                                 "}"
                                 "QProgressBar{"
                                 "border: 1px"
                                 "}"
                                 "");
    ui->healthLabel->setStyleSheet("QLabel{"
                                   "color:white"
                                   "}");
    ui->manaBar->setStyleSheet(""
                               "QProgressBar::Chunk {"
                               "background-color:#ADD8E6"
                               "}"
                               "QProgressBar{"
                               "border: 1px"
                               "}"
                               "");
    ui->manaLabel->setStyleSheet("QLabel{"
                                 "color:white"
                                 "}");
    ui->timeLabel->setStyleSheet("QLabel{"
                                 "background-color: transparent;"
                                   "color:white;"
                                    ""
                                    ""
                                    ""
                                    "}");
    QFont font;
    font.setPointSize(32);
    ui->timeLabel->setFont(font);
    connect(Globals::instance(),&Globals::playerLoaded,this,[this](Player *player){
        connect(player->healthComponent,&HealthComponent::healthChanged,this,[this](int health){
            ui->healthBar->setValue(health);
            qDebug()<<health;
        });
    });
    connect(Globals::instance(),&Globals::playerLoaded,this,[this](Player *player){
        connect(player,&Player::manaChanged,this,[this](int mana){
            ui->manaBar->setValue(mana /2);
        });
    });
    connect(timer,&QTimer::timeout,this,[this](){
        ui->timeLabel->setText(QString::number(currentTime));
        currentTime += 1;
        levelTime += 1;
        if(levelTime > 40){
            Globals::instance()->window->spawnCard();
            levelTime = 0;
        }
    });
    timer->setInterval(100);
    timer->start();
}

HUD::~HUD()
{
    delete ui;
}

void HUD::mouseMoveEvent(QMouseEvent*event){
    event->ignore();
}

void HUD::mousePressEvent(QMouseEvent*event){
    event->ignore();
}


void HUD::mouseReleaseEvent(QMouseEvent*event){
    event->ignore();
}


