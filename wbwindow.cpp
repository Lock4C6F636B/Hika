#include "wbwindow.h"
#include "ui_wbwindow.h"

WBWindow::WBWindow(QWidget *parent, const std::shared_ptr<Library> library, const std::shared_ptr<bool> isfullScreen) : OriginWindow(parent, isfullScreen), ui(new Ui::WBWindow){
    ui->setupUi(this);
    word_bringer = std::make_unique<WordBringer>(library);

    // Set all window flags at once to avoid conflicts
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Add escape key handling
    setFocusPolicy(Qt::StrongFocus);


    connect(ui->inputLineEdit, &QLineEdit::returnPressed,[this](){ //start loop of backend
        wordbringer();
    });

    connect(ui->backButton, &QPushButton::clicked,[this]{hide();});
}

WBWindow::~WBWindow(){}

void WBWindow::wordbringer() noexcept{
    //run the program
    if(word_bringer->compare(ui->inputLineEdit->text().toStdString()) == false){
        ui->answerLabel->setStyleSheet("background-color: rgb(255, 85, 127); color: rgb(170, 0, 0);");
        ui->answerLabel->setText("Correct word: " + (QString::fromStdString(word_bringer->divine_truth())));

        QTimer::singleShot(8000, [this]() { //clear answer after while
            ui->answerLabel->clear();
            ui->answerLabel->setStyleSheet("background-color: rgb(0,0,0,0)");
        });
    }

    this->success(word_bringer->success_count()); //shows compare result

    if(word_bringer->success_count() >= 5){
        ui->comboLabel->setText(QString::number(word_bringer->success_count()) + "x");
    } else ui->comboLabel->clear();



    //rest the backend
    word_bringer->start();
    ui->harbingerLabel->setText(QString::fromStdString(word_bringer->harbinger())); //show backend output
    ui->inputLineEdit->clear();
}


void WBWindow::success(const int success_count) noexcept {//print out success
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
}


void WBWindow::showEvent(QShowEvent* event){
    OriginWindow::showEvent(event);

    //start or refresh backend
    word_bringer->start();
    ui->harbingerLabel->setText(QString::fromStdString(word_bringer->harbinger())); //show backend output
}
