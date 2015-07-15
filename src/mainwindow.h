
/*!
 * \file mainwindow.h
 * \brief Main window headers for Caps Lock Notifier.
 * \author JMSinfo SAS <www.jmsinfo.co>
 * \date 2014.08.25
 *
 * Copyleft ((C)) 2014, 2015 JMSinfo SAS
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QLocale>
#include <QTranslator>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QObject>
#include <QTimer>
#include <windows.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QTimer *timer;
    QIcon locked;
    QIcon unlocked;
    bool caps_state;
    bool first_run;
    QString tooltip;
    QString msg;
    QIcon icon;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
private slots:
    void quit();
    void toggle_capslock();
};

#endif
