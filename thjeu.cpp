/* *** Fait moi un dessin *** */
/* *** Projet Final Linux *** */
/* *** Jérémie Tremblay et Axel Gauthier-Bélanger *** */
/* *** Mai 2012 *** */
/* *** Cégep Lévis-Lauzon *** */

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
                //envoi les points dessinés au serveur
                m_socket.write(m_baPoints);
                m_socket.waitForBytesWritten();
                m_baPoints.clear();
            }
            else
            {
                m_baPoints.clear();
            }
        }
    }
    else
        if(m_baRole== "C")
        {
            while(1)
            {
                m_socket.waitForReadyRead();
                //lecture de tout les caractères
                m_baPoints = m_socket.read(m_socket.bytesAvailable());
                //décalage des bytes en int
                int x = (m_baPoints[0] << 8) + static_cast<uchar>(m_baPoints[1]);
                int y = (m_baPoints[2] << 8) + static_cast<uchar>(m_baPoints[3]);
                //appel le signal déclenchant le paint
                emit(siPaint(x,y));
                m_baPoints.clear();
            }
        }
}
//SLOT déclenché a chaque point dessiné pas le maitre
void thJeu::slNouveauPoint(int x, int y)
{
    m_baPoints.clear();
    //décalage des bytes pour les avoir en int
    m_baPoints.append(x >> 8);
    m_baPoints.append(x);
    m_baPoints.append(y >> 8);
    m_baPoints.append(y);
}
