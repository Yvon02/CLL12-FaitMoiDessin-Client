/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#include "faitmoidessin.h"
#include "ui_faitmoidessin.h"
#include <QtGui>
#include <QColorDialog>
#include <QTcpSocket>

FaitMoiDessin::FaitMoiDessin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaitMoiDessin)
{
    ui->setupUi(this);
    m_socket.connectToHost("172.16.10.1", 61500);
}

FaitMoiDessin::~FaitMoiDessin()
{
    delete ui;
}

void FaitMoiDessin::on_btnChoisirCouleur_clicked()
{
    QByteArray baCouleur;
    QColor m_couleur = QColorDialog::getColor(Qt::white, this);
    m_couleur.getRgb(&m_r,&m_g,&m_b);
    baCouleur.append(m_r);
    baCouleur.append(m_g);
    baCouleur.append(m_b);
    m_socket.write(baCouleur);
    //ui->btnChoisirCouleur->setPalette(QColor((uchar)baCouleur[0],(uchar)baCouleur[1],(uchar)baCouleur[2]));

}

