/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

#ifndef THJEU_H
#define THJEU_H

#include <QThread>
#include <QtGui>
#include <QTcpSocket>

class thJeu : public QThread
{
    Q_OBJECT
public:
    explicit thJeu(QString ip);
    void run();
signals:
    void siPaint(int, int);
    void siNouveauMot(int);
    void siClient();
public slots:
    void slNouveauPoint(int, int);
    void slGetMot(QString);
    void slEssais(QByteArray);
    void slDeconnection();
private:
    QTcpSocket m_socket;
    QByteArray m_baRole, m_baPoints;
    QString m_ip;
    QByteArray m_Mot;
    bool m_Connection;
};

#endif // THJEU_H
