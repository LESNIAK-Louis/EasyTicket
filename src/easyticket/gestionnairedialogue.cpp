#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    gu = new Gestionnaire<Utilisateur>();
    bd = new BaseDonnee();
}

bool GestionnaireDialogue::tentativeConnexion(QString login, QString mdp){

    utilisateurActuel = &(bd->recupererUtilisateur(login, mdp));

    if(utilisateurActuel != NULL){
        gu->ajouterItem(*utilisateurActuel);

        if(utilisateurActuel->estUnEmploye()){
            bd->recupererEmployes(*utilisateurActuel, *gu);
        }


        chargerTickets(*utilisateurActuel, *gu);
    }

    return utilisateurActuel != NULL;
}

void GestionnaireDialogue::chargerTickets(Utilisateur& u, Gestionnaire<Utilisateur>& gu){

    FabriqueIdentifiant *fi = fi->getInstance();
    fi->setIdTicket(bd->getNombreTickets());
    fi->setIdMessage(bd->getNombreMessages());

    utilisateurActuel->chargerTickets(bd->recupererTickets(u, gu));
}

void GestionnaireDialogue::chargerMessages(Ticket& t){

    t.chargerMessages(bd->recupererMessages(t));
}

void GestionnaireDialogue::creerTicket(QString titre, QString categorie, QString logiciel, QString message){
    Ticket& t = ((Client*)utilisateurActuel)->creerTicket(titre, categorie, logiciel, message);
    bd->ajouterTicket(t);
    ajouterMessage(*(t.getMessages().first()));

}

void GestionnaireDialogue::ajouterMessage(Message& m){
    bd->ajouterMessage(m);
}

void GestionnaireDialogue::modifierTicket(Ticket& t){
    bd->modifierTicket(t);
}

void GestionnaireDialogue::cloturerTicket(Ticket& ticket, QString statut, QString motif){
    statutTicket statutT;
    if(statut == "RESOLU")
        statutT = RESOLU;
    else if(statut == "INSOLUBLE")
        statutT = INSOLUBLE;
    else
        statutT = OUVERT;

    Message& m = *(((Utilisateur*)utilisateurActuel)->cloturerTicket(ticket, statutT, motif));
    if(&m != NULL)
        ajouterMessage(m);
}

void GestionnaireDialogue::nouveauDialogue(){
    delete this->gu;

    this->gu = new Gestionnaire<Utilisateur>();
    this->utilisateurActuel = nullptr;
}


GestionnaireDialogue::~GestionnaireDialogue(){

    delete gu;
    delete bd;
}

