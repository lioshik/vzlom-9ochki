вQT -= gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        barchanger.cpp \
        dialog.cpp \
        main.cpp \
        uncloseable.cpp

# Default rules for deployment.
include(gifs/)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    barchanger.h \
    dialog.h \
    uncloseable.h

DISTFILES += \
    gifs/3073826_original.mp4 \
    gifs/putin1.gif

RESOURCES += \
    res.qrc
