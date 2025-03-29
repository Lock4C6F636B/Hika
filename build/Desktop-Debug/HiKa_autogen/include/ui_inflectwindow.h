/********************************************************************************
** Form generated from reading UI file 'inflectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFLECTWINDOW_H
#define UI_INFLECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InflectWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QPushButton *backButton;
    QLabel *imageLabel;
    QLabel *comboLabel;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *inputLineEdit;
    QLabel *answerLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *pickLabel;
    QPushButton *whatButton;
    QLabel *harbingerLabel;
    QLabel *prophecyLabel;

    void setupUi(QWidget *InflectWindow)
    {
        if (InflectWindow->objectName().isEmpty())
            InflectWindow->setObjectName("InflectWindow");
        InflectWindow->resize(960, 540);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InflectWindow->sizePolicy().hasHeightForWidth());
        InflectWindow->setSizePolicy(sizePolicy);
        InflectWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(InflectWindow);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 8, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 2);

        backButton = new QPushButton(InflectWindow);
        backButton->setObjectName("backButton");
        QFont font;
        font.setPointSize(20);
        backButton->setFont(font);

        gridLayout->addWidget(backButton, 0, 0, 1, 1);

        imageLabel = new QLabel(InflectWindow);
        imageLabel->setObjectName("imageLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        imageLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(imageLabel, 0, 4, 10, 1);

        comboLabel = new QLabel(InflectWindow);
        comboLabel->setObjectName("comboLabel");
        QFont font1;
        font1.setPointSize(32);
        comboLabel->setFont(font1);
        comboLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 192, 243);\n"
"background-color: rgb(0, 0, 0, 0);"));
        comboLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);

        gridLayout->addWidget(comboLabel, 8, 3, 2, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 7, 0, 1, 4);

        inputLineEdit = new QLineEdit(InflectWindow);
        inputLineEdit->setObjectName("inputLineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inputLineEdit->sizePolicy().hasHeightForWidth());
        inputLineEdit->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("mikachan-puchi")});
        font2.setPointSize(22);
        font2.setItalic(true);
        inputLineEdit->setFont(font2);
        inputLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 181, 243);\n"
"color: rgb(170, 0, 0);"));
        inputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(inputLineEdit, 3, 3, 2, 1);

        answerLabel = new QLabel(InflectWindow);
        answerLabel->setObjectName("answerLabel");
        sizePolicy.setHeightForWidth(answerLabel->sizePolicy().hasHeightForWidth());
        answerLabel->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(26);
        answerLabel->setFont(font3);
        answerLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0,0);"));

        gridLayout->addWidget(answerLabel, 6, 0, 1, 4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 5, 0, 1, 4);

        pickLabel = new QLabel(InflectWindow);
        pickLabel->setObjectName("pickLabel");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font4.setPointSize(18);
        pickLabel->setFont(font4);
        pickLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0, 0);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(pickLabel, 3, 0, 2, 1);

        whatButton = new QPushButton(InflectWindow);
        whatButton->setObjectName("whatButton");
        sizePolicy.setHeightForWidth(whatButton->sizePolicy().hasHeightForWidth());
        whatButton->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("mikachan-puchi")});
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(false);
        whatButton->setFont(font5);
        whatButton->setStyleSheet(QString::fromUtf8("background: rgba(0, 0, 0, 0);\n"
"borde: rgba(0, 0, 0, 0);"));

        gridLayout->addWidget(whatButton, 9, 0, 2, 1);

        harbingerLabel = new QLabel(InflectWindow);
        harbingerLabel->setObjectName("harbingerLabel");
        sizePolicy2.setHeightForWidth(harbingerLabel->sizePolicy().hasHeightForWidth());
        harbingerLabel->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("mikachan-puchiB")});
        font6.setPointSize(22);
        harbingerLabel->setFont(font6);
        harbingerLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 181, 243);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(harbingerLabel, 3, 1, 2, 1);

        prophecyLabel = new QLabel(InflectWindow);
        prophecyLabel->setObjectName("prophecyLabel");
        sizePolicy.setHeightForWidth(prophecyLabel->sizePolicy().hasHeightForWidth());
        prophecyLabel->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("mikachan-puchi")});
        font7.setPointSize(20);
        font7.setBold(true);
        font7.setItalic(false);
        prophecyLabel->setFont(font7);
        prophecyLabel->setTextFormat(Qt::TextFormat::AutoText);
        prophecyLabel->setWordWrap(true);

        gridLayout->addWidget(prophecyLabel, 2, 0, 1, 4);


        retranslateUi(InflectWindow);

        QMetaObject::connectSlotsByName(InflectWindow);
    } // setupUi

    void retranslateUi(QWidget *InflectWindow)
    {
        InflectWindow->setWindowTitle(QCoreApplication::translate("InflectWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("InflectWindow", "Back", nullptr));
        imageLabel->setText(QString());
        comboLabel->setText(QString());
        inputLineEdit->setText(QString());
        answerLabel->setText(QString());
        pickLabel->setText(QCoreApplication::translate("InflectWindow", "Picked word:", nullptr));
        whatButton->setText(QCoreApplication::translate("InflectWindow", "?", nullptr));
        harbingerLabel->setText(QString());
        prophecyLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InflectWindow: public Ui_InflectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFLECTWINDOW_H
