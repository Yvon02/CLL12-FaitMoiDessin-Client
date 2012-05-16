/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#include "faitmoidessin.h"
#include "thjeu.h"
#include "ui_faitmoidessin.h"

FaitMoiDessin::FaitMoiDessin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaitMoiDessin)
{
    ui->setupUi(this);
    m_dessin = false;
}

FaitMoiDessin::~FaitMoiDessin()
{
    delete ui;
}

void FaitMoiDessin::on_btnChoisirCouleur_clicked()
{
    m_couleur = QColorDialog::getColor(Qt::white, ui->lblDessin);
}
void FaitMoiDessin::mouseMoveEvent(QMouseEvent * e)
{
    if(e->x()< 1010 && e->x() > 20 && e->y() > 20 && e->y() < 505)
    {
        pointsList.append(e->x());
        pointsList.append(e->y());
        emit(siNouveauPoint(e->x(),e->y()));
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
            pointsList.append(e->x());
            pointsList.append(e->y());
            emit(siNouveauPoint(e->x(),e->y()));
        }
    }
    this->repaint();
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
    pen.setWidth(5);
    painter.setPen(pen);
    for (int i = 0; i < pointsList.length(); i++)
    {
       painter.setPen(pen);
       painter.drawEllipse(pointsList.at(i), pointsList[i + 1],5,5);
       i++;
    }
}

void FaitMoiDessin::on_btnConnexion_clicked()
{
    QString adresse = ui->txtAdresse->text();
    thJeu* threadJeu = new thJeu(adresse);
    connect(this,SIGNAL(siNouveauPoint(int,int)),threadJeu,SLOT(slNouveauPoint(int,int)));
    connect(threadJeu,SIGNAL(siPaint(int, int)),this,SLOT(slPaint(int,int)));
    threadJeu->start();
}

void FaitMoiDessin::slPaint(int x, int y)
{
    pointsList.append(x);
    pointsList.append(y);
    this->repaint();
}
