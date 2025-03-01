#pragma once
#include "Sentencer.h"
#include "originwindow.h"

namespace Ui {
class SentencerWindow;
}

class SentencerWindow: public OriginWindow{
private:
    Q_OBJECT
    std::unique_ptr<Ui::SentencerWindow> ui;
    //inherited std::shared_ptr<bool> isFullScreen;
    //inherited bool isAnimating;

    //backend
    std::unique_ptr<Sentencer> sentencer;

protected:
    //show() function override
    virtual void showEvent(QShowEvent* event) override;

public:
    explicit SentencerWindow(QWidget *parent = nullptr, const std::shared_ptr<Library> library = nullptr, const std::shared_ptr<bool> isfullScreen = nullptr);

    ~SentencerWindow();


    //communicate with backend
    void sentenceru() noexcept;
    //shows success
    void success(const int success_count) noexcept override;

    inline void updateLib(const std::shared_ptr<Library> library) noexcept {sentencer->updateLib(library);}
};
