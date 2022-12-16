#include "ecranprincipal.h"
#include "ui_ecranprincipal.h"
#include "mainwindow.h"
#include "detailsticket.h"
#include "creationticket.h"

#include <QMessageBox>

EcranPrincipal::EcranPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EcranPrincipal)
{
    ui->setupUi(this);
    // On met la bonne taille à la fenêtre et on empêche le resize
    ((MainWindow*)(this->parent()))->setFixedSize(this->width(),this->height());
    setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    // On récupère l'utilisateur et on configure l'interface en fonction de lui
    utilisateur = &(((MainWindow*)(this->parent()))->getGD().getUtilisateur());
    ui->labelNom->setText("Bienvenue " + utilisateur->getPrenom() + " " + utilisateur->getNom());
    ui->pushButtonCreationTicket->setVisible(utilisateur->estUnClient());
}

void EcranPrincipal::chargerTickets(){
    // On récupère les tickets
    QMap<int, Ticket*> tickets = utilisateur->getTickets();

    // On les ajoutes à la list de l'ui
    ui->listeTickets->clear();
    corresId.clear();
    foreach(Ticket* t, tickets.values()){

        ui->listeTickets->addItem(new QListWidgetItem(QString::number(t->getId()) + "\t" +
                                                      t->getTitre() + "\t" +
                                                      t->getStatutString() + "\t" +
                                                      t->getCategorie() + "\t" +
                                                      t->getDateDerniereModification() + "\t"));
        corresId.append(t->getId());
    }
}

void EcranPrincipal::on_pushButtonCreationTicket_clicked(){
    CreationTicket* creationTicket = new CreationTicket(this);
    creationTicket->exec();
}

void EcranPrincipal::on_pushButtonDeco_clicked(){
   ((MainWindow*)(this->parent()))->deconnexion();
}


EcranPrincipal::~EcranPrincipal(){
    delete ui;
}

void EcranPrincipal::on_listeTickets_itemClicked(QListWidgetItem *item)
{
    int index = ui->listeTickets->row(item);
    Ticket& t = *(utilisateur->getTickets().value(corresId.at(index)));
    ((MainWindow*)(this->parent()))->getGD().chargerMessages(t);
    DetailsTicket* detailsTicket = new DetailsTicket(this, &t);

    detailsTicket->exec();
}
