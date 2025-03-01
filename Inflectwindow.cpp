#include "inflectwindow.h"
#include "ui_inflectwindow.h"

InflectWindow::InflectWindow(QWidget *parent, const std::shared_ptr<Library> library, const std::shared_ptr<bool> isfullScreen): OriginWindow(parent, isfullScreen), ui(new Ui::InflectWindow){
    ui->setupUi(this);
    inflection_master = std::make_unique<InflectionMaster>(library);

    // Set all window flags at once to avoid conflicts
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // Add escape key handling
    setFocusPolicy(Qt::StrongFocus);


    connect(ui->inputLineEdit, &QLineEdit::returnPressed,[this](){ //start loop of app
        inflectionmaster();
    });

    connect(ui->whatButton, &QPushButton::clicked,this, &InflectWindow::morph); //output translation

    connect(ui->backButton, &QPushButton::clicked,[this]{hide();}); //quit subprogram...
}

InflectWindow::~InflectWindow(){}

void InflectWindow::showEvent(QShowEvent* event){
    OriginWindow::showEvent(event);

    //start or refresh backend
    inflection_master->start();
    ui->prophecyLabel->setText(QString::fromStdString(inflection_master->prophecy()));

    //show prompt or notify user of using unsupported difficulty
    if(inflection_master->getDifficulty() == 1 || inflection_master->getDifficulty() == 4){
        ui->harbingerLabel->setText("unsupported difficulty, please switch");
        ui->inputLineEdit->setEnabled(false);
    } else ui->harbingerLabel->setText(QString::fromStdString(inflection_master->harbinger())); //show backend output
}

void InflectWindow::inflectionmaster() noexcept{
    //run the program
    if(inflection_master->compare(ui->inputLineEdit->text().toStdString()) == false){
        ui->answerLabel->setStyleSheet("background-color: rgb(255, 85, 127); color: rgb(170, 0, 0);");
        ui->answerLabel->setText("Correct word: " + (QString::fromStdString(inflection_master->divine_truth())));

        QTimer::singleShot(12000, [this]() { //clear answer after while
            ui->answerLabel->clear();
            ui->answerLabel->setStyleSheet("background-color: rgb(0,0,0,0)");
        });
    }

    this->success(inflection_master->success_count()); //shows compare result

    if(inflection_master->success_count() >= 5){
        ui->comboLabel->setText(QString::number(inflection_master->success_count()) + "x");
    } else ui->comboLabel->clear();



    //rest the backend
    inflection_master->start();
    ui->prophecyLabel->setText(QString::fromStdString(inflection_master->prophecy()));
    ui->harbingerLabel->setText(QString::fromStdString(inflection_master->harbinger())); //show backend output
    ui->inputLineEdit->clear();
}


void InflectWindow::success(const int success_count) noexcept {//print out success
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

        QTimer::singleShot(4000, [this]() {
            ui->imageLabel->setProperty("state", 0);
            ui->imageLabel->style()->polish(ui->imageLabel);
        });
    }

};

void InflectWindow::morph() noexcept{
    ui->whatButton->setText(QString::fromStdString(inflection_master->morph()));

    QTimer::singleShot(5000, [this]() {
        ui->whatButton->setText("?");
    });
}
