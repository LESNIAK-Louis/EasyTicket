#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    gu = new GestionnaireUtilisateurs();
}

bool GestionnaireDialogue::tentativeConnexion(QString login){

    utilisateurActuel = gu->getUtilisateur(login);

    return utilisateurActuel != NULL;
}

void GestionnaireDialogue::creerTicket(QString titre, QString categorie,  QString logiciel, QString message){

    ((Client*)utilisateurActuel)->creerTicket(titre, categorie, logiciel, message);
}

