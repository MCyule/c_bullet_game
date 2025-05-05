/********************************************************************************
** Form generated from reading UI file 'messagepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEPANEL_H
#define UI_MESSAGEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_MessagePanel
{
public:
    QLabel *healthLabel;
    QProgressBar *healthBar;
    QLabel *manaLabel;
    QProgressBar *manaBar;

    void setupUi(QDialog *MessagePanel)
    {
        if (MessagePanel->objectName().isEmpty())
            MessagePanel->setObjectName("MessagePanel");
        MessagePanel->resize(400, 300);
        healthLabel = new QLabel(MessagePanel);
        healthLabel->setObjectName("healthLabel");
        healthLabel->setGeometry(QRect(10, 20, 51, 21));
        healthLabel->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:rgb(255, 255, 255)\n"
"}"));
        healthLabel->setLineWidth(1);
        healthBar = new QProgressBar(MessagePanel);
        healthBar->setObjectName("healthBar");
        healthBar->setGeometry(QRect(60, 20, 331, 16));
        healthBar->setValue(100);
        healthBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        healthBar->setTextVisible(true);
        manaLabel = new QLabel(MessagePanel);
        manaLabel->setObjectName("manaLabel");
        manaLabel->setGeometry(QRect(10, 70, 40, 12));
        manaBar = new QProgressBar(MessagePanel);
        manaBar->setObjectName("manaBar");
        manaBar->setGeometry(QRect(60, 70, 331, 16));
        manaBar->setValue(100);
        manaBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        manaBar->setTextVisible(true);

        retranslateUi(MessagePanel);

        QMetaObject::connectSlotsByName(MessagePanel);
    } // setupUi

    void retranslateUi(QDialog *MessagePanel)
    {
        MessagePanel->setWindowTitle(QCoreApplication::translate("MessagePanel", "Dialog", nullptr));
        healthLabel->setText(QCoreApplication::translate("MessagePanel", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        manaLabel->setText(QCoreApplication::translate("MessagePanel", "\351\255\224\345\212\233\345\200\274\357\274\232 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagePanel: public Ui_MessagePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEPANEL_H
