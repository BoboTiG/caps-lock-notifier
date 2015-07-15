#-------------------------------------------------
#
# Caps Lock Notifier
# Copyleft ((C)) 2014, 2015 JMSinfo SAS
#
# Project created by QtCreator 2013-05-09T18:30:54
#
#-------------------------------------------------

TARGET       = caps-lock-notifier
SOURCES     += main.cc mainwindow.cc
HEADERS     += mainwindow.h
RESOURCES   += icons.qrc
TRANSLATIONS = l10n/fr_FR.ts

win32 {
    TARGET  += .exe
    RC_FILE += resources.rc
}

QT += core widgets
