/********************************************************************************
** Form generated from reading UI file 'hika.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIKA_H
#define UI_HIKA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HiKa
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QStackedWidget *windowPages;
    QWidget *page_0;
    QGridLayout *gridLayout_2;
    QLabel *rightImageLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *buttonVerticalLayout;
    QPushButton *alphStartButton;
    QPushButton *wordbringerStartButton;
    QPushButton *inflectionmasterStartButton;
    QPushButton *sentencerStartButton;
    QPushButton *libraryButton;
    QPushButton *QuitButton;
    QLabel *logoLabel;
    QWidget *page_1;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *difficultyLabel;
    QPushButton *difficultyPushButton1;
    QPushButton *difficultyPushButton2;
    QPushButton *difficultyPushButton3;
    QPushButton *difficultyPushButton4;
    QPushButton *difficultyPushButton5;
    QPushButton *difficultyPushButton6;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesSectionButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *noSectionButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QWidget *page_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QRadioButton *lessonButton_1;
    QRadioButton *lessonButton_9;
    QRadioButton *lessonButton_17;
    QRadioButton *lessonButton_25;
    QRadioButton *lessonButton_2;
    QRadioButton *lessonButton_10;
    QRadioButton *lessonButton_18;
    QRadioButton *lessonButton_26;
    QRadioButton *lessonButton_3;
    QRadioButton *lessonButton_11;
    QRadioButton *lessonButton_19;
    QRadioButton *lessonButton_27;
    QRadioButton *lessonButton_4;
    QRadioButton *lessonButton_12;
    QRadioButton *lessonButton_20;
    QRadioButton *lessonButton_28;
    QRadioButton *lessonButton_5;
    QRadioButton *lessonButton_13;
    QRadioButton *lessonButton_21;
    QRadioButton *lessonButton_29;
    QRadioButton *lessonButton_6;
    QRadioButton *lessonButton_14;
    QRadioButton *lessonButton_22;
    QRadioButton *lessonButton_30;
    QRadioButton *lessonButton_7;
    QRadioButton *lessonButton_15;
    QRadioButton *lessonButton_23;
    QRadioButton *lessonButton_31;
    QRadioButton *lessonButton_8;
    QRadioButton *lessonButton_16;
    QRadioButton *lessonButton_24;
    QRadioButton *lessonButton_32;
    QLineEdit *lessonLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *selectionProceedButton;
    QPushButton *selectionBackButton;
    QPushButton *selectionBabyButton;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *HiKa)
    {
        if (HiKa->objectName().isEmpty())
            HiKa->setObjectName("HiKa");
        HiKa->resize(960, 540);
        HiKa->setMinimumSize(QSize(240, 135));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/\343\201\212\343\201\255\343\202\223\343\201\255\347\214\253\343\201\225\343\202\223.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HiKa->setWindowIcon(icon);
        HiKa->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(HiKa);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName("gridLayout_5");
        windowPages = new QStackedWidget(centralwidget);
        windowPages->setObjectName("windowPages");
        page_0 = new QWidget();
        page_0->setObjectName("page_0");
        gridLayout_2 = new QGridLayout(page_0);
        gridLayout_2->setObjectName("gridLayout_2");
        rightImageLabel = new QLabel(page_0);
        rightImageLabel->setObjectName("rightImageLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rightImageLabel->sizePolicy().hasHeightForWidth());
        rightImageLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(rightImageLabel, 0, 2, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 2, 1);

        buttonVerticalLayout = new QVBoxLayout();
        buttonVerticalLayout->setSpacing(0);
        buttonVerticalLayout->setObjectName("buttonVerticalLayout");
        buttonVerticalLayout->setContentsMargins(-1, -1, 0, -1);
        alphStartButton = new QPushButton(page_0);
        alphStartButton->setObjectName("alphStartButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(alphStartButton->sizePolicy().hasHeightForWidth());
        alphStartButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(26);
        alphStartButton->setFont(font);
        alphStartButton->setStyleSheet(QString::fromUtf8(""));

        buttonVerticalLayout->addWidget(alphStartButton);

        wordbringerStartButton = new QPushButton(page_0);
        wordbringerStartButton->setObjectName("wordbringerStartButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wordbringerStartButton->sizePolicy().hasHeightForWidth());
        wordbringerStartButton->setSizePolicy(sizePolicy2);
        wordbringerStartButton->setFont(font);
        wordbringerStartButton->setStyleSheet(QString::fromUtf8(""));

        buttonVerticalLayout->addWidget(wordbringerStartButton);

        inflectionmasterStartButton = new QPushButton(page_0);
        inflectionmasterStartButton->setObjectName("inflectionmasterStartButton");
        sizePolicy1.setHeightForWidth(inflectionmasterStartButton->sizePolicy().hasHeightForWidth());
        inflectionmasterStartButton->setSizePolicy(sizePolicy1);
        inflectionmasterStartButton->setFont(font);
        inflectionmasterStartButton->setStyleSheet(QString::fromUtf8(""));

        buttonVerticalLayout->addWidget(inflectionmasterStartButton);

        sentencerStartButton = new QPushButton(page_0);
        sentencerStartButton->setObjectName("sentencerStartButton");
        sizePolicy2.setHeightForWidth(sentencerStartButton->sizePolicy().hasHeightForWidth());
        sentencerStartButton->setSizePolicy(sizePolicy2);
        sentencerStartButton->setFont(font);
        sentencerStartButton->setStyleSheet(QString::fromUtf8(""));

        buttonVerticalLayout->addWidget(sentencerStartButton);

        libraryButton = new QPushButton(page_0);
        libraryButton->setObjectName("libraryButton");
        sizePolicy1.setHeightForWidth(libraryButton->sizePolicy().hasHeightForWidth());
        libraryButton->setSizePolicy(sizePolicy1);
        libraryButton->setFont(font);

        buttonVerticalLayout->addWidget(libraryButton);

        QuitButton = new QPushButton(page_0);
        QuitButton->setObjectName("QuitButton");
        sizePolicy1.setHeightForWidth(QuitButton->sizePolicy().hasHeightForWidth());
        QuitButton->setSizePolicy(sizePolicy1);
        QuitButton->setFont(font);
        QuitButton->setStyleSheet(QString::fromUtf8(""));

        buttonVerticalLayout->addWidget(QuitButton);


        gridLayout_2->addLayout(buttonVerticalLayout, 1, 1, 1, 1);

        logoLabel = new QLabel(page_0);
        logoLabel->setObjectName("logoLabel");
        sizePolicy1.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(36);
        logoLabel->setFont(font1);
        logoLabel->setStyleSheet(QString::fromUtf8("image: url(:/resources/120410702_p0_master1200.png);"));
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(logoLabel, 0, 1, 1, 1);

        windowPages->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        gridLayout_3 = new QGridLayout(page_1);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        difficultyLabel = new QLabel(page_1);
        difficultyLabel->setObjectName("difficultyLabel");
        sizePolicy1.setHeightForWidth(difficultyLabel->sizePolicy().hasHeightForWidth());
        difficultyLabel->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(difficultyLabel);

        difficultyPushButton1 = new QPushButton(page_1);
        difficultyPushButton1->setObjectName("difficultyPushButton1");
        sizePolicy1.setHeightForWidth(difficultyPushButton1->sizePolicy().hasHeightForWidth());
        difficultyPushButton1->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(22);
        difficultyPushButton1->setFont(font2);

        verticalLayout->addWidget(difficultyPushButton1);

        difficultyPushButton2 = new QPushButton(page_1);
        difficultyPushButton2->setObjectName("difficultyPushButton2");
        sizePolicy1.setHeightForWidth(difficultyPushButton2->sizePolicy().hasHeightForWidth());
        difficultyPushButton2->setSizePolicy(sizePolicy1);
        difficultyPushButton2->setFont(font2);

        verticalLayout->addWidget(difficultyPushButton2);

        difficultyPushButton3 = new QPushButton(page_1);
        difficultyPushButton3->setObjectName("difficultyPushButton3");
        sizePolicy1.setHeightForWidth(difficultyPushButton3->sizePolicy().hasHeightForWidth());
        difficultyPushButton3->setSizePolicy(sizePolicy1);
        difficultyPushButton3->setFont(font2);

        verticalLayout->addWidget(difficultyPushButton3);

        difficultyPushButton4 = new QPushButton(page_1);
        difficultyPushButton4->setObjectName("difficultyPushButton4");
        sizePolicy1.setHeightForWidth(difficultyPushButton4->sizePolicy().hasHeightForWidth());
        difficultyPushButton4->setSizePolicy(sizePolicy1);
        difficultyPushButton4->setFont(font2);

        verticalLayout->addWidget(difficultyPushButton4);

        difficultyPushButton5 = new QPushButton(page_1);
        difficultyPushButton5->setObjectName("difficultyPushButton5");
        sizePolicy1.setHeightForWidth(difficultyPushButton5->sizePolicy().hasHeightForWidth());
        difficultyPushButton5->setSizePolicy(sizePolicy1);
        difficultyPushButton5->setFont(font2);

        verticalLayout->addWidget(difficultyPushButton5);

        difficultyPushButton6 = new QPushButton(page_1);
        difficultyPushButton6->setObjectName("difficultyPushButton6");
        sizePolicy1.setHeightForWidth(difficultyPushButton6->sizePolicy().hasHeightForWidth());
        difficultyPushButton6->setSizePolicy(sizePolicy1);
        difficultyPushButton6->setFont(font2);

        verticalLayout->addWidget(difficultyPushButton6);


        gridLayout_3->addLayout(verticalLayout, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        windowPages->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        yesSectionButton = new QPushButton(page_2);
        yesSectionButton->setObjectName("yesSectionButton");
        QFont font3;
        font3.setPointSize(24);
        yesSectionButton->setFont(font3);

        horizontalLayout->addWidget(yesSectionButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        noSectionButton = new QPushButton(page_2);
        noSectionButton->setObjectName("noSectionButton");
        noSectionButton->setFont(font3);

        horizontalLayout->addWidget(noSectionButton);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 2);

        gridLayout_4->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        label = new QLabel(page_2);
        label->setObjectName("label");
        QFont font4;
        font4.setPointSize(28);
        label->setFont(font4);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 2);

        windowPages->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_6 = new QGridLayout(page_3);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lessonButton_1 = new QRadioButton(page_3);
        lessonButton_1->setObjectName("lessonButton_1");
        QFont font5;
        font5.setPointSize(12);
        lessonButton_1->setFont(font5);
        lessonButton_1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lessonButton_1->setIconSize(QSize(24, 24));
        lessonButton_1->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_1, 0, 0, 1, 1);

        lessonButton_9 = new QRadioButton(page_3);
        lessonButton_9->setObjectName("lessonButton_9");
        lessonButton_9->setFont(font5);
        lessonButton_9->setIconSize(QSize(24, 24));
        lessonButton_9->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_9, 0, 1, 1, 1);

        lessonButton_17 = new QRadioButton(page_3);
        lessonButton_17->setObjectName("lessonButton_17");
        QFont font6;
        font6.setPointSize(14);
        lessonButton_17->setFont(font6);
        lessonButton_17->setIconSize(QSize(24, 24));
        lessonButton_17->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_17, 0, 2, 1, 1);

        lessonButton_25 = new QRadioButton(page_3);
        lessonButton_25->setObjectName("lessonButton_25");
        lessonButton_25->setFont(font6);
        lessonButton_25->setIconSize(QSize(24, 24));
        lessonButton_25->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_25, 0, 3, 1, 1);

        lessonButton_2 = new QRadioButton(page_3);
        lessonButton_2->setObjectName("lessonButton_2");
        lessonButton_2->setFont(font5);
        lessonButton_2->setIconSize(QSize(24, 24));
        lessonButton_2->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_2, 1, 0, 1, 1);

        lessonButton_10 = new QRadioButton(page_3);
        lessonButton_10->setObjectName("lessonButton_10");
        lessonButton_10->setFont(font5);
        lessonButton_10->setIconSize(QSize(24, 24));
        lessonButton_10->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_10, 1, 1, 1, 1);

        lessonButton_18 = new QRadioButton(page_3);
        lessonButton_18->setObjectName("lessonButton_18");
        lessonButton_18->setFont(font6);
        lessonButton_18->setIconSize(QSize(24, 24));
        lessonButton_18->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_18, 1, 2, 1, 1);

        lessonButton_26 = new QRadioButton(page_3);
        lessonButton_26->setObjectName("lessonButton_26");
        lessonButton_26->setFont(font6);
        lessonButton_26->setIconSize(QSize(24, 24));
        lessonButton_26->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_26, 1, 3, 1, 1);

        lessonButton_3 = new QRadioButton(page_3);
        lessonButton_3->setObjectName("lessonButton_3");
        lessonButton_3->setFont(font5);
        lessonButton_3->setIconSize(QSize(24, 24));
        lessonButton_3->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_3, 2, 0, 1, 1);

        lessonButton_11 = new QRadioButton(page_3);
        lessonButton_11->setObjectName("lessonButton_11");
        lessonButton_11->setFont(font5);
        lessonButton_11->setIconSize(QSize(24, 24));
        lessonButton_11->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_11, 2, 1, 1, 1);

        lessonButton_19 = new QRadioButton(page_3);
        lessonButton_19->setObjectName("lessonButton_19");
        lessonButton_19->setFont(font6);
        lessonButton_19->setIconSize(QSize(24, 24));
        lessonButton_19->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_19, 2, 2, 1, 1);

        lessonButton_27 = new QRadioButton(page_3);
        lessonButton_27->setObjectName("lessonButton_27");
        lessonButton_27->setFont(font6);
        lessonButton_27->setIconSize(QSize(24, 24));
        lessonButton_27->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_27, 2, 3, 1, 1);

        lessonButton_4 = new QRadioButton(page_3);
        lessonButton_4->setObjectName("lessonButton_4");
        lessonButton_4->setFont(font5);
        lessonButton_4->setIconSize(QSize(24, 24));
        lessonButton_4->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_4, 3, 0, 1, 1);

        lessonButton_12 = new QRadioButton(page_3);
        lessonButton_12->setObjectName("lessonButton_12");
        lessonButton_12->setFont(font5);
        lessonButton_12->setIconSize(QSize(24, 24));
        lessonButton_12->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_12, 3, 1, 1, 1);

        lessonButton_20 = new QRadioButton(page_3);
        lessonButton_20->setObjectName("lessonButton_20");
        lessonButton_20->setFont(font6);
        lessonButton_20->setIconSize(QSize(24, 24));
        lessonButton_20->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_20, 3, 2, 1, 1);

        lessonButton_28 = new QRadioButton(page_3);
        lessonButton_28->setObjectName("lessonButton_28");
        lessonButton_28->setFont(font6);
        lessonButton_28->setIconSize(QSize(24, 24));
        lessonButton_28->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_28, 3, 3, 1, 1);

        lessonButton_5 = new QRadioButton(page_3);
        lessonButton_5->setObjectName("lessonButton_5");
        lessonButton_5->setFont(font5);
        lessonButton_5->setIconSize(QSize(24, 24));
        lessonButton_5->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_5, 4, 0, 1, 1);

        lessonButton_13 = new QRadioButton(page_3);
        lessonButton_13->setObjectName("lessonButton_13");
        lessonButton_13->setFont(font5);
        lessonButton_13->setIconSize(QSize(24, 24));
        lessonButton_13->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_13, 4, 1, 1, 1);

        lessonButton_21 = new QRadioButton(page_3);
        lessonButton_21->setObjectName("lessonButton_21");
        lessonButton_21->setFont(font6);
        lessonButton_21->setIconSize(QSize(24, 24));
        lessonButton_21->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_21, 4, 2, 1, 1);

        lessonButton_29 = new QRadioButton(page_3);
        lessonButton_29->setObjectName("lessonButton_29");
        lessonButton_29->setFont(font6);
        lessonButton_29->setIconSize(QSize(24, 24));
        lessonButton_29->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_29, 4, 3, 1, 1);

        lessonButton_6 = new QRadioButton(page_3);
        lessonButton_6->setObjectName("lessonButton_6");
        lessonButton_6->setFont(font5);
        lessonButton_6->setIconSize(QSize(24, 24));
        lessonButton_6->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_6, 5, 0, 1, 1);

        lessonButton_14 = new QRadioButton(page_3);
        lessonButton_14->setObjectName("lessonButton_14");
        lessonButton_14->setFont(font5);
        lessonButton_14->setIconSize(QSize(24, 24));
        lessonButton_14->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_14, 5, 1, 1, 1);

        lessonButton_22 = new QRadioButton(page_3);
        lessonButton_22->setObjectName("lessonButton_22");
        lessonButton_22->setFont(font6);
        lessonButton_22->setIconSize(QSize(24, 24));
        lessonButton_22->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_22, 5, 2, 1, 1);

        lessonButton_30 = new QRadioButton(page_3);
        lessonButton_30->setObjectName("lessonButton_30");
        lessonButton_30->setFont(font6);
        lessonButton_30->setIconSize(QSize(24, 24));
        lessonButton_30->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_30, 5, 3, 1, 1);

        lessonButton_7 = new QRadioButton(page_3);
        lessonButton_7->setObjectName("lessonButton_7");
        lessonButton_7->setFont(font5);
        lessonButton_7->setIconSize(QSize(24, 24));
        lessonButton_7->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_7, 6, 0, 1, 1);

        lessonButton_15 = new QRadioButton(page_3);
        lessonButton_15->setObjectName("lessonButton_15");
        lessonButton_15->setFont(font5);
        lessonButton_15->setIconSize(QSize(24, 24));
        lessonButton_15->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_15, 6, 1, 1, 1);

        lessonButton_23 = new QRadioButton(page_3);
        lessonButton_23->setObjectName("lessonButton_23");
        lessonButton_23->setFont(font6);
        lessonButton_23->setIconSize(QSize(24, 24));
        lessonButton_23->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_23, 6, 2, 1, 1);

        lessonButton_31 = new QRadioButton(page_3);
        lessonButton_31->setObjectName("lessonButton_31");
        lessonButton_31->setFont(font6);
        lessonButton_31->setIconSize(QSize(24, 24));
        lessonButton_31->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_31, 6, 3, 1, 1);

        lessonButton_8 = new QRadioButton(page_3);
        lessonButton_8->setObjectName("lessonButton_8");
        lessonButton_8->setFont(font5);
        lessonButton_8->setIconSize(QSize(24, 24));
        lessonButton_8->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_8, 7, 0, 1, 1);

        lessonButton_16 = new QRadioButton(page_3);
        lessonButton_16->setObjectName("lessonButton_16");
        lessonButton_16->setFont(font5);
        lessonButton_16->setIconSize(QSize(24, 24));
        lessonButton_16->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_16, 7, 1, 1, 1);

        lessonButton_24 = new QRadioButton(page_3);
        lessonButton_24->setObjectName("lessonButton_24");
        lessonButton_24->setFont(font6);
        lessonButton_24->setIconSize(QSize(24, 24));
        lessonButton_24->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_24, 7, 2, 1, 1);

        lessonButton_32 = new QRadioButton(page_3);
        lessonButton_32->setObjectName("lessonButton_32");
        lessonButton_32->setFont(font6);
        lessonButton_32->setIconSize(QSize(24, 24));
        lessonButton_32->setAutoExclusive(false);

        gridLayout->addWidget(lessonButton_32, 7, 3, 1, 1);


        gridLayout_6->addLayout(gridLayout, 1, 0, 1, 1);

        lessonLineEdit = new QLineEdit(page_3);
        lessonLineEdit->setObjectName("lessonLineEdit");
        lessonLineEdit->setFont(font6);

        gridLayout_6->addWidget(lessonLineEdit, 0, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        selectionProceedButton = new QPushButton(page_3);
        selectionProceedButton->setObjectName("selectionProceedButton");
        sizePolicy2.setHeightForWidth(selectionProceedButton->sizePolicy().hasHeightForWidth());
        selectionProceedButton->setSizePolicy(sizePolicy2);
        selectionProceedButton->setFont(font5);

        verticalLayout_2->addWidget(selectionProceedButton);

        selectionBackButton = new QPushButton(page_3);
        selectionBackButton->setObjectName("selectionBackButton");
        sizePolicy1.setHeightForWidth(selectionBackButton->sizePolicy().hasHeightForWidth());
        selectionBackButton->setSizePolicy(sizePolicy1);
        selectionBackButton->setFont(font5);

        verticalLayout_2->addWidget(selectionBackButton);

        selectionBabyButton = new QPushButton(page_3);
        selectionBabyButton->setObjectName("selectionBabyButton");
        sizePolicy1.setHeightForWidth(selectionBabyButton->sizePolicy().hasHeightForWidth());
        selectionBabyButton->setSizePolicy(sizePolicy1);
        selectionBabyButton->setFont(font5);

        verticalLayout_2->addWidget(selectionBabyButton);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout_6->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        windowPages->addWidget(page_3);

        gridLayout_5->addWidget(windowPages, 0, 0, 1, 1);

        HiKa->setCentralWidget(centralwidget);

        retranslateUi(HiKa);

        windowPages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HiKa);
    } // setupUi

    void retranslateUi(QMainWindow *HiKa)
    {
        HiKa->setWindowTitle(QCoreApplication::translate("HiKa", "HiKa", nullptr));
        rightImageLabel->setText(QString());
        alphStartButton->setText(QCoreApplication::translate("HiKa", "Alphabet", nullptr));
        wordbringerStartButton->setText(QCoreApplication::translate("HiKa", "Word Bringer", nullptr));
        inflectionmasterStartButton->setText(QCoreApplication::translate("HiKa", "Inflection Master", nullptr));
        sentencerStartButton->setText(QCoreApplication::translate("HiKa", "Sentencer", nullptr));
        libraryButton->setText(QCoreApplication::translate("HiKa", "Library", nullptr));
        QuitButton->setText(QCoreApplication::translate("HiKa", "Quit", nullptr));
        logoLabel->setText(QCoreApplication::translate("HiKa", "HiKa", nullptr));
        difficultyLabel->setText(QCoreApplication::translate("HiKa", "Choose difficulty", nullptr));
        difficultyPushButton1->setText(QCoreApplication::translate("HiKa", "english to romanji (japanese)", nullptr));
        difficultyPushButton2->setText(QCoreApplication::translate("HiKa", "english to hiragana (japanese)", nullptr));
        difficultyPushButton3->setText(QCoreApplication::translate("HiKa", "english to full japanese", nullptr));
        difficultyPushButton4->setText(QCoreApplication::translate("HiKa", "romanji (japanese) to english", nullptr));
        difficultyPushButton5->setText(QCoreApplication::translate("HiKa", "hiragana (japanese) to english", nullptr));
        difficultyPushButton6->setText(QCoreApplication::translate("HiKa", "full japanese to english", nullptr));
        yesSectionButton->setText(QCoreApplication::translate("HiKa", "Yes", nullptr));
        noSectionButton->setText(QCoreApplication::translate("HiKa", "No", nullptr));
        label->setText(QCoreApplication::translate("HiKa", "do you want to learn sections?", nullptr));
        lessonButton_1->setText(QCoreApplication::translate("HiKa", "1. greetings,introduction", nullptr));
        lessonButton_9->setText(QCoreApplication::translate("HiKa", "9. relative space", nullptr));
        lessonButton_17->setText(QCoreApplication::translate("HiKa", "17. fashion", nullptr));
        lessonButton_25->setText(QCoreApplication::translate("HiKa", "25. animals", nullptr));
        lessonButton_2->setText(QCoreApplication::translate("HiKa", "2. show appreciation", nullptr));
        lessonButton_10->setText(QCoreApplication::translate("HiKa", "10. weather, seasons", nullptr));
        lessonButton_18->setText(QCoreApplication::translate("HiKa", "18. life", nullptr));
        lessonButton_26->setText(QCoreApplication::translate("HiKa", "26. body", nullptr));
        lessonButton_3->setText(QCoreApplication::translate("HiKa", "3. being sorry", nullptr));
        lessonButton_11->setText(QCoreApplication::translate("HiKa", "11. numbers", nullptr));
        lessonButton_19->setText(QCoreApplication::translate("HiKa", "19. home", nullptr));
        lessonButton_27->setText(QCoreApplication::translate("HiKa", "27. computers", nullptr));
        lessonButton_4->setText(QCoreApplication::translate("HiKa", "4. shopping", nullptr));
        lessonButton_12->setText(QCoreApplication::translate("HiKa", "12. time and day", nullptr));
        lessonButton_20->setText(QCoreApplication::translate("HiKa", "20. health", nullptr));
        lessonButton_28->setText(QCoreApplication::translate("HiKa", "28. elements", nullptr));
        lessonButton_5->setText(QCoreApplication::translate("HiKa", "5. food and drink", nullptr));
        lessonButton_13->setText(QCoreApplication::translate("HiKa", "13. myself", nullptr));
        lessonButton_21->setText(QCoreApplication::translate("HiKa", "21. school", nullptr));
        lessonButton_29->setText(QCoreApplication::translate("HiKa", "29. honor", nullptr));
        lessonButton_6->setText(QCoreApplication::translate("HiKa", "6. hanging out", nullptr));
        lessonButton_14->setText(QCoreApplication::translate("HiKa", "14. people", nullptr));
        lessonButton_22->setText(QCoreApplication::translate("HiKa", "22. work", nullptr));
        lessonButton_30->setText(QCoreApplication::translate("HiKa", "30. jorogumo", nullptr));
        lessonButton_7->setText(QCoreApplication::translate("HiKa", "7. family", nullptr));
        lessonButton_15->setText(QCoreApplication::translate("HiKa", "15. activities", nullptr));
        lessonButton_23->setText(QCoreApplication::translate("HiKa", "23. future", nullptr));
        lessonButton_31->setText(QCoreApplication::translate("HiKa", "32. vampires", nullptr));
        lessonButton_8->setText(QCoreApplication::translate("HiKa", "8. location, places", nullptr));
        lessonButton_16->setText(QCoreApplication::translate("HiKa", "16. likes and dislikes", nullptr));
        lessonButton_24->setText(QCoreApplication::translate("HiKa", "24. age", nullptr));
        lessonButton_32->setText(QCoreApplication::translate("HiKa", "32. ghosts and spirits", nullptr));
        selectionProceedButton->setText(QCoreApplication::translate("HiKa", "Procceed", nullptr));
        selectionBackButton->setText(QCoreApplication::translate("HiKa", "Back", nullptr));
        selectionBabyButton->setText(QCoreApplication::translate("HiKa", "I'm baby, dont hurt me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HiKa: public Ui_HiKa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIKA_H
