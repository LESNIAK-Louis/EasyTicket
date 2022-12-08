#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    gu = new GestionnaireUtilisateurs();
}

bool GestionnaireDialogue::tentativeConnexion(QString login, QString mdp){

    bd->recupererUtilisateur(login, mdp, utilisateurActuel);
        if(utilisateurActuel != NULL){
            gu->ajouterUtilisateur(utilisateurActuel);
        }

    return utilisateurActuel != NULL;
}

void GestionnaireDialogue::chargerTickets(Utilisateur* u){

    //bd->recupererTickets();
}

void GestionnaireDialogue::creerTicket(QString titre, QString categorie, QString logiciel, QString message){
    ((Client*)utilisateurActuel)->creerTicket(titre, categorie, logiciel, message);
}

void GestionnaireDialogue::cloturerTicket(Ticket* ticket, QString statut, QString motif){
    statutTicket statutT;
    if(statut == "RESOLU")
        statutT = RESOLU;
    else if(statut == "INSOLUBLE")
        statutT = INSOLUBLE;
    else
        statutT = OUVERT;

    ((Utilisateur*)utilisateurActuel)->cloturerTicket(ticket, statutT, motif);
}


GestionnaireDialogue::~GestionnaireDialogue(){

    delete gu;
}

