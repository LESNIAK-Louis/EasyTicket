#include "ecranprincipal.h"
#include "ui_ecranprincipal.h"
#include "mainwindow.h"

#include <QMessageBox>

EcranPrincipal::EcranPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EcranPrincipal)
{
    ui->setupUi(this);
    Utilisateur* u = ((MainWindow*)(this->parent()))->getGD()->getUtilisateur();
    ui->labelNom->setText("Bienvenue " + u->getPrenom() + " " + u->getNom());
    ui->pushButtonCreationTicket->setVisible(u->estUnClient());
}

void EcranPrincipal::chargerTickets(Utilisateur* utilisateur){

    QMap<int, Ticket*> tickets = utilisateur->getTickets();

    ui->listeTickets->clear();
    foreach(Ticket* t, tickets.values()){

        ui->listeTickets->addItem(new QListWidgetItem(QString::number(t->getId()) + "\t" +
                                                      t->getTitre() + "\t" +
                                                      t->getStatut() + "\t" +
                                                      t->getCategorie() + "\t" +
                                                      t->getDateDerniereModification() + "\t"));
    }
}

void EcranPrincipal::on_pushButtonCreationTicket_clicked(){
    MainWindow* mainWindow = (MainWindow*)(this->parent());
    mainWindow->afficherCreationTicket();
}


EcranPrincipal::~EcranPrincipal(){
    delete ui;
}

void EcranPrincipal::on_listeTickets_itemClicked(QListWidgetItem *item)
{

}
