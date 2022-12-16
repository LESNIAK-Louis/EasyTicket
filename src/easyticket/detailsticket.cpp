#include "detailsticket.h"
#include "ui_detailsticket.h"
#include "mainwindow.h"
#include "motifcloture.h"
#include "dialogcombobox.h"
#include "ecranprincipal.h"
#include "gestionnairedialogue.h"
#include "gestionnaireutilisateurs.h"
#include "utilitaires.h"

#include <QScrollBar>
#include <QMap>
#include <QRegularExpression>
#include <QDebug>

DetailsTicket::DetailsTicket(QWidget *parent, Ticket* ticket) :
    QDialog(parent),
    ui(new Ui::DetailsTicket)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose); // L'objet est delete à la fermeture de la fenêtre

    // On met la bonne taille à la fenêtre, on empêche le resize et on défini le titre
    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Détails du ticket");

    this->ticket = ticket;

    // On setup la zone des messages
    ui->scrollAreaWidgetContents->setLayout(ui->zoneMessagesLayout);
    // On charge les messages dans leur zone
    chargerMessages();
}

void DetailsTicket::chargerMessages(){

    // On met dans les labels les informations du ticket correspondant
    ui->labelTitre->setText(ticket->getTitre());
    ui->labelID->setText("ID\n" + QString::number(ticket->getId()));
    ui->labelStatut->setText("Statut\n" + ticket->getStatutString());
    ui->labelDate->setText("Créé le\n" + ticket->getDateCreation());
    ui->labelCategorie->setText("Catégorie\n" + ticket->getCategorie());
    ui->labelLogiciel->setText("Logiciel\n" + ticket->getLogiciel());

    if(&(ticket->getEmploye()) != NULL) // Le ticket a été déjà pris en charge par un employé, on l'affiche
    {
        ui->labelPrisEnCharge->setText("Pris en charge par\n" + ticket->getEmploye().getNom() + " " + ticket->getEmploye().getPrenom() + "\n" + ticket->getDatePriseEnCharge());
    }
    else{
        if(ticket->getStatut() != OUVERT) // Le ticket n'a pas encore été pris en charge
            ui->labelPrisEnCharge->setText("Personne n'a pris en charge ce ticket");
    }


    if(((EcranPrincipal*)this->parent())->getUtilisateur().estUnEmploye()){
        // Affichage des actions possibles en tant qu'employé
        ui->boutonModifierCateg->setVisible(true);
        ui->boutonModifierAttribution->setVisible(true);
    }
    else{
        // On masque les bouton d'actions relatifs aux employés
        ui->boutonModifierCateg->setVisible(false);
        ui->boutonModifierAttribution->setVisible(false);
    }

    if(ticket->getStatut() != OUVERT){
        // On grise les intéractions utilisateur de modification du ticket si celui-ci est fermé
        ui->boutonCloturer->setEnabled(false);
        ui->inputReponse->setEnabled(false);
        ui->boutonEnvoyer->setEnabled(false);
        ui->boutonModifierAttribution->setEnabled(false);
    }

    QMap<int, Message*> messages = ticket->getMessages();

    // Destruction des anciens messages s'il y en a
    QLayoutItem *child;
    while ((child = ui->zoneMessagesLayout->takeAt(0)) != 0) {
       delete child->widget();
       delete child;
    }

    // Préparation de la zone message
    ui->zoneMessages->setWidget(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->setLayout(ui->zoneMessagesLayout);

    // Mise des messages dans la zone
    foreach(Message* m, messages.values()){

        MessageInfosTicket* msg = new MessageInfosTicket(nullptr, m);
        ui->zoneMessagesLayout->addWidget(msg);
        ui->zoneMessages->verticalScrollBar()->setValue(
                            ui->zoneMessages->verticalScrollBar()->maximum());
    }
}

void DetailsTicket::on_boutonModifierCateg_clicked()
{
    // Setup dynamique de la dialog combo box
    DialogComboBox* dialog = new DialogComboBox(this);

    if(ticket->getCategorie() == "Bug"){
        dialog->addItem("Question");
        dialog->addItem("Réclamation");
    }
    else if(ticket->getCategorie() == "Question")
    {
        dialog->addItem("Bug");
        dialog->addItem("Réclamation");
    }
    else {
        dialog->addItem("Bug");
        dialog->addItem("Question");
    }

    dialog->setTitle("Choisissez une catégorie");
    dialog->setMessage("Choisissez une catégorie à affecter au ticket");
    dialog->exec();

    if(dialog->getStringResult() != ""){ // En cas de validation
        // On modifie la catégorie du ticket et on rafraichit l'ui
        ticket->setCategorie(dialog->getStringResult());

        GestionnaireDialogue& gd =((MainWindow*)(this->parent()->parent()))->getGD();
        gd.modifierTicket(*ticket);

        ui->labelCategorie->setText("Catégorie\n" + ticket->getCategorie());
        ((EcranPrincipal*)this->parent())->chargerTickets();
    }

    delete dialog;

}

void DetailsTicket::on_boutonModifierAttribution_clicked()
{
    // Setup dynamique de la dialog combo box
    DialogComboBox* dialog = new DialogComboBox(this);

    GestionnaireDialogue& gd =((MainWindow*)(this->parent()->parent()))->getGD();
    GestionnaireUtilisateurs& gu = gd.getGestionnaireUtilisateur();
    QMap<QString,Utilisateur*> utilisateurs = gu.getUtilisateurs();

    foreach(Utilisateur* u, utilisateurs.values()){
        if(u->estUnEmploye() && u->getLogin() != gd.getUtilisateur().getLogin())
            dialog->addItem(u->getNom() + " " + u->getPrenom() + " (" + u->getLogin() + ")");
    }

    dialog->setTitle("Attribution du ticket");
    dialog->setMessage("Choisissez un employé à qui attribuer le ticket");
    dialog->exec();

    QString result = dialog->getStringResult();

    if(result != "") // En cas de validation
    {

        // Regexp utilisée pour extraire le login de la QString affichée dans la ComboBox
        QRegularExpression regex("\\((.*?)\\)", QRegularExpression::MultilineOption);
        QRegularExpressionMatch match = regex.match(result);
        QString captured = match.captured(1);

        // Modification de l'employé qui prend en charge le message
        Utilisateur* utilisateur = &(gu.getUtilisateur(captured));
        if(utilisateur != NULL)
        {
            ticket->setEmploye((Employe&)*utilisateur);
            ticket->setDatePriseEnCharge(getDateActuelle());
            ui->labelPrisEnCharge->setText("Pris en charge par\n" + ticket->getEmploye().getNom() + " " + ticket->getEmploye().getPrenom() + "\n" + ticket->getDatePriseEnCharge());
            gd.modifierTicket(*ticket);
        }
        delete dialog;

        // On supprime le ticket du gestionnaire
        gd.getUtilisateur().getGestionnaireTickets().supprimerTicket(*ticket);

        // On grise les options de modification car nous ne pouvons plus modifier le ticket car il est attribué à quelqu'un d'autre
        ui->boutonCloturer->setEnabled(false);
        ui->inputReponse->setEnabled(false);
        ui->boutonEnvoyer->setEnabled(false);
        ui->boutonModifierAttribution->setEnabled(false);
        ui->boutonModifierCateg->setVisible(false);

        // On recharge les tickets dans l'ecran principal
        ((EcranPrincipal*)this->parent())->chargerTickets();
   }
}

void DetailsTicket::on_boutonEnvoyer_clicked()
{
    GestionnaireDialogue& gd = ((MainWindow*)(this->parent()->parent()))->getGD();

    // Envoi du message
    if(ui->inputReponse->toPlainText() != ""){
        Message& m = ticket->ajouterMessage(ui->inputReponse->toPlainText(),
                               gd.getUtilisateur().getPrenom() + " " +
                               gd.getUtilisateur().getNom());

        if(gd.getUtilisateur().estUnEmploye()){
            ticket->setEmploye((Employe&)(gd.getUtilisateur()));
        }
        gd.ajouterMessage(m);
        gd.modifierTicket(*ticket);

        chargerMessages();

        ui->inputReponse->clear();
    }
}

void DetailsTicket::on_boutonCloturer_clicked(){
    MotifCloture* motifCloture = new MotifCloture(this, this->ticket);
    motifCloture->exec();

    // la cloture est validée
    if(motifCloture->getEstValide()){
        GestionnaireDialogue& gd =((MainWindow*)(this->parent()->parent()))->getGD();
        gd.modifierTicket(*ticket);
    }

    delete motifCloture;
}

DetailsTicket::~DetailsTicket()
{
    QLayoutItem *child;
    while ((child = ui->zoneMessagesLayout->takeAt(0)) != 0) {
       delete child->widget();
       delete child;
    }
    delete ui;
}


