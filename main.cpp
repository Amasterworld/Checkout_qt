#include "checkout.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckOut w;
    w.show();
    return a.exec();
}
