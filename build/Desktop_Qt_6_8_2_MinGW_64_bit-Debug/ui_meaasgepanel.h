/********************************************************************************
** Form generated from reading UI file 'meaasgepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEAASGEPANEL_H
#define UI_MEAASGEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MeaasgePanel
{
public:

    void setupUi(QDialog *MeaasgePanel)
    {
        if (MeaasgePanel->objectName().isEmpty())
            MeaasgePanel->setObjectName("MeaasgePanel");
        MeaasgePanel->resize(400, 300);

        retranslateUi(MeaasgePanel);

        QMetaObject::connectSlotsByName(MeaasgePanel);
    } // setupUi

    void retranslateUi(QDialog *MeaasgePanel)
    {
        MeaasgePanel->setWindowTitle(QCoreApplication::translate("MeaasgePanel", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeaasgePanel: public Ui_MeaasgePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEAASGEPANEL_H
