#include <QtGui/QApplication>
#include "faitmoidessin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaitMoiDessin w;
    w.show();
    
    return a.exec();
}
