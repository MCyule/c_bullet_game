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

    void setupUi(QWidget *HUD)
    {
        if (HUD->objectName().isEmpty())
            HUD->setObjectName("HUD");
        HUD->resize(400, 856);
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
        timeLabel->setGeometry(QRect(0, 810, 401, 41));
        timeLabel->setScaledContents(false);
        timeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeLabel->setWordWrap(false);

        retranslateUi(HUD);

        QMetaObject::connectSlotsByName(HUD);
    } // setupUi

    void retranslateUi(QWidget *HUD)
    {
        HUD->setWindowTitle(QCoreApplication::translate("HUD", "Form", nullptr));
        manaLabel->setText(QCoreApplication::translate("HUD", "\351\255\224\345\212\233\345\200\274\357\274\232 ", nullptr));
        healthLabel->setText(QCoreApplication::translate("HUD", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        timeLabel->setText(QCoreApplication::translate("HUD", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HUD: public Ui_HUD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUD_H
