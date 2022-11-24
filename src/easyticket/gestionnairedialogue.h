#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include "gestionnaireutilisateurs.h"

class GestionnaireDialogue
{
public:
    GestionnaireDialogue();

    bool tentativeConnexion(QString login);

    ~GestionnaireDialogue();

private:
    GestionnaireUtilisateurs* gu;
    Utilisateur* utilisateurActuel;

};



#endif // GESTIONNAIREDIALOGUE_H
