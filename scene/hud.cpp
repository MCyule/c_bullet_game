#include "hud.h"
#include "ui_hud.h"
#include"globals.h"

HUD::HUD(QWidget *parent)
    : QWidget(parent)
    , timer(new QTimer)
    ,ui(new Ui::HUD)
{
    ui->setupUi(this);
    Globals::instance()->hud = this;
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
    ui->bossBar->setStyleSheet(""
                                 "QProgressBar::Chunk {"
                                 "background-color:red"
                                 "}"
                                 "QProgressBar{"
                                 "border: 1px"
                                 "}"
                                 "");
    ui->bossBar->setValue(100);
    ui->bossBar->setVisible(false);
    ui->winLabel->setStyleSheet("QLabel{"
                                   "color:white"
                                   "}");
    ui->winLabel->setVisible(false);
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
    ui->label->setStyleSheet("QLabel{"
                             "background-image: url(:/q1);"
                             ""
                             "}");
    ui->label_2->setStyleSheet("QLabel{"
                             "background-image: url(:/q2);"
                             ""
                             "}");
    ui->label_3->setStyleSheet("QLabel{"
                               "background-image: url(:/q3);"
                               ""
                               "}");
    ui->label_4->setStyleSheet("QLabel{"
                               "background-image: url(:/q4);"
                               ""
                               "}");
    ui->label_5->setStyleSheet("QLabel{"
                               "background-image: url(:/q5);"
                               ""
                               "}");
    ui->label_6->setStyleSheet("QLabel{"
                               "background-image: url(:/q6);"
                               ""
                               "}");
    ui->label_7->setStyleSheet("QLabel{"
                               "background-image: url(:/q7);"
                               ""
                               "}");
    ui->label_8->setStyleSheet("QLabel{"
                               "background-image: url(:/q8);"
                               ""
                               "}");
    ui->label_9->setStyleSheet("QLabel{"
                               "background-image: url(:/q9);"
                               ""
                               "}");
    ui->label_10->setStyleSheet("QLabel{"
                               "background-image: url(:/q10);"
                               ""
                               "}");
    ui->label_11->setStyleSheet("QLabel{"
                               "background-image: url(:/q11);"
                               ""
                               "}");
    ui->label_12->setStyleSheet("QLabel{"
                               "background-image: url(:/q12);"
                               ""
                               "}");
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
            ui->label_5->setVisible(false);
            ui->label_6->setVisible(false);
            ui->label_7->setVisible(false);
            ui->label_8->setVisible(false);
            ui->label_9->setVisible(false);
            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);


    QFont font;
    font.setPointSize(32);
    ui->timeLabel->setFont(font);
    QFont font1;
    font1.setPointSize(200);
    ui->winLabel->setFont(font1);
    connect(Globals::instance(),&Globals::playerLoaded,this,[this](Player *player){
        connect(player->healthComponent,&HealthComponent::healthChanged,this,[this](int health){
            ui->healthBar->setValue(health);
            //qDebug()<<health;
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
            if(Globals::instance()->window->enemyCounnt<=10){
                Globals::instance()->window->enemyCounnt += 2;
                Globals::instance()->enemySpeed += 40;
                Globals::instance()->enemyAttack += 5;
                Globals::instance()->enemyHealth += 10;
            }
            levelTime = 0;
        }
    });
    timer->setInterval(50);
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


