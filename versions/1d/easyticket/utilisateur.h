#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "gestionnairetickets.h"

/**
 * @brief c'est la superclasse de toutes types de personnes (employé, tecnhicien, ingenieur, client)
 */
class Utilisateur {

protected:

    /**
     * @brief login d'un utilisateur
     */
    QString login;

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
     * @brief return vrai si c'est un client
     * @return valeur du bool
     */
    bool estUnClient() const { return false; }

    /**
    * @brief retourne vrai si c'est employé
    * @return valeur du bool
    */
    bool estUnEmploye() const { return false; }

    /**
     * @brief retourne vrai si c'est un ingenieur
     * @return valeur du bool
     */
    bool estUnIngenieur() const { return false; }

    /**
     * destructeur de l'Utilisateur
     */
    ~Utilisateur();
};

#endif // UTILISATEUR_H
