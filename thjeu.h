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
    void siPaint();
public slots:
    void slNouveauPoint(int, int);
private:
    QTcpSocket m_socket;
    QByteArray m_baRole, m_baPoints;
    QString m_ip;
    
};

#endif // THJEU_H
