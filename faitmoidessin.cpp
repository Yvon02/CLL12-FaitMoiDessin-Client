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
    motList.append("chat");
    motList.append("poney");
    motList.append("diablo");
    motList.append("coucher de soleil");
    motList.append("compotte");
    motList.append("Felix");
    motList.append("chatnoir");
    ui->btnEssai->setVisible(false);
    ui->txtEssai->setVisible(false);
}

FaitMoiDessin::~FaitMoiDessin()
{
    delete ui;
}

void FaitMoiDessin::on_btnChoisirCouleur_clicked()
{
    //obtention d'une nouvelle couleur a partir du dialogue
    m_couleur = QColorDialog::getColor(Qt::white, ui->lblDessin);
}
void FaitMoiDessin::mouseMoveEvent(QMouseEvent * e)
{
    if(e->x()< 1010 && e->x() > 20 && e->y() > 20 && e->y() < 505)
    {
        //Autorise le paint si le curseur se trouve dans les limites
        pointsList.append(e->x());
        pointsList.append(e->y());
        //envoi les points au thread pour les envoyer au serveur
        emit(siNouveauPoint(e->x(),e->y()));
    }
    else
    {
        m_dessin = false;
    }
    //déclenche l'évenement paintEvent
    this->repaint();
}
void FaitMoiDessin::mousePressEvent(QMouseEvent * e)
{   //Autorise le paint si le bouton droit de la souris est enfoncé et si le curseur se trouve dans les limites
    if(e->button() == Qt::RightButton)
    {
        if(e->x()< 1000 && e->y() < 500)
        {
            m_dessin = true;
            //ajoute les points a la liste de points
            pointsList.append(e->x());
            pointsList.append(e->y());
            //envoi les points au thread pour les envoyer au serveur
            emit(siNouveauPoint(e->x(),e->y()));
        }
    }
    //déclenche l'évenement paintEvent
    this->repaint();
}

void FaitMoiDessin::mouseReleaseEvent(QMouseEvent *)
{
    //le paint n'est plus autorisé quand le bouton est relaché
    m_dessin = false;
}

void FaitMoiDessin::paintEvent(QPaintEvent *)
{
    //initialisation d'un objet QPainter pour dessiner
    QPainter painter(this);
    QPen pen;
    pen.setColor(m_couleur);
    pen.setWidth(5);
    painter.setPen(pen);
    //dessine l'ensemble des points se trouvant dans la liste
    for (int i = 0; i < pointsList.length(); i++)
    {
        painter.drawEllipse(pointsList.at(i), pointsList[i + 1],5,5);
        i++;
    }
}
//SLOT connexion au serveur
void FaitMoiDessin::on_btnConnexion_clicked()
{
    QString adresse = ui->txtAdresse->text();
    thJeu* threadJeu = new thJeu(adresse);
    //connexion du signal et du slot permettant de transmettre un point au thread
    connect(this,SIGNAL(siNouveauPoint(int,int)),threadJeu,SLOT(slNouveauPoint(int,int)));
    //connexion du signal et du slot permettant de dessiner un point à partir du thread
    connect(threadJeu,SIGNAL(siPaint(int, int)),this,SLOT(slPaint(int,int)));
    connect(threadJeu,SIGNAL(siNouveauMot(int)),this,SLOT(slNouveauMot(int)));
    connect(threadJeu,SIGNAL(siClient()),this,SLOT(slClient()));
    //connexion du signal et du slot permettant de transmettre le nom au maitre
    connect(this,SIGNAL(siSendMot(QByteArray)),threadJeu,SLOT(slGetMot(QByteArray)));
    //connexion du signal et du slot permettant de transmettre un essais au serveur
    connect(this,SIGNAL(siEssais(QByteArray)),threadJeu,SLOT(slEssais(QByteArray)));
    //connexion du signal et du slot permettant de se déconnecter du serveur
    connect(this,SIGNAL(siDeconnection()),threadJeu,SLOT(slDeconnection()));
    //départ du thread
    threadJeu->start();
}
//SLOT dessinant a la reception d'un point
void FaitMoiDessin::slPaint(int x, int y)
{
    //ajoute les points recus de la part du serveur à la liste
    pointsList.append(x);
    pointsList.append(y);
    //déclenche le paint
    this->repaint();
}

void FaitMoiDessin::slNouveauMot(int a)
{
    QString Mot;
    Mot = motList.at(a);
    m_mot.append(Mot);
    ui->lblx->setText("Vous etes le maitre, vous devez dessiner : ");
    ui->lbly->setText(Mot);
    emit(siSendMot(m_mot));
}

void FaitMoiDessin::slClient()
{
    ui->lblx->setText("Vous etes le joueur");
    ui->btnEssai->setVisible(true);
    ui->txtEssai->setVisible(true);
}

void FaitMoiDessin::on_btnEssai_clicked()
{
    QByteArray Essais;
    QString test;
    if(ui->btnEssai->text() != "")
    {
        Essais.clear();
        test = ui->txtEssai->text();
        Essais.append(test);
        emit(siEssais(Essais));
    }
}

void FaitMoiDessin::on_btnDeco_clicked()
{
    //émettre le signal de déconnexion
    emit(siDeconnection());
}
