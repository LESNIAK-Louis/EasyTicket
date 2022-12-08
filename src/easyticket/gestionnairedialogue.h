#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include "gestionnaireutilisateurs.h"
#inclue "basedonnee.h"

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
     * @brief retourne le gestionnaire utilisateurs
     * @return gu
     */
    inline GestionnaireUtilisateurs* getGestionnaireUtilisateur() const { return gu; }

    /**
     * @brief tente de récupérer les informations d'un utilisateur depuis la base de données
     * @param login du client/employé
     * @param mdp mot de passe
     * @return vrai si les infos de connexion sont correctes
     */
    bool tentativeConnexion(QString login, QString mdp);
    /**
     * @brief charge les tickets d'un utilisateur depuis la base de données
     * @param u Utilisateur
     */
    void chargerTickets(Utilisateur* u);
    /**
     * @brief Crée un ticket
     * @param titre Titre
     * @param categorie Categorie
     * @param logiciel Logiciel
     * @param message Message
     */
    void creerTicket(QString titre, QString categorie,  QString logiciel, QString message);

    /**
     * @brief Cloture un ticket
     * @param id id du ticket
     * @param statut statut à mettre
     * @param motif motif de cloture
     */
    void cloturerTicket(Ticket* ticket, QString statut, QString motif);

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
     * @brief Accès à la base de données
     */
    BaseDonnee* bd;
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
