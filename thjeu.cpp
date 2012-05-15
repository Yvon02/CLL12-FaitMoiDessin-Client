#include "thjeu.h"

thJeu::thJeu(QString ip)
{
    m_ip = ip;
}

void thJeu::run()
{
    QByteArray baRecept;
    m_socket.connectToHost(m_ip, 61500);                          // se connecte au serveur
    m_socket.waitForReadyRead();                                // attend une réponse du serveur
    m_baRole = m_socket.read(m_socket.bytesAvailable());        // recoit la réponse
    if(m_baRole== "M")
    {
        while(1)
        {

        }
    }
    else
        if(m_baRole== "C")
        {
            //(QString("%0").arg((baPoints[0] << 8) + static_cast<uchar>(baPoints[1])));
            //(QString("%0").arg((baPoints[2] << 8) + static_cast<uchar>(baPoints[3])));
            while(1)
            {

            }
        }
}

void thJeu::slNouveauPoint(int x, int y)
{
    m_baPoints.append(x >> 8);
    m_baPoints.append(x);
    m_baPoints.append(y >> 8);
    m_baPoints.append(y);
}
