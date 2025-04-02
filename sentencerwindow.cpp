#include "sentencerwindow.h"
#include "ui_sentencerwindow.h"

SentencerWindow::SentencerWindow(QWidget *parent, const std::shared_ptr<Library> library, const std::shared_ptr<bool> isfullScreen): OriginWindow(parent, isfullScreen), ui(new Ui::SentencerWindow){
    ui->setupUi(this);
    sentencer = std::make_unique<Sentencer>(library);

    // Set all window flags at once to avoid conflicts
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Add escape key handling
    setFocusPolicy(Qt::StrongFocus);


    connect(ui->inputLineEdit, &QLineEdit::returnPressed,[this](){ //start loop of backend
        sentenceru();
    });

    connect(ui->backButton, &QPushButton::clicked,[this]{hide();});
}

SentencerWindow::~SentencerWindow(){}


void SentencerWindow::showEvent(QShowEvent* event){
    OriginWindow::showEvent(event);

    //start or refresh backend
    sentencer->start();

    //show prompt or notify user of using unsupported difficulty
    if(sentencer->getDifficulty() == 1 || sentencer->getDifficulty() == 4){
        ui->harbingerLabel->setText("unsupported difficulty, please switch");
        ui->inputLineEdit->setEnabled(false);
    } else ui->harbingerLabel->setText(QString::fromStdString(sentencer->harbinger())); //show backend output
}

void SentencerWindow::sentenceru() noexcept{
    //run the program
    if(sentencer->compare(ui->inputLineEdit->text().toStdString()) == false){
        ui->answerLabel->setStyleSheet("background-color: rgb(255, 85, 127); color: rgb(170, 0, 0);");
        ui->answerLabel->setTextFormat(Qt::RichText); // Enable rich text interpretation
        ui->answerLabel->setText("Possible sentences:<br>" + QString::fromStdString(sentencer->string_sutra(sentencer->getDifficulty())));

        QTimer::singleShot(24000, [this]() { //clear answer after while
            ui->answerLabel->clear();
            ui->answerLabel->setStyleSheet("background-color: rgb(0,0,0,0)");
        });
    }

    this->success(sentencer->success_count()); //shows compare result

    if(sentencer->success_count() >= 5){
        ui->comboLabel->setText(QString::number(sentencer->success_count()) + "x");
    } else ui->comboLabel->clear();



    //rest the backend
    sentencer->start();
    ui->harbingerLabel->setText(QString::fromStdString(sentencer->harbinger())); //show backend output
    ui->inputLineEdit->clear();
}


void SentencerWindow::success(const int success_count) noexcept {//print out success
    short int state;

    if (success_count == 1) {
        state = 1;
    }
    else if ((success_count >= 2) && (success_count < 4)) {
        state = 2;
    }
    else if ((success_count >= 4) && (success_count < 8)) {
        state = 3;
    }
    else if ((success_count >= 8) && (success_count < 16)) {
        state = 4;
    }
    else if ((success_count >= 16) && (success_count < 32)) {
        state = 5;
    }
    else if (success_count >= 32) {
        state = 6;
    }
    else if ((success_count < 1) && (success_count > -2)) {
        state = -1;
    }
    else if ((success_count <= -2) && (success_count > -4)) {
        state = -2;
    }
    else if (success_count <= -4) {
        state = -3;
    }

    if (state != 0) {
        ui->imageLabel->setProperty("state", state);
        ui->imageLabel->style()->polish(ui->imageLabel);  // Force style update

        QTimer::singleShot(15000, [this]() {
            ui->imageLabel->setProperty("state", 0);
            ui->imageLabel->style()->polish(ui->imageLabel);
        });
    }

};

