
/*!
 * \file main.cc
 * \brief Start of Caps Lock Notifier.
 * \author JMSinfo SAS <www.jmsinfo.co>
 * \date 2014.08.25
 *
 * Copyleft ((C)) 2014, 2015 JMSinfo SAS
 */


#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QTranslator translator;
    translator.load(QString("%1/%2.qm")
            .arg(a.applicationDirPath())
            .arg(QLocale::system().name()));
    a.installTranslator(&translator);

    MainWindow w;
    w.hide();
    return a.exec();
}
