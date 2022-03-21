#include <QApplication>
#include <QPushButton>
#include "mainwindowMTV.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWindow m;
    m.show();
    return QApplication::exec();
}
