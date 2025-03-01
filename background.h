#pragma once
#include <QWidget>
#include <memory.h>
#include <iostream>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioDevice>
#include <QAudioOutput>

namespace Ui {
class BackGround;
}


class BackGround : public QWidget{

private:
    Q_OBJECT
    std::unique_ptr<Ui::BackGround> ui;

    std::unique_ptr<QVideoWidget> videoWidget;
    std::unique_ptr<QMediaPlayer> mediaPlayer;

protected:
    //resizing policy
    void resizeEvent(QResizeEvent* event) override;

    //moving policy
    void moveEvent(QMoveEvent* event) override;

    //show() function override
    void showEvent(QShowEvent* event) override;

public:
    explicit BackGround(QWidget *parent = nullptr);
    ~BackGround();

    //helper to actually resize and position the window
    void adjustSize();

    void initializeVideo(const QString video_url);
};
