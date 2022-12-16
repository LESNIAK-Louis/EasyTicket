#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "gestionnairetickets.h"

/**
 * @brief c'est la superclasse de toutes types de personnes (employé, tecnhicien, ingenieur, client)
 * @authors Aboubacar HASSANE CHEKOU KORE, Louis LESNIAK, Théo JOFFROY
 */
class Utilisateur {

protected:

    /**
     * @brief login d'un utilisateur
     */
    QString login;

    /**
     * @brief password d'un utilisateur
     */
    QString password;


    /**
     * @brief nom d'un utilisateur
     */
    QString nom;

    /**
     * @brief prenom
     */
    QString prenom;

    /**
    * @brief gestionnaireTickets des utilisateur
    */
    GestionnaireTickets* gestionnaireTickets;

    /**
    * @brief Constructeur
    */
    Utilisateur(QString login, QString nom, QString prenom);

public:

    /**
    * @brief retourne le login de l'utilisateur
    * @return nom
    */
   QString  getLogin(){return login;}

   /**
   * @brief retourne le mot de passe de l'utilisateur
   * @return nom
   */
   QString  getPassword(){return password; }

    /**
     * @brief retourne le nom de l'utilisateur
     * @return nom
     */
    QString getNom() { return nom; }


    /**
     * @brief retourne le prenom de l'utilisateur
     * @return prenom
     */
    QString getPrenom() { return prenom; }

    /**
     * @brief return les tickets de l'utilisateur
     * @return tickets
     */
    QMap<int, Ticket*> getTickets() { return gestionnaireTickets->getTickets(); }

    /**
     * @brief return les tickets de l'utilisateur
     * @return tickets
     */
    inline Ticket& getTicket(int id) { return *(getTickets().value(id)); }

    /**
     * @brief retourne vrai si l'utilisateur est un client
     * @return valeur du bool
     */
    virtual inline bool estUnClient() const = 0;

    /**
     * @brief retourne vrai si l'utilisateur est un employé
     * @return valeur du bool
     */
    virtual inline bool estUnEmploye() const = 0;

    /**
     * @brief retourne vrai si l'utilisateur est un ingénieur
     * @return valeur du bool
     */
    virtual inline bool estUnIngenieur() const = 0;

    /**
     * @brief retourne vrai si l'utilisateur est un technicien
     * @return valeur du bool
     */
    virtual inline bool estUnTechnicien() const = 0;

    /**
     * @brief retourne une QString avec le rôle de l'utilisateur
     * @return rôle de l'utilisateur
     */
    virtual inline QString getRole() const = 0;

    /**
     * @brief Permet a l'utilisateur de clôturer un ticket
     * @author Louis LESNIAK
     * @param ticket
     * @param statut
     * @param motif
     * @return Message contenant le motif de clôture
     */
    Message* cloturerTicket(Ticket& ticket, statutTicket statut, QString motif);

    /**
     * @brief Charge les tickets de l'utilisateur
     * @author Théo JOFFROY
     * @param tickets Tickets
     */
    void chargerTickets(GestionnaireTickets& tickets);

    /**
     * destructeur de l'Utilisateur
     */
    ~Utilisateur();
};

#endif // UTILISATEUR_H
