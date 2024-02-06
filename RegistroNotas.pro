QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ingresoestudiantesform.cpp \
    main.cpp \
    menuprincipal.cpp

HEADERS += \
    ingresoestudiantesform.h \
    menuprincipal.h

FORMS += \
    ingresoestudiantesform.ui \
    menuprincipal.ui
TRANSLATIONS += \
    de_de.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
