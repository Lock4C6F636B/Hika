cmake_minimum_required(VERSION 3.16)

project(HiKa VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Multimedia
    MultimediaWidgets
)

set(PROJECT_SOURCES
        main.cpp
        hika.cpp
        hika.h
        hika.ui


        backEnd/alphabet/AlpGame.cpp
        backEnd/alphabet/AlpGame.h
        backEnd/alphabet/Alphabet.cpp
        backEnd/alphabet/Alphabet.h
        backEnd/grammar/Exceptions.h
        backEnd/grammar/TransformMap.h
        backEnd/grammar/engrammar/ENGrammar.cpp
        backEnd/grammar/engrammar/ENGrammar.h
        backEnd/grammar/jpgrammar/JPGrammar.cpp
        backEnd/grammar/jpgrammar/JPGrammar.h
        backEnd/inflectionmaster/InflectionMaster.cpp
        backEnd/inflectionmaster/InflectionMaster.h
        backEnd/library/Library.cpp
        backEnd/library/Library.h
        backEnd/library/Vocabulary.cpp
        backEnd/library/Vocabulary.h
        backEnd/sentencer/Sentencer.cpp
        backEnd/sentencer/Sentencer.h
        backEnd/wordbringer/WordBringer.cpp
        backEnd/wordbringer/WordBringer.h

        pubximl/pugiconfig.hpp
        pubximl/pugixml.cpp
        pubximl/pugixml.hpp
)


if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_executable(HiKa
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_RESOURCES}
        resources.qrc
        wbwindow.h wbwindow.cpp wbwindow.ui
        backEnd/template/Origin.h
        background.h background.cpp background.ui
        inflectwindow.cpp inflectwindow.h inflectwindow.ui
)
else()
    if(ANDROID)
        add_library(HiKa SHARED
            ${PROJECT_SOURCES}
            ${PROJECT_RESOURCES}
        )
    else()
        add_executable(HiKa
            ${PROJECT_SOURCES}
            ${PROJECT_RESOURCES}
            inflectwindow.ui wbwindow.ui
            background.cpp background.h background.ui inflectwindow.h inflectwindow.ui Inflectwindow.cpp wbwindow.cpp wbwindow.h wbwindow.ui
            resources.qrc
            sentencerwindow.cpp sentencerwindow.h sentencerwindow.ui
            backEnd/template/Origin.h
            originwindow.h originwindow.cpp
            backEnd/template/ScriptureOfWest.h
            guide/lesson_guide.txt guide/template.txt
            LICENSE
            README.md


        )
    endif()
endif()

target_include_directories(HiKa PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/alphabet
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/grammar
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/grammar/engrammar
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/grammar/jpgrammar
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/inflectionmaster
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/library
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/sentencer
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/template
    ${CMAKE_CURRENT_SOURCE_DIR}/backEnd/wordbringer
    ${CMAKE_CURRENT_SOURCE_DIR}/pubximl
)

target_link_libraries(
    HiKa PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)


if(QT_VERSION VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.HiKa)
endif()
set_target_properties(HiKa PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS HiKa
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HiKa)
endif()
