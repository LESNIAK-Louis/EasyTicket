#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include "gestionnaireutilisateurs.h"

/**
 * @brief classe qui permet l'interraction client et GUI
 */
class GestionnaireDialogue
{
public:
    /**
     * @brief constructeur de la classe
     */
    GestionnaireDialogue();

    /**
     * @brief verifie si le penom saisit se trouve dans la listes des utilisateurs
     * @param login du client/employé
     * @return vrai si la l'utilisateur est enregistrer
     */
    bool tentativeConnexion(QString login);

    /**
     * @brief retourne un utilisateur
     * @return utilisateur
     */
    Utilisateur* getUtilisateur() { return utilisateurActuel; }

    /**
      * destructeur de la classe
      */
    ~GestionnaireDialogue();

private:
    /**
     * @brief gestionnaire utilisateur
     */
    GestionnaireUtilisateurs* gu;

    /**
     * @brief l'utilsateur qui tente de se connecter
     */
    Utilisateur* utilisateurActuel;

};



#endif // GESTIONNAIREDIALOGUE_H
