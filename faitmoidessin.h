/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#ifndef FAITMOIDESSIN_H
#define FAITMOIDESSIN_H
#include <QtGui>
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
    void mousePressEvent(QMouseEvent * );
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:
    Ui::FaitMoiDessin *ui;
    QColor m_couleur;
    QList<int> pointsList;
    QTcpSocket m_socket;
    int m_r,m_g,m_b,m_x,m_y;
    bool m_dessin;
};

#endif // FAITMOIDESSIN_H
