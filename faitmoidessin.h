#ifndef FAITMOIDESSIN_H
#define FAITMOIDESSIN_H

#include <QMainWindow>
#include <QColor>


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

    void on_lblDessin_linkActivated(const QString &link);

private:
    Ui::FaitMoiDessin *ui;
    QColor m_couleur;
    int m_r;
    int m_g;
    int m_b;
};

#endif // FAITMOIDESSIN_H
