QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 app_bundle
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttonhoverwatcher.cpp \
    cupswindow.cpp \
    graphics.cpp \
    main.cpp \
    mainwindow.cpp \
    moneywindow.cpp \
    safewindow.cpp

ICON = app_icons.icns

HEADERS += \
    buttonhoverwatcher.h \
    cupswindow.h \
    graphics.h \
    mainwindow.h \
    moneywindow.h \
    safewindow.h

FORMS += \
    cupswindow.ui \
    mainwindow.ui \
    moneywindow.ui \
    safewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
