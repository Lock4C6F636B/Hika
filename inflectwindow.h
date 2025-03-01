#pragma once
#include "InflectionMaster.h"
#include "originwindow.h"

namespace Ui {
class InflectWindow;
}

class InflectWindow : public OriginWindow{
private:
    Q_OBJECT
    std::unique_ptr<Ui::InflectWindow> ui;
    //inherited std::shared_ptr<bool> isFullScreen;
    //inherited bool isAnimating;

    //backend
    std::unique_ptr<InflectionMaster> inflection_master;

protected:
    //show() function override
    virtual void showEvent(QShowEvent* event) override;

public:
    explicit InflectWindow(QWidget *parent = nullptr, const std::shared_ptr<Library> library = nullptr, const std::shared_ptr<bool> isfullScreen = nullptr);

    ~InflectWindow();

    //communicate with backend
    void inflectionmaster() noexcept;
    //shows success
    void success(const int success_count) noexcept override;

    void morph() noexcept;

    inline void updateLib(const std::shared_ptr<Library> library) noexcept {inflection_master->updateLib(library);}
};
