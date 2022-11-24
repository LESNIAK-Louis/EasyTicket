#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    gu = new GestionnaireUtilisateurs();
}

bool GestionnaireDialogue::tentativeConnexion(QString login){

    utilisateurActuel = gu->getUtilisateur(login);

    return utilisateurActuel != NULL;
}
