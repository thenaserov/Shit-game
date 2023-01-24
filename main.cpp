#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen();
    QPixmap pixmap = QPixmap(":/kindshit.png");
    splash->setPixmap(pixmap.scaled(700, 700, Qt::KeepAspectRatio));
    splash->show();
    MainWindow w;
    QTimer::singleShot(500, splash, SLOT(close()));
    QTimer::singleShot(500, &w, SLOT(Show()));
    w.show();
    return a.exec();
}
