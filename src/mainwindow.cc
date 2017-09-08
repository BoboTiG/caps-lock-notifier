
/*!
 * \file mainwindow.cc
 * \brief Main window for Caps Lock Notifier.
 * \author JMSinfo SAS <www.jmsinfo.co>
 * \date 2015.11.19
 *
 * Copyleft ((C)) 2014, 2015 JMSinfo SAS
 */


#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    trayIcon(new QSystemTrayIcon(this)),
    trayMenu(new QMenu(this)),
    timer(new QTimer(this)),
    locked(QIcon(":/res/locked.svg")),
    unlocked(QIcon(":/res/unlocked.svg")),
    caps_state(false),
    first_run(true),
    tooltip(QString()),
    msg(QString()),
    icon(QIcon())
#ifdef __linux__
    ,
    display(XOpenDisplay(0))
#endif
{
    trayMenu->addAction(QIcon(":/res/exit.svg"), tr("Exit"), this, SLOT(quit()));
    trayIcon->setContextMenu(trayMenu);
    toggle_capslock();
    connect(timer, SIGNAL(timeout()), this, SLOT(toggle_capslock()));
    timer->start(100);
}

MainWindow::~MainWindow() {}

void MainWindow::quit()
{
    this->close();
}

void MainWindow::toggle_capslock()
{
    bool new_state;

#ifdef __linux__
    // https://stackoverflow.com/questions/9009775/using-getkeystatevk-capital-1-in-linux
    unsigned int n = 0;
    XkbGetIndicatorState(display, XkbUseCoreKbd, &n);
    new_state = n & 0x01;
#elif defined _WIN32 || defined _WIN64
    // https://stackoverflow.com/questions/2968336/qt-password-field
    new_state = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
#endif

    if ( new_state != caps_state || first_run ) {
        if (new_state) {
            tooltip = tr("Caps lock is ON.");
            icon = locked;
            msg = tr("Locked!");
        } else {
            tooltip = tr("Caps lock is OFF.");
            icon = unlocked;
            msg = tr("Unlocked!");
        }
        // http://qt-project.org/doc/qt-5/qsystemtrayicon.html#showMessage
        trayIcon->setToolTip(tooltip);
        trayIcon->setIcon(icon);
        trayIcon->showMessage(tr("Caps lock status: "), msg);
        if ( !trayIcon->isVisible() ) {
            trayIcon->show();
        }
        caps_state = new_state;
        first_run = false;
    }
}
