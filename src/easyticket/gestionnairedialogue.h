#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include "gestionnaireutilisateurs.h"
#include "basedonnee.h"
#include "fabriqueidentifiant.h"

/**
 * @brief Classe facade qui fait le lien entre l'interface graphique, la partie logique et la base de données
 * @authors Théo JOFFROY, Louis LESNIAK
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
    inline GestionnaireUtilisateurs& getGestionnaireUtilisateur() const { return *gu; }

    /**
     * @brief tente de récupérer les informations d'un utilisateur depuis la base de données
     * @author Théo JOFFROY
     * @param login du client/employé
     * @param mdp mot de passe
     * @return vrai si les infos de connexion sont correctes
     */
    bool tentativeConnexion(QString login, QString mdp);
    /**
     * @brief charge les tickets d'un utilisateur depuis la base de données
     * @author Théo JOFFROY
     * @param u Utilisateur
     * @param gu GestionnaireUtilisateurs
     */
    void chargerTickets(Utilisateur& u, GestionnaireUtilisateurs& gu);
    /**
     * @brief charge les messages d'un ticket depuis la base de données
     * @author Théo JOFFROY
     * @param t Ticket
     */
    void chargerMessages(Ticket& t);
    /**
     * @brief Crée un ticket
     * @author Théo JOFFROY
     * @param titre Titre
     * @param categorie Categorie
     * @param logiciel Logiciel
     * @param message Message
     */
    void creerTicket(QString titre, QString categorie,  QString logiciel, QString message);

    /**
     * @brief Ajoute un message à la bdd
     * @author Théo JOFFROY
     * @param m Message à ajouter
     */
    void ajouterMessage(Message& m);

    /**
     * @brief Modifie les infos d'un ticket dans la bdd
     * @author Théo JOFFROY
     * @param t Ticket à modifier
     */
    void modifierTicket(Ticket& t);

    /**
     * @brief Cloture un ticket
     * @author Louis LESNIAK
     * @param id id du ticket
     * @param statut statut à mettre
     * @param motif motif de cloture
     */
    void cloturerTicket(Ticket& ticket, QString statut, QString motif);

    /**
     * @brief retourne un utilisateur
     * @return utilisateur
     */
    Utilisateur& getUtilisateur() { return *utilisateurActuel; }

    /**
     * @brief supprime tous les utilisateur et son gestionnaire et en instancie de nouveau le gestionnaire
     * @author Louis LESNIAK
     */
    void nouveauDialogue();

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
