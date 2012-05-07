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
#include <QPainter>

FaitMoiDessin::FaitMoiDessin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaitMoiDessin)
{
    ui->setupUi(this);
    m_socket.connectToHost("172.16.10.1", 61500);
    m_dessin = false;
}

FaitMoiDessin::~FaitMoiDessin()
{
    delete ui;
}

void FaitMoiDessin::on_btnChoisirCouleur_clicked()
{
    QByteArray baCouleur;
    m_couleur = QColorDialog::getColor(Qt::white, ui->lblDessin);
    m_couleur.getRgb(&m_r,&m_g,&m_b);
    baCouleur.append(m_r);
    baCouleur.append(m_g);
    baCouleur.append(m_b);
    m_socket.write(baCouleur);
    m_socket.disconnectFromHost();

}
void FaitMoiDessin::mouseMoveEvent(QMouseEvent * e)
{
    if(e->x()< 1015 && e->x() > 25 && e->y() > 20 && e->y() < 510)
    {
        pointsList.append(e->x());
        pointsList.append(e->y());
    }
    else
    {
        m_dessin = false;
    }
    this->repaint();
}
void FaitMoiDessin::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::RightButton)
    {
        if(e->x()< 1000 && e->y() < 500)
        {
            m_dessin = true;
            //pointsList.append(e->x());
            //pointsList.append(e->y());
        }
    }

}

void FaitMoiDessin::mouseReleaseEvent(QMouseEvent *)
{
    m_dessin = false;
}

void FaitMoiDessin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(m_couleur);
    pen.setWidth(10);
    painter.setPen(pen);
    for (int i = 0; i < pointsList.length(); i++)
    {
        painter.drawPoint(pointsList.at(i), pointsList[i + 1]);
        i++;
    }
}
