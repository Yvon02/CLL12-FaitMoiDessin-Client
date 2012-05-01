/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#include <QtGui/QApplication>
#include "faitmoidessin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaitMoiDessin w;
    w.show();
    
    return a.exec();
}
