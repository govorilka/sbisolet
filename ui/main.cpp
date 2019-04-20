#include <QApplication>
#include <QFrame>

#include "precomp.h"
#include "mycanvas.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
