#include "background.h"
#include "ui_background.h"

BackGround::BackGround(QWidget *parent): QWidget(parent), ui(new Ui::BackGround){
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    // Add these lines to ensure it stays behind the parent window
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);  // Prevents window from taking focus
    setWindowFlag(Qt::WindowStaysOnBottomHint); // Forces window to stay on bottom
    lower(); // Makes sure it's behind other windows
}

BackGround::~BackGround(){}


//overrided show()
void BackGround::showEvent(QShowEvent* event){
    QWidget::showEvent(event);
    // maybe later slide_in_2(); //show up animation

}

//override resizing policies
void BackGround::resizeEvent(QResizeEvent* event){
    QWidget::resizeEvent(event);
    adjustSize();
}

//override moving policy
void BackGround::moveEvent(QMoveEvent* event){
    QWidget::moveEvent(event);
    adjustSize();
}


//helper function to actually manage size and position universally
void BackGround::adjustSize(){
    if (parentWidget()) {
        // Get parent size and position
        QSize parentSize = parentWidget()->size();
        QPoint parentPos = parentWidget()->mapToGlobal(QPoint(0, 0));

        // Update geometry
        setGeometry(QRect(parentPos, parentSize));
    }
}


void BackGround::initializeVideo(const QString video_url){
    // Create and configure video widget
    videoWidget = std::make_unique<QVideoWidget>(this);
    videoWidget->setGeometry(0, 0, width(), height());
    videoWidget->lower(); // Put it behind other widgets

    //auto audioOutput = new QAudioOutput(this);
    //mediaPlayer->setAudioOutput(audioOutput);
    //audioOutput->setVolume(1.0);  // Set volume to 100%

    // Create and configure media player
    mediaPlayer = std::make_unique<QMediaPlayer>();
    mediaPlayer->setVideoOutput(videoWidget.get());

    // Set the video source using qrc path
    mediaPlayer->setSource(QUrl(video_url));

    // Configure video widget

    videoWidget->setStyleSheet("background-color: transparent;");

    // Set playback options
    mediaPlayer->setLoops(QMediaPlayer::Infinite);

    std::cerr<<"playing"<<std::endl;
    // Start playing
    mediaPlayer->play();
}
