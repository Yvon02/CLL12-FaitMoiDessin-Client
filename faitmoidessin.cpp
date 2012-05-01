/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#include "faitmoidessin.h"
#include "ui_faitmoidessin.h"
#include <QtGui>
#include <QColorDialog>

FaitMoiDessin::FaitMoiDessin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaitMoiDessin)
{
    ui->setupUi(this);
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
    baCouleur.append(200);
    baCouleur.append(500);
    ui->btnChoisirCouleur->setPalette(QColor((uchar)baCouleur[0],(uchar)baCouleur[1],(uchar)baCouleur[2]));
    ui->btnChoisirCouleur->setText(QString("%0").arg((uint)baCouleur[3]));
}

