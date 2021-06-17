QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    account.cpp \
    addgoodsdialog.cpp \
    changepassworddialog.cpp \
    discountdialog.cpp \
    goods.cpp \
    loginDialog.cpp \
    main.cpp \
    mainwindow.cpp \
    manageaccountdialog.cpp \
    managegoodsdialog.cpp \
    registerdialog.cpp \
    searchgoodsdialog.cpp

HEADERS += \
    account.h \
    addgoodsdialog.h \
    changepassworddialog.h \
    discountdialog.h \
    goods.h \
    loginDialog.h \
    mainwindow.h \
    manageaccountdialog.h \
    managegoodsdialog.h \
    registerdialog.h \
    searchgoodsdialog.h

FORMS += \
    addgoodsdialog.ui \
    changepassworddialog.ui \
    discountdialog.ui \
    loginDialog.ui \
    mainwindow.ui \
    manageaccountdialog.ui \
    managegoodsdialog.ui \
    registerdialog.ui \
    searchgoodsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
