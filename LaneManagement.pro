QT += core gui sql concurrent network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = LaneManagement
TEMPLATE = app

CONFIG += skip_target_version_ext

QMAKE_TARGET_COPYRIGHT = "Copyright 2021 Shen zhen zhong bai yuan"

VERSION = 1.0.0.1_2206082310

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddialog.cpp \
    #audioserver.cpp \
    avdioserverform.cpp \
    database.cpp \
    databaseform.cpp \
    filterdialog.cpp \
    lockdialog.cpp \
    logform.cpp \
    main.cpp \
    mainwindow.cpp \
    platecl.cpp \
    postdata.cpp \
    showdialog.cpp

HEADERS += \
    adddialog.h \
    #audioserver.h \
    avdioserverform.h \
    database.h \
    databaseform.h \
    filterdialog.h \
    inc/VzClientSDK_CommonDefine.h \
    inc/VzClientSDK_FaceDefine.h \
    inc/VzClientSDK_LPDefine.h \
    inc/VzClientSDK_ParkDefine.h \
    inc/VzLPRClientSDK.h \
    inc/VzLPRClientSDKDefine.h \
    inc/VzLPRClientSDK_WhiteList.h \
    inc/VzLPRClientSDK_WhiteListDefine.h \
    inc/VzLPRDiscardClientSDK.h \
    inc/VzLPRFaceClientSDK.h \
    inc/VzLPRParkClientSDK.h \
    inc/VzLPRRoadsiteClientSDK.h \
    lockdialog.h \
    logform.h \
    mainwindow.h \
    platecl.h \
    postdata.h \
    showdialog.h

FORMS += \
    adddialog.ui \
    avdioserverform.ui \
    databaseform.ui \
    filterdialog.ui \
    lockdialog.ui \
    logform.ui \
    mainwindow.ui \
    mainwindow.ui \
    showdialog.ui

TRANSLATIONS += \
    LaneManagement_en_AS.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res.rc

RESOURCES += \
    ui.qrc

RC_FILE = res.rc

MOC_DIR=tmp/moc
RCC_DIR=tmp/rcc
UI_DIR=tmp/ui
OBJECTS_DIR=tmp/obj

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/LogController/ -lCc1_Logging
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/LogController/ -lCc1_Logging
else:unix:!macx: LIBS += -L$$PWD/LogController/ -lCc1_Logging

INCLUDEPATH += $$PWD/LogController/release
DEPENDPATH += $$PWD/LogController/release

win32: LIBS += -L$$PWD/lib/ -lVzLPRSDK

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

#win32: LIBS += -L$$PWD/SDK32/lib/ -lVzLPRSDK

#INCLUDEPATH += $$PWD/SDK32
#DEPENDPATH += $$PWD/SDK32
