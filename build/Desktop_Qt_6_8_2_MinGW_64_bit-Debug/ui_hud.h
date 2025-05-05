/********************************************************************************
** Form generated from reading UI file 'hud.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUD_H
#define UI_HUD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HUD
{
public:
    QLabel *manaLabel;
    QLabel *healthLabel;
    QProgressBar *healthBar;
    QProgressBar *manaBar;
    QLabel *timeLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QProgressBar *bossBar;
    QLabel *winLabel;

    void setupUi(QWidget *HUD)
    {
        if (HUD->objectName().isEmpty())
            HUD->setObjectName("HUD");
        HUD->resize(801, 856);
        manaLabel = new QLabel(HUD);
        manaLabel->setObjectName("manaLabel");
        manaLabel->setGeometry(QRect(10, 60, 40, 12));
        healthLabel = new QLabel(HUD);
        healthLabel->setObjectName("healthLabel");
        healthLabel->setGeometry(QRect(10, 10, 51, 21));
        healthLabel->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:rgb(255, 255, 255)\n"
"}"));
        healthLabel->setLineWidth(1);
        healthBar = new QProgressBar(HUD);
        healthBar->setObjectName("healthBar");
        healthBar->setGeometry(QRect(60, 10, 331, 16));
        healthBar->setValue(100);
        healthBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        healthBar->setTextVisible(true);
        manaBar = new QProgressBar(HUD);
        manaBar->setObjectName("manaBar");
        manaBar->setGeometry(QRect(60, 60, 331, 16));
        manaBar->setValue(100);
        manaBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        manaBar->setTextVisible(true);
        timeLabel = new QLabel(HUD);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(410, 20, 401, 41));
        timeLabel->setScaledContents(false);
        timeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeLabel->setWordWrap(false);
        label = new QLabel(HUD);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 100, 31, 31));
        label->setScaledContents(true);
        label_2 = new QLabel(HUD);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 100, 31, 31));
        label_2->setScaledContents(true);
        label_3 = new QLabel(HUD);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 100, 31, 31));
        label_3->setScaledContents(true);
        label_4 = new QLabel(HUD);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 100, 31, 31));
        label_4->setScaledContents(true);
        label_5 = new QLabel(HUD);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 100, 31, 31));
        label_5->setScaledContents(true);
        label_6 = new QLabel(HUD);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 100, 31, 31));
        label_6->setScaledContents(true);
        label_7 = new QLabel(HUD);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 130, 31, 31));
        label_7->setScaledContents(true);
        label_8 = new QLabel(HUD);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(70, 130, 31, 31));
        label_8->setScaledContents(true);
        label_9 = new QLabel(HUD);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(110, 130, 31, 31));
        label_9->setScaledContents(true);
        label_10 = new QLabel(HUD);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(160, 130, 31, 31));
        label_10->setScaledContents(true);
        label_11 = new QLabel(HUD);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(200, 130, 31, 31));
        label_11->setScaledContents(true);
        label_12 = new QLabel(HUD);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(250, 130, 31, 31));
        label_12->setScaledContents(true);
        bossBar = new QProgressBar(HUD);
        bossBar->setObjectName("bossBar");
        bossBar->setGeometry(QRect(7, 793, 631, 20));
        bossBar->setValue(24);
        winLabel = new QLabel(HUD);
        winLabel->setObjectName("winLabel");
        winLabel->setGeometry(QRect(10, 160, 801, 391));

        retranslateUi(HUD);

        QMetaObject::connectSlotsByName(HUD);
    } // setupUi

    void retranslateUi(QWidget *HUD)
    {
        HUD->setWindowTitle(QCoreApplication::translate("HUD", "Form", nullptr));
        manaLabel->setText(QCoreApplication::translate("HUD", "\351\255\224\345\212\233\345\200\274\357\274\232 ", nullptr));
        healthLabel->setText(QCoreApplication::translate("HUD", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        timeLabel->setText(QCoreApplication::translate("HUD", "0", nullptr));
        label->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("HUD", "TextLabel", nullptr));
        winLabel->setText(QCoreApplication::translate("HUD", "WIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HUD: public Ui_HUD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUD_H
