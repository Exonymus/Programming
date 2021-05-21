#include "mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QDir::currentPath();
    MainWindow w;
    a.setWindowIcon(QIcon(":/StartMenu/Assets/app_icon.png"));
    w.show();
    return a.exec();
}
