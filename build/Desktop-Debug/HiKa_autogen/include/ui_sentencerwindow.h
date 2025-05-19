/********************************************************************************
** Form generated from reading UI file 'sentencerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENTENCERWINDOW_H
#define UI_SENTENCERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SentencerWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *answerLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *imageLabel;
    QPushButton *backButton;
    QLabel *comboLabel;
    QLineEdit *inputLineEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *harbingerLabel;
    QLabel *pickLabel;

    void setupUi(QWidget *SentencerWindow)
    {
        if (SentencerWindow->objectName().isEmpty())
            SentencerWindow->setObjectName("SentencerWindow");
        SentencerWindow->resize(960, 540);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SentencerWindow->sizePolicy().hasHeightForWidth());
        SentencerWindow->setSizePolicy(sizePolicy);
        SentencerWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(SentencerWindow);
        gridLayout->setObjectName("gridLayout");
        answerLabel = new QLabel(SentencerWindow);
        answerLabel->setObjectName("answerLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(answerLabel->sizePolicy().hasHeightForWidth());
        answerLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(18);
        answerLabel->setFont(font);
        answerLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0,0);"));

        gridLayout->addWidget(answerLabel, 7, 0, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 0, 2, 2);

        imageLabel = new QLabel(SentencerWindow);
        imageLabel->setObjectName("imageLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);
        imageLabel->setStyleSheet(QString::fromUtf8("background:transparent;"));

        gridLayout->addWidget(imageLabel, 0, 3, 10, 2);

        backButton = new QPushButton(SentencerWindow);
        backButton->setObjectName("backButton");
        QFont font1;
        font1.setPointSize(20);
        backButton->setFont(font1);
        backButton->setStyleSheet(QString::fromUtf8("background: transparent;"));

        gridLayout->addWidget(backButton, 0, 0, 1, 1);

        comboLabel = new QLabel(SentencerWindow);
        comboLabel->setObjectName("comboLabel");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(comboLabel->sizePolicy().hasHeightForWidth());
        comboLabel->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(32);
        comboLabel->setFont(font2);
        comboLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 192, 243);\n"
"background-color: rgb(0, 0, 0, 0);"));
        comboLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);

        gridLayout->addWidget(comboLabel, 8, 2, 2, 1);

        inputLineEdit = new QLineEdit(SentencerWindow);
        inputLineEdit->setObjectName("inputLineEdit");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(inputLineEdit->sizePolicy().hasHeightForWidth());
        inputLineEdit->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("mikachan-puchi")});
        font3.setPointSize(22);
        inputLineEdit->setFont(font3);
        inputLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 181, 243);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(inputLineEdit, 5, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 3);

        harbingerLabel = new QLabel(SentencerWindow);
        harbingerLabel->setObjectName("harbingerLabel");
        sizePolicy2.setHeightForWidth(harbingerLabel->sizePolicy().hasHeightForWidth());
        harbingerLabel->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("mikachan-puchiB")});
        font4.setPointSize(22);
        harbingerLabel->setFont(font4);
        harbingerLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 181, 243);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(harbingerLabel, 3, 0, 2, 3);

        pickLabel = new QLabel(SentencerWindow);
        pickLabel->setObjectName("pickLabel");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font5.setPointSize(18);
        pickLabel->setFont(font5);
        pickLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0, 0);\n"
"color: rgb(170, 0, 0);"));

        gridLayout->addWidget(pickLabel, 2, 0, 1, 3);


        retranslateUi(SentencerWindow);

        QMetaObject::connectSlotsByName(SentencerWindow);
    } // setupUi

    void retranslateUi(QWidget *SentencerWindow)
    {
        SentencerWindow->setWindowTitle(QCoreApplication::translate("SentencerWindow", "Form", nullptr));
        answerLabel->setText(QString());
        imageLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("SentencerWindow", "Back", nullptr));
        comboLabel->setText(QString());
        harbingerLabel->setText(QString());
        pickLabel->setText(QCoreApplication::translate("SentencerWindow", "Picked Sentence:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SentencerWindow: public Ui_SentencerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENTENCERWINDOW_H
