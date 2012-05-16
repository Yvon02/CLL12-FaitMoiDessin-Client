#include "thjeu.h"

thJeu::thJeu(QString ip)
{
    m_ip = ip;
}

void thJeu::run()
{
    m_socket.connectToHost(m_ip, 61500);                        // se connecte au serveur
    m_socket.waitForReadyRead();                                // attend une réponse du serveur
    m_baRole = m_socket.read(m_socket.bytesAvailable());        // recoit la réponse
    if(m_baRole== "M")
    {
        while(1)
        {
            if(m_baPoints.length()==4)
            {
                m_socket.write(m_baPoints);                     // envoi de points dessinés vers le serveur
                m_baPoints.clear();
            }
            else
            {
                m_baPoints.clear();
            }
            m_socket.waitForBytesWritten();                     // attend la fin de l'envoi

        }
    }
    else
        if(m_baRole== "C")
        {
            while(1)
            {
                m_socket.waitForReadyRead();
                m_baPoints = m_socket.read(m_socket.bytesAvailable());
                int x = (m_baPoints[0] << 8) + static_cast<uchar>(m_baPoints[1]);
                int y = (m_baPoints[2] << 8) + static_cast<uchar>(m_baPoints[3]);
                emit(siPaint(x,y));
                m_baPoints.clear();
            }
        }
}
//SLOT déclenché a chaque point dessiné pas le maitre
void thJeu::slNouveauPoint(int x, int y)
{
    m_baPoints.clear();
    m_baPoints.append(x >> 8);
    m_baPoints.append(x);
    m_baPoints.append(y >> 8);
    m_baPoints.append(y);
}
