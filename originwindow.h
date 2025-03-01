#pragma once
#include <QWidget>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QDebug>
#include <QMainWindow>
#include <QStyle>
#include <QTimer>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

class OriginWindow : public QWidget{
private:
    Q_OBJECT
    std::shared_ptr<bool> isFullScreen;
    bool isAnimating;

protected:
    //key input reaction, contais F11 for fullscreen
    virtual void keyPressEvent(QKeyEvent *event) override;

    //resizing policy
    virtual void resizeEvent(QResizeEvent* event) override;

    //moving policy
    virtual void moveEvent(QMoveEvent* event) override;

    //show() function override
    virtual void showEvent(QShowEvent* event) override;

public:
    explicit OriginWindow(QWidget *parent = nullptr, const std::shared_ptr<bool> isfullScreen = nullptr) : QWidget(parent), isFullScreen(isfullScreen){}; //not intended as object, just template to encapsulate
    virtual ~OriginWindow() = default;

    //helper to actually resize and position the window
    virtual void adjustSize();

    virtual void setOnTop(bool shouldBeOnTop);

    virtual void slide_in();
    virtual void slide_in_2();

    //shows success
    virtual void success(const int success_count) noexcept = 0;

};
