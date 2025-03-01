#include "originwindow.h"


//toggle between fullscreen and window
void OriginWindow::keyPressEvent(QKeyEvent *event) {
    // F11 is commonly used for fullscreen toggle
    if (event->key() == Qt::Key_F11 && isFullScreen) {
        // Toggle fullscreen state
        *isFullScreen = !(*isFullScreen);
        // Get the parent window and adjust it
        if (QMainWindow* mainWin = qobject_cast<QMainWindow*>(parentWidget())) {
            if (*isFullScreen) {
                mainWin->showFullScreen();
            } else {
                mainWin->showNormal();
            }
        }
    }
    else if(event->key() == Qt::Key_Escape) {
        hide(); // or close() depending on what behavior you want
    };
}


//overrided show()
void OriginWindow::showEvent(QShowEvent* event){
    QWidget::showEvent(event);
    slide_in_2(); //show up animation
}

//override resizing policies
void OriginWindow::resizeEvent(QResizeEvent* event){
    QWidget::resizeEvent(event);
    adjustSize();
}

//override moving policy
void OriginWindow::moveEvent(QMoveEvent* event){
    QWidget::moveEvent(event);
    if(!isAnimating){adjustSize();}
}

//helper function to actually manage size and position universally
void OriginWindow::adjustSize(){
    if (parentWidget()) {
        // Get parent size and position
        QSize parentSize = parentWidget()->size();
        QPoint parentPos = parentWidget()->mapToGlobal(QPoint(0, 0));

        // Update geometry
        setGeometry(QRect(parentPos, parentSize));
    }
}


void OriginWindow::setOnTop(bool shouldBeOnTop) {
    if(shouldBeOnTop) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    } else {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
    }
    QWidget::show();  // Need to show() after changing window flags
}


//moderated, cool animation
void OriginWindow::slide_in() {
    if (parentWidget()) {
        // Get parent's position in global coordinates
        QPoint parentGlobalPos = parentWidget()->mapToGlobal(QPoint(0, 0));
        // Set initial position (off the right edge of parent)
        setGeometry(parentGlobalPos.x() + parentWidget()->width(), parentGlobalPos.y(),
                    parentWidget()->width(), parentWidget()->height());

        // Create animation
        QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(400);
        animation->setEasingCurve(QEasingCurve::OutCubic);


        // Start value (off right edge)
        QRect startRect(parentGlobalPos.x() + parentWidget()->width(), parentGlobalPos.y(),
                        parentWidget()->width(), parentWidget()->height());

        QRect middleRect(parentGlobalPos.x() + ((parentWidget()->width())/3), parentGlobalPos.y(),
                         parentWidget()->width(), parentWidget()->height());

        // End value (aligned with parent)
        QRect endRect(parentGlobalPos.x(), parentGlobalPos.y(),
                      parentWidget()->width(), parentWidget()->height());

        animation->setKeyValueAt(0, startRect);     // Start (0%)
        animation->setKeyValueAt(0.3, middleRect);     // Start (0%)
        animation->setKeyValueAt(1, endRect);       // End (100%)
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

//stroke inducing
void OriginWindow::slide_in_2() {
    if (parentWidget()) {
        isAnimating = true;
        QPoint parentGlobalPos = parentWidget()->mapToGlobal(QPoint(0, 0));
        setGeometry(parentGlobalPos.x() + parentWidget()->width(), parentGlobalPos.y(),
                    parentWidget()->width(), parentWidget()->height());

        // Create sequential animation group for chaining animations
        QSequentialAnimationGroup* sequence = new QSequentialAnimationGroup(this);

        // First movement animation (to middle position)
        QPropertyAnimation* firstMove = new QPropertyAnimation(this, "geometry");
        firstMove->setDuration(400); // 80% of original duration
        firstMove->setEasingCurve(QEasingCurve::OutCubic);

        QRect startRect(parentGlobalPos.x() + parentWidget()->width(), parentGlobalPos.y(),
                        parentWidget()->width(), parentWidget()->height());
        QRect middleRect(parentGlobalPos.x() - ((parentWidget()->width())/24),
                         parentGlobalPos.y() - ((parentWidget()->height())/36),
                         parentWidget()->width(), parentWidget()->height());

        firstMove->setStartValue(startRect);
        firstMove->setEndValue(middleRect);

        // Glitch effect animations
        QSequentialAnimationGroup* glitchSequence = new QSequentialAnimationGroup;

        // Create several rapid visibility toggles
        for (int i = 0; i < 3; i++) {  // 3 glitch flickers
            // Hide
            QPropertyAnimation* hide = new QPropertyAnimation(this, "windowOpacity");
            hide->setDuration(111);  // Very quick
            hide->setStartValue(1.0);
            hide->setEndValue(0.0);
            glitchSequence->addAnimation(hide);

            // Show
            QPropertyAnimation* show = new QPropertyAnimation(this, "windowOpacity");
            show->setDuration(50);  // Very quick
            show->setStartValue(0.0);
            show->setEndValue(1.0);
            glitchSequence->addAnimation(show);
        }


        // Final movement animation (to end position)
        QPropertyAnimation* finalMove = new QPropertyAnimation(this, "geometry");
        finalMove->setDuration(200);
        finalMove->setEasingCurve(QEasingCurve::OutCubic);

        QRect endRect(parentGlobalPos.x(), parentGlobalPos.y(),
                      parentWidget()->width(), parentWidget()->height());

        QRect finishingRect(parentGlobalPos.x() + ((parentWidget()->width())/48),
                            parentGlobalPos.y() - ((parentWidget()->height())/24),
                            parentWidget()->width(), parentWidget()->height());

        finalMove->setStartValue(middleRect);
        finalMove->setEndValue(endRect);

        // Add all animations to the sequence
        sequence->addAnimation(firstMove);
        sequence->addAnimation(glitchSequence);
        sequence->addAnimation(finalMove);


        // Start the entire sequence
        sequence->start(QAbstractAnimation::DeleteWhenStopped);

        connect(sequence, &QSequentialAnimationGroup::finished, [this]() {
            isAnimating = false;  // Now animation is really done
            adjustSize();  // Make final adjustment if needed
        });
    }
}

