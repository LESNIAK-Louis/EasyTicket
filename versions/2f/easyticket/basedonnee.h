#ifndef BASEDONNEE_H
#define BASEDONNEE_H

#include <QtSql>
#include <QObject>
#include <QString>
#include "utilisateur.h"
#include "client.h"
#include "employe.h"
#include "ticket.h"
#include "message.h"
#include "ingenieur.h"
#include "technicien.h"
#include "gestionnaireutilisateurs.h"

/**
 * @brief Class qui gere la creation de la basse de donnée et les requetes
 */
class BaseDonnee
{

public:
    BaseDonnee();
    /**
     * @brief fonction qui creer la table utilisateur
     */
    void creerTableUtilisateur();

    /**
     * @brief fonction qui creer la table Ticket
     */
    void creerTableTicket();

    /**
      * @brief fonction qui creer la table Messages
      */
     void creerTableMessages();

     /**
       * @brief retourne le nombre de tickets dans la bdd
       * @return nb de tickets
       */
     int getNombreTickets();

     /**
       * @brief retourne le nombre de messages dans la bdd
       * @return nb de messages
       */
     int getNombreMessages();

     /**
     * @brief fonction qui rajoute un utilisateur dans sa table
     * @param login
     * @param mot de passe
     */
    void ajouterUtilisateur(Utilisateur * u);

    /**
     * @brief fonction qui rajoute un message dans sa table
     * @param identifiant
     * @param contenu du message
     * @param date du Message
     */
    void ajouterMessage(Message * m );

    /**
     * @brief fonction qui rajoute un ticket dans sa table
     * @param identifiant
     * @param status
     * @param titre
     * @param categorie
     * @param logiciel
     * @param date de Creation
     * @param dated de PriseEnCharge
     * @param dateCloture
     */
    void ajouterTicket(Ticket * t);

    /**
     * @brief fonction qui modifier un Ticket dans sa table
     * @param identifiant
     * @param status
     * @param categorie
     * @param logiciel
     * @param date de Cloture
     */
    void modifierTicket(Ticket * t);

    /**
     * @brief fonction qui récupère un utilisateur dans la bdd
     * @param login Login
     * @param mdp Mot de passe
     */
    Utilisateur* recupererUtilisateur(const QString login,const QString mdp);

    /**
     * @brief fonction qui récupère un utilisateur dans la bdd
     * @param login Login
     */
    Utilisateur* recupererUtilisateur(const QString login);

    /**
     * @brief fonction qui récupère les tickets d'un utilisateur
     * @param u Utilisateur
     * @param gu GestionnaireUtilisateurs
     * @return GestionnaireTickets
     */
    GestionnaireTickets* recupererTickets(Utilisateur* u, GestionnaireUtilisateurs* gu);

    /**
     * @brief fonction qui récupère les messages d'un ticket
     * @param u Utilisateur
     * @param t Ticket
     * @param gu GestionnaireUtilisateurs
     * @return GestionnaireMessages
     */
    GestionnaireMessages* recupererMessages(Ticket* t);


    void deconnection();
    ~BaseDonnee();



private:
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


};

#endif // BASEDONNEE_H
