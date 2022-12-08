#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    gu = new GestionnaireUtilisateurs();
}

bool GestionnaireDialogue::tentativeConnexion(QString login){

    utilisateurActuel = gu->getUtilisateur(login);

    return utilisateurActuel != NULL;
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

