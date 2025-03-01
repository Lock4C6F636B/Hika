#pragma once
#include "WordBringer.h"
#include "originwindow.h"
#include <memory>

namespace Ui {
class WBWindow;
}

class WBWindow : public OriginWindow{
private:
    Q_OBJECT
    std::unique_ptr<Ui::WBWindow> ui;
    //inherited std::shared_ptr<bool> isFullScreen;
    //inherited bool isAnimating;

    //backend
    std::unique_ptr<WordBringer> word_bringer;

protected:
    //show() function override
    virtual void showEvent(QShowEvent* event) override;

public:
    explicit WBWindow(QWidget *parent = nullptr, const std::shared_ptr<Library> library = nullptr, const std::shared_ptr<bool> isfullScreen = nullptr);

    ~WBWindow();

    //communicate with backend
    void wordbringer() noexcept;
    //shows success
    void success(const int success_count) noexcept override;

    inline void updateLib(const std::shared_ptr<Library> library) noexcept {word_bringer->updateLib(library);}
};
