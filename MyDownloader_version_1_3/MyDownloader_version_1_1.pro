QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deepseek_client.cpp \
    dialog.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowai.cpp \
    signup.cpp

HEADERS += \
    deepseek_client.h \
    dialog.h \
    login.h \
    mainwindow.h \
    mainwindowai.h \
    signup.h

FORMS += \
    dialog.ui \
    login.ui \
    mainwindow.ui \
    mainwindowai.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    help.qrc \
    pics.qrc
RC_ICONS = icon.ico
