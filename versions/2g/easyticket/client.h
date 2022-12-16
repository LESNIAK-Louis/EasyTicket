#ifndef CLIENT_H
#define CLIENT_H

#include "utilisateur.h"

/**
 * @brief represente un client dans l'application
 * @authors Aboubacar HASSANE CHEKOU KORE, Louis LESNIAK, Théo JOFFROY
 */
class Client : public Utilisateur
{
public:
    /**
     * @brief constructeur d'un client
     * @param login d'un client
     * @param nom d'un client
     * @param prenom d'un client
     */
    Client(QString login, QString nom, QString prenom);

    /**
    * @brief retourne vrai si l'utilisateur est un employé
    * @return valeur du bool
    */
   inline bool estUnEmploye() const {return false;}

   /**
    * @brief retourne vrai s si l'utilisateur est un client
    * @return valeur du bool
    */
   inline bool estUnClient() const {return true;}

   /**
    * @brief retourne vrai si  si l'utilisateur est un ingénieur
    * @return valeur du bool
    */
   inline bool estUnIngenieur() const {return false;}

   /**
    * @brief retourne vrai si  si l'utilisateur est un technicien
    * @return valeur du bool
    */
   inline bool estUnTechnicien() const {return false;}

   /**
    * @brief retourne une QString avec le rôle de l'utilisateur
    * @return rôle de l'utilisateur
    */
   inline QString getRole() const { return "Client"; }

    /**
     * @brief Créateur d'un ticket sans categorie definie
     * @author Théo JOFFROY
     * @param login d'un client
     * @param nom d'un client
     * @param prenom d'un client
     * @return Ticket créé
     */
    Ticket& creerTicket(QString titre, QString categorie, QString message);

    /**
     * @brief Créateur d'un ticket sans categorie definie
     * @author Théo JOFFROY
     * @param login d'un client
     * @param nom d'un client
     * @param prenom d'un client
     * @return Ticket créé
     */
    Ticket& creerTicket(QString titre, QString categorie, QString logiciel, QString message);

    /**
     * @briefDestructeur de client
     */
    ~Client();
};

#endif // CLIENT_H
