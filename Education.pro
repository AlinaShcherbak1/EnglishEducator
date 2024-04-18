QT       += core gui
QT       += core gui sql
QT       += texttospeech
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animatedlabel.cpp \
    dictionary.cpp \
    main.cpp \
    mainmenu.cpp \
    play.cpp

HEADERS += \
    additional.h \
    animatedlabel.h \
    dictionary.h \
    mainmenu.h \
    play.h

FORMS += \
    dictionary.ui \
    mainmenu.ui \
    play.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
    RC_ICONS = steering-wheel.ico



#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql

#INCLUDEPATH += $$PWD/'../../../../Program Files/MySQL/MySQL Connector C 6.1/include/mysql'
#DEPENDPATH += $$PWD/'../../../../Program Files/MySQL/MySQL Connector C 6.1/include/mysql'

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/include/mysql'
DEPENDPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/include/mysql'
