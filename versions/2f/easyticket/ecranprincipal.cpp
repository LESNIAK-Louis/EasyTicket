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
    ((MainWindow*)(this->parent()))->setFixedSize(this->width(),this->height());
    setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    utilisateur = ((MainWindow*)(this->parent()))->getGD()->getUtilisateur();
    ui->labelNom->setText("Bienvenue " + utilisateur->getPrenom() + " " + utilisateur->getNom());
    ui->pushButtonCreationTicket->setVisible(utilisateur->estUnClient());

    //chargerTickets();
}

void EcranPrincipal::chargerTickets(){

    QMap<int, Ticket*> tickets = utilisateur->getTickets();

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


EcranPrincipal::~EcranPrincipal(){
    delete ui;
}

void EcranPrincipal::on_listeTickets_itemClicked(QListWidgetItem *item)
{
    int index = ui->listeTickets->row(item);
    Ticket* t = utilisateur->getTickets().value(corresId.at(index));
    ((MainWindow*)(this->parent()))->getGD()->chargerMessages(t);
    DetailsTicket* detailsTicket = new DetailsTicket(this, t);

    detailsTicket->exec();
}
