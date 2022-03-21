#include <QApplication>
#include "notepadMTV.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Notepad n;
    n.show();
    return a.exec();
}
