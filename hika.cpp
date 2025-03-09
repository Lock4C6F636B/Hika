#include "hika.h"
#include "./ui_hika.h"

HiKa::HiKa(QWidget *parent): QMainWindow(parent), ui(new Ui::HiKa){
    ui->setupUi(this);

    setWindowTitle("HiKa");

    QPixmap cursorPixmap(":/resources/cursor.png");
    QCursor cursor(cursorPixmap);
    QApplication::setOverrideCursor(cursor);

    //initiate bool for fullscreen
    isFullScreen = std::make_shared<bool>(false);
    connect(qApp, &QApplication::applicationStateChanged,
            this, &HiKa::applicationState);

    //makes buttons reactive to enter also
    ui->wordbringerStartButton->setAutoDefault(true);
    ui->inflectionmasterStartButton->setAutoDefault(true);
    ui->libraryButton->setAutoDefault(true);
    ui->QuitButton->setAutoDefault(true);

    //create WBWindow as child but don't show it yet
    connect(ui->wordbringerStartButton, &QPushButton::clicked, this, &HiKa::wordbringer);

    // Create InflectWindow as child but don't show it yet
    connect(ui->inflectionmasterStartButton, &QPushButton::clicked, this, &HiKa::inflection_master);

    // Create SentencerWindow as child but don't show it yet
    connect(ui->sentencerStartButton, &QPushButton::clicked, this, &HiKa::sentencer);

    //initialize library
    connect(ui->libraryButton, &QPushButton::clicked,[this](){
        libInitialize = libraryInitialized::library;
        init_library();
    });

    //quit
    connect(ui->QuitButton, &QPushButton::clicked,this, &QApplication::quit);
}

HiKa::~HiKa(){}

//toggle between fullscreen and window
void HiKa::keyPressEvent(QKeyEvent *event) {
    // F11 is commonly used for fullscreen toggle
    if (event->key() == Qt::Key_F11) {
        *isFullScreen ? showNormal() : showFullScreen();
        *isFullScreen = !(*isFullScreen);
    }
}


//resize policy reimplementation
void HiKa::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);

    // Calculate font size relative to window height
    int fontSize = height() / 10; // Adjust divisor to taste
    QFont font = ui->logoLabel->font();
    font.setPointSize(fontSize);
    ui->logoLabel->setFont(font);

    // Resize overlay if it exists
    if (wordbringerWindow) {
        wordbringerWindow->adjustSize();
    }

    if (inflectionWindow) {
        inflectionWindow->adjustSize();
    }

    if(sentencerWindow){
        sentencerWindow->adjustSize();
    }
}

void HiKa::moveEvent(QMoveEvent* event){
    // Resize overlay if it exists
    if (wordbringerWindow) {
        wordbringerWindow->adjustSize();
    }

    if (inflectionWindow) {
        inflectionWindow->adjustSize();
    }

    if(sentencerWindow){
        sentencerWindow->adjustSize();
    }
}

// Add this method to HiKa class:
void HiKa::applicationState(Qt::ApplicationState state) {
    active_focus.applicationFocus = (state == Qt::ApplicationActive);

    // Update window states based on new focus state
    if (wordbringerWindow && active_focus.wordbringerFocus) {
        wordbringerWindow->setOnTop(active_focus.applicationFocus);
    }
    if (inflectionWindow && active_focus.inflectionFocus) {
        //inflectionWindow->setOnTop(active_focus.applicationFocus);
    }
    if (sentencerWindow && active_focus.sentencerFocus) {
        //sentencerWindow->setOnTop(active_focus.applicationFocus);
    }
}


void HiKa::wordbringer(){
    // Disconnect any existing connections first
    disconnect(this, &HiKa::wordbringerReady, this, nullptr);

    // Make new connection BEFORE potentially emitting the signal
    connect(this, &HiKa::wordbringerReady, this, [this]() {
        if (!wordbringerWindow) {
            wordbringerWindow = std::make_unique<WBWindow>(this,library,isFullScreen);
        } else {
            wordbringerWindow->updateLib(library);
        }
        wordbringerWindow->show();
    });



    // Now handle library initialization or emit signal
    if(!library || library->empty()) {
        libInitialize = libraryInitialized::wordbringer;
        init_library();
    } else emit wordbringerReady();
}


void HiKa::inflection_master(){
    // Disconnect any existing connections first
    disconnect(this, &HiKa::inflectionReady, this, nullptr);

    // Make new connection BEFORE potentially emitting the signal
    connect(this, &HiKa::inflectionReady, this, [this]() {
        if (!inflectionWindow) {
            inflectionWindow = std::make_unique<InflectWindow>(this,library,isFullScreen);
            if(engrammar::exceptions_empty()){
                engrammar::initialize();
            }
            if(jpgrammar::exceptions_empty()){
                jpgrammar::initialize(library->getDifficulty());
            }
        }
        else {
            inflectionWindow->updateLib(library);
        }
        inflectionWindow->show();
    });



    // Now handle library initialization or emit signal
    if(!library || library->empty()) {
        libInitialize = libraryInitialized::inflection_master;
        init_library();
    } else emit inflectionReady();
}


void HiKa::sentencer(){
    // Disconnect any existing connections first
    disconnect(this, &HiKa::sentencerReady, this, nullptr);

    // Make new connection BEFORE potentially emitting the signal
    connect(this, &HiKa::sentencerReady, this, [this]() {
        if (!sentencerWindow) {
            sentencerWindow = std::make_unique<SentencerWindow>(this,library,isFullScreen);
            if(engrammar::exceptions_empty()){
                engrammar::initialize();
            }
            if(jpgrammar::exceptions_empty()){
                jpgrammar::initialize(library->getDifficulty());
            }
        }
        else {
            sentencerWindow->updateLib(library);
        }
        sentencerWindow->show();
    });



    // Now handle library initialization or emit signal
    if(!library || library->empty()) {
        libInitialize = libraryInitialized::sentencer;
        init_library();
    } else emit sentencerReady();
}


//initiate library
int HiKa::init_library() {
    // Initialize or clear it to prepare for loading of data
    if (!library) {
        library = std::make_shared<Library>();
    } else {
        library->clear();
    }


    // Show difficulty selection page
    ui->windowPages->setCurrentIndex(1);


    //disconnect buttons to stopping from establishing multiple connections
    disconnect(ui->difficultyPushButton1, &QPushButton::clicked,this,nullptr);
    disconnect(ui->difficultyPushButton2, &QPushButton::clicked,this,nullptr);
    disconnect(ui->difficultyPushButton3, &QPushButton::clicked,this,nullptr);
    disconnect(ui->difficultyPushButton4, &QPushButton::clicked,this,nullptr);
    disconnect(ui->difficultyPushButton5, &QPushButton::clicked,this,nullptr);
    disconnect(ui->difficultyPushButton6, &QPushButton::clicked,this,nullptr);

    //makes buttons reactive to enter also
    ui->difficultyPushButton1->setAutoDefault(true);
    ui->difficultyPushButton2->setAutoDefault(true);
    ui->difficultyPushButton3->setAutoDefault(true);
    ui->difficultyPushButton4->setAutoDefault(true);
    ui->difficultyPushButton5->setAutoDefault(true);
    ui->difficultyPushButton6->setAutoDefault(true);

    // Connect difficulty buttons
    connect(ui->difficultyPushButton1, &QPushButton::clicked, this, [this]() {
        handleDifficultySelection(1);
    });
    connect(ui->difficultyPushButton2, &QPushButton::clicked, this, [this]() {
        handleDifficultySelection(2);
    });
    connect(ui->difficultyPushButton3, &QPushButton::clicked, this, [this]() {
        handleDifficultySelection(3);
    });
    connect(ui->difficultyPushButton4, &QPushButton::clicked, this, [this]() {
        handleDifficultySelection(4);
    });
    connect(ui->difficultyPushButton5, &QPushButton::clicked, this, [this]() {
        handleDifficultySelection(5);
    });
    connect(ui->difficultyPushButton6, &QPushButton::clicked, this, [this]() {
        handleDifficultySelection(6);
    });


    return 0;
}


//set difficulty in backend, set selection dialog
void HiKa::handleDifficultySelection(int Difficulty) {
    if (Difficulty < 1 || Difficulty > 6) {
        std::cout << "Invalid difficulty selected" << std::endl;
        return;
    }

    library->setDifficulty(Difficulty);  // Store as class member
    ui->windowPages->setCurrentIndex(2);  // Show section dialog page

    //disconnect buttons to stopping from establishing multiple connections
    disconnect(ui->yesSectionButton, &QPushButton::clicked, this,nullptr);
    disconnect(ui->noSectionButton, &QPushButton::clicked, this,nullptr);

    //makes buttons reactive to enter also
    ui->yesSectionButton->setAutoDefault(true);
    ui->noSectionButton->setAutoDefault(true);

    //connect section selection buttons
    connect(ui->yesSectionButton, &QPushButton::clicked, this, [this]() {
        handleSectionSelection();
    });
    connect(ui->noSectionButton, &QPushButton::clicked, this, [this]() {
        handleFinal(false); //skip selection, user wants to load everything
    });
}

void HiKa::handleSectionSelection() {
    //pivotals to fill the vector first, whole thing relies on overriding to true
    sections.resize(20, false); //no need to clear... settings everything to false already does the work

    //set to selection page
    ui->windowPages->setCurrentIndex(3);


    //disconnect buttons to stopping from establishing multiple connections
    disconnect(ui->selectionProceedButton, &QPushButton::clicked, this,nullptr);
    disconnect(ui->selectionBackButton, &QPushButton::clicked, this,nullptr);


    connect(ui->selectionProceedButton,&QPushButton::clicked,[this](){
        checkLessonButtons(); //load from selected buttons
        checkLessonLine(); //load from command line
        handleFinal(true); //if user has procceeded release from this page
    });

    connect(ui->selectionBackButton, &QPushButton::clicked,[this](){
        ui->windowPages->setCurrentIndex(0);
    });
}



void HiKa::handleFinal(const bool userSelection){
    // Load library with appropriate settings
    if (userSelection) {
        library->load(library->getDifficulty(), sections);        
    } else {
        library->load(library->getDifficulty());
    }


    switch(libInitialize){
    case libraryInitialized::wordbringer:
        emit wordbringerReady();
        break;
    case libraryInitialized::inflection_master:
        emit inflectionReady();
        break;
    case libraryInitialized::sentencer:
        emit sentencerReady();
        break;
    case libraryInitialized::library:
        break;
    }

    //debug to see loaded selection
    for(size_t i= 0; i < sections.size();i++){
        if(sections[i]){std::cerr<<"lesson "<<i+1<<" loaded, ";}
    }
    std::cerr<<"\n"<<std::endl;

    //return to main page
    ui->windowPages->setCurrentIndex(0);
}



void HiKa::checkLessonButtons() {
    for(QRadioButton* button : findChildren<QRadioButton*>()) {
        if(button->objectName().startsWith("lessonButton")) {
            QString numStr = button->objectName().mid(13); // Skip "lessonButton"
            bool ok;
            int lessonNum = numStr.toInt(&ok);

            if(ok && lessonNum >= 1 && lessonNum <= sections.size() && button->isChecked()) {
                sections[lessonNum-1] = true;  // Just set the state directly
            }
        }
    }
}


void HiKa::checkLessonLine() {
    if(ui->lessonLineEdit->text().isEmpty()) return;

    QString input = ui->lessonLineEdit->text().simplified(); // Remove extra whitespace

    QStringList parts = input.split(QRegularExpression("[,\\s]+"), Qt::SkipEmptyParts); //

    for(const QString& part : parts) {
        if(part.contains('-')) {
            // Handle range (e.g., "1-5")
            QStringList range = part.split('-');
            if(range.size() == 2) {
                bool okStart, okEnd;
                int start = range[0].toInt(&okStart);
                int end = range[1].toInt(&okEnd);

                if(okStart && okEnd && start > 0 && end <= sections.size() && start <= end) {
                    for(int i = start; i <= end; i++) {
                        sections[i-1] = true;
                    }
                }
            }
        } else {
            // Handle single number
            bool ok;
            int lesson = part.toInt(&ok);
            if(ok && lesson > 0 && lesson <= sections.size()) {
                sections[lesson-1] = true;
            }
        }
    }
}
