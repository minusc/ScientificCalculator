#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setFixedSize(400,500);
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();
    
    return a.exec();
}
