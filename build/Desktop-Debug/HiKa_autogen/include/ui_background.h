/********************************************************************************
** Form generated from reading UI file 'background.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUND_H
#define UI_BACKGROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackGround
{
public:

    void setupUi(QWidget *BackGround)
    {
        if (BackGround->objectName().isEmpty())
            BackGround->setObjectName("BackGround");
        BackGround->resize(400, 300);

        retranslateUi(BackGround);

        QMetaObject::connectSlotsByName(BackGround);
    } // setupUi

    void retranslateUi(QWidget *BackGround)
    {
        BackGround->setWindowTitle(QCoreApplication::translate("BackGround", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackGround: public Ui_BackGround {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUND_H
