#include <QApplication>
#include "mainwindowmtv.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindowMTV m;
    m.show();
    return QApplication::exec();
}
