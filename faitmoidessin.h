/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#ifndef FAITMOIDESSIN_H
#define FAITMOIDESSIN_H
#include <QtGui>
#include <QColorDialog>
#include <QPainter>


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
    void mousePressEvent(QMouseEvent * );
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void on_btnConnexion_clicked();

signals:
    void siNouveauPoint(int, int);
public slots:
    void slPaint(int,int);
private:
    Ui::FaitMoiDessin *ui;
    QColor m_couleur;           //Objet QColor contenant la valeur choisi par QColorDialog
    QList<int> pointsList;
    QList<QString> motList;
    QByteArray m_baRole;
    QByteArray baPoints;
    int m_r,m_g,m_b,m_x,m_y;
    bool m_dessin;
};

#endif // FAITMOIDESSIN_H
