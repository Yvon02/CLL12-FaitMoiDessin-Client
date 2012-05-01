/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#ifndef FAITMOIDESSIN_H
#define FAITMOIDESSIN_H

#include <QMainWindow>
#include <QColor>
#include <QTcpSocket>


namespace Ui {
class FaitMoiDessin;
}

class FaitMoiDessin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FaitMoiDessin(QWidget *parent = 0);
    ~FaitMoiDessin();
    
private slots:
    void on_btnChoisirCouleur_clicked();

private:
    Ui::FaitMoiDessin *ui;
    QColor m_couleur;
    QTcpSocket m_socket;
    int m_r;
    int m_g;
    int m_b;
};

#endif // FAITMOIDESSIN_H
