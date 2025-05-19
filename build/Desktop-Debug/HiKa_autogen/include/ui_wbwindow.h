/********************************************************************************
** Form generated from reading UI file 'wbwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WBWINDOW_H
#define UI_WBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WBWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *pickLabel;
    QLabel *comboLabel;
    QLabel *answerLabel;
    QSpacerItem *verticalSpacer_6;
    QLabel *harbingerLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *inputLineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *imageLabel;
    QPushButton *backButton;

    void setupUi(QWidget *WBWindow)
    {
        if (WBWindow->objectName().isEmpty())
            WBWindow->setObjectName("WBWindow");
        WBWindow->resize(960, 540);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WBWindow->sizePolicy().hasHeightForWidth());
        WBWindow->setSizePolicy(sizePolicy);
        WBWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(WBWindow);
        gridLayout->setObjectName("gridLayout");
        pickLabel = new QLabel(WBWindow);
        pickLabel->setObjectName("pickLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font.setPointSize(18);
        pickLabel->setFont(font);
        pickLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0, 0);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(pickLabel, 4, 0, 2, 1);

        comboLabel = new QLabel(WBWindow);
        comboLabel->setObjectName("comboLabel");
        QFont font1;
        font1.setPointSize(32);
        comboLabel->setFont(font1);
        comboLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 192, 243);\n"
"background-color: rgb(0, 0, 0, 0);"));
        comboLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);

        gridLayout->addWidget(comboLabel, 9, 3, 2, 1);

        answerLabel = new QLabel(WBWindow);
        answerLabel->setObjectName("answerLabel");
        sizePolicy.setHeightForWidth(answerLabel->sizePolicy().hasHeightForWidth());
        answerLabel->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(26);
        answerLabel->setFont(font2);
        answerLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0,0);"));

        gridLayout->addWidget(answerLabel, 7, 0, 1, 4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 2, 0, 1, 4);

        harbingerLabel = new QLabel(WBWindow);
        harbingerLabel->setObjectName("harbingerLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(harbingerLabel->sizePolicy().hasHeightForWidth());
        harbingerLabel->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("mikachan-puchiB")});
        font3.setPointSize(22);
        harbingerLabel->setFont(font3);
        harbingerLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 181, 243);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(harbingerLabel, 4, 1, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 8, 0, 1, 4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 9, 0, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 4);

        inputLineEdit = new QLineEdit(WBWindow);
        inputLineEdit->setObjectName("inputLineEdit");
        sizePolicy1.setHeightForWidth(inputLineEdit->sizePolicy().hasHeightForWidth());
        inputLineEdit->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("mikachan-puchi")});
        font4.setPointSize(22);
        font4.setItalic(false);
        inputLineEdit->setFont(font4);
        inputLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 181, 243);\n"
"color: rgb(170, 0, 0);"));
        inputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(inputLineEdit, 4, 3, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 4);

        imageLabel = new QLabel(WBWindow);
        imageLabel->setObjectName("imageLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);
        imageLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(imageLabel, 0, 4, 11, 1);

        backButton = new QPushButton(WBWindow);
        backButton->setObjectName("backButton");
        QFont font5;
        font5.setPointSize(20);
        backButton->setFont(font5);
        backButton->setStyleSheet(QString::fromUtf8("background: transparent;"));

        gridLayout->addWidget(backButton, 0, 0, 1, 1);


        retranslateUi(WBWindow);

        QMetaObject::connectSlotsByName(WBWindow);
    } // setupUi

    void retranslateUi(QWidget *WBWindow)
    {
        WBWindow->setWindowTitle(QCoreApplication::translate("WBWindow", "Form", nullptr));
        pickLabel->setText(QCoreApplication::translate("WBWindow", "Picked word:", nullptr));
        comboLabel->setText(QString());
        answerLabel->setText(QString());
        harbingerLabel->setText(QString());
        inputLineEdit->setText(QString());
        imageLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("WBWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WBWindow: public Ui_WBWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WBWINDOW_H
