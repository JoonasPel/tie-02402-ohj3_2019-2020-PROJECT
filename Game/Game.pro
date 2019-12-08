TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    buildings/mine.cpp \
    buildings/nuclearplant.cpp \
    buildings/studentoutpost.cpp \
    gameeventhandler.cpp \
    main.cpp \
    mapitem.cpp \
    mapwindow.cc \
    objectmanager.cpp \
    player.cpp \
    tiles/desert.cpp \
    tiles/rocky_mountains.cpp \
    tiles/water.cpp \
    windows/dialog.cpp \
    windows/gamescene.cpp \
    workers/advancedworker.cpp \
    workers/eliteworker.cpp \
    workers/soldier.cpp

HEADERS += \
    buildings/mine.h \
    buildings/nuclearplant.h \
    buildings/studentoutpost.h \
    gameeventhandler.h \
    mapitem.h \
    mapwindow.hh \
    objectmanager.h \
    player.h \
    resourcelist.h \
    tiles/desert.h \
    tiles/rocky_mountains.h \
    tiles/water.h \
    windows/dialog.h \
    windows/gamescene.h \
    workers/advancedworker.h \
    workers/eliteworker.h \
    workers/soldier.h

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    dialog.ui \
    mapwindow.ui

DISTFILES += \

    farmi.png \

RESOURCES += \
    images.qrc \
    images.qrc
