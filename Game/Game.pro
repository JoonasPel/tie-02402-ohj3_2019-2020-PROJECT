TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    advancedworker.cpp \
    desert.cpp \
    gameeventhandler.cpp \
    main.cpp \
    mapwindow.cc \
    mine.cpp \
    objectmanager.cpp \
    player.cpp \
    windows/dialog.cpp \
    windows/gamescene.cpp

HEADERS += \
    advancedworker.h \
    desert.h \
    gameeventhandler.h \
    mapwindow.hh \
    mine.h \
    objectmanager.h \
    player.h \
    resourcelist.h \
    windows/dialog.h \
    windows/gamescene.h

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
    Images/farm_image.png \
    farmi.png \
    images/farm_image.png

RESOURCES += \
    images.qrc \
    images.qrc
