#pragma once
//#include "background.h"
#include "wbwindow.h"
#include "inflectwindow.h"
#include "sentencerwindow.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QRegularExpression>
#include <QDebug>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class HiKa;
}
QT_END_NAMESPACE


enum libraryInitialized{ //to show windows only when library is ready
    library, wordbringer, inflection_master, sentencer
};

struct activeFocus{
    bool applicationFocus = true;
    bool wordbringerFocus, inflectionFocus, sentencerFocus;
};


class HiKa : public QMainWindow{
private:
    Q_OBJECT
    std::unique_ptr<Ui::HiKa> ui;
    std::shared_ptr<bool> isFullScreen;
    activeFocus active_focus;
    std::string input; //user input
    libraryInitialized libInitialize; //to determine who is initializing library
    std::vector<bool> sections; //controls which sections should load

    //backend
    std::shared_ptr<Library> library;

    //frontend
    std::unique_ptr<WBWindow> wordbringerWindow;
    std::unique_ptr<InflectWindow> inflectionWindow;
    std::unique_ptr<SentencerWindow> sentencerWindow;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;
    void moveEvent(QMoveEvent* event) override;

public:
    HiKa(QWidget *parent = nullptr);
    ~HiKa();

    void wordbringer();
    void inflection_master();
    void sentencer();

    //initiating library
    int init_library();

    //initiating alphabet
    int init_alphabet();

    void checkLessonButtons();

    void checkLessonLine();

    void applicationState(Qt::ApplicationState state);

private slots:
    void handleDifficultySelection(const int difficulty);
    void handleSectionSelection();
    void handleFinal(const bool userSelection);

signals:
    //signal that library is initialized,
    void wordbringerReady();
    void inflectionReady();
    void sentencerReady();
};

