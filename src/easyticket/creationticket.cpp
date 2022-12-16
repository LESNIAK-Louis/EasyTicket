#include "creationticket.h"
#include "ui_creationticket.h"
#include "ecranprincipal.h"
#include "mainwindow.h"
#include "erreur.h"

CreationTicket::CreationTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreationTicket)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose); // L'objet est delete à la fermeture de la fenêtre

    // On met la bonne taille à la fenêtre, on empêche le resize et on défini le titre
    this->setFixedSize(this->width(),this->height());
    setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Création d'un ticket");

    // On définit les catégories et les logiciels pris en charge

    ui->comboBoxCategorie->addItem("Bug");
    ui->comboBoxCategorie->addItem("Question");
    ui->comboBoxCategorie->addItem("Réclamation");

    ui->comboBoxLogiciel->addItem("Twisk");
    ui->comboBoxLogiciel->addItem("Easy Tickets");
    ui->comboBoxLogiciel->addItem("Easy Drinks");

}

CreationTicket::~CreationTicket()
{
    delete ui;
}

void CreationTicket::on_comboBoxResultat_accepted()
{
    if(ui->champTitre->text() != "" &&  ui->champMessage->toPlainText() != ""){
        // Aucun des champs n'est vide, on procède à la création
        GestionnaireDialogue& gd = ((MainWindow*)(this->parent()->parent()))->getGD();
        gd.creerTicket(ui->champTitre->text(), ui->comboBoxCategorie->currentText(),
                        ui->comboBoxLogiciel->currentText(), ui->champMessage->toPlainText());
        // On rafraichit l'écran principal pour qu'il charge le nouveau ticket
        ((EcranPrincipal*)(this->parent()))->chargerTickets();
    }
    else{
        // Un des champs est vide,  on affiche une erreur
        QString erreur;
        if(ui->champTitre->text() == "" &&  ui->champMessage->toPlainText() != "")
            erreur = "Veuillez renseigner un titre au ticket";
        else  if(ui->champTitre->text() != "" &&  ui->champMessage->toPlainText() == "")
            erreur = "Veuillez renseigner un message de description au ticket";
        else if(ui->champTitre->text() == "" &&  ui->champMessage->toPlainText() == "")
            erreur = "Veuillez renseigner un titre et un message de description au ticket";

        Erreur erreurDialog;
        erreurDialog.setErreur(erreur);
        erreurDialog.exec();


        // On récupère les informations déjà entrées et on recréer une CreationTicket car l'objet est delete à la fermeture de la fenêtre
        CreationTicket* newTicket = new CreationTicket((EcranPrincipal*)this->parent());
        newTicket->ui->champMessage->setText(this->ui->champMessage->toPlainText());
        newTicket->ui->champTitre->setText(this->ui->champTitre->text());
        newTicket->ui->comboBoxCategorie->setCurrentIndex(this->ui->comboBoxCategorie->currentIndex());
        newTicket->ui->comboBoxLogiciel->setCurrentIndex(this->ui->comboBoxLogiciel->currentIndex());
        newTicket->exec();
    }
}
