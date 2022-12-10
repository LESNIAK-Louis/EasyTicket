#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include "gestionnairemessages.h"

class Client;
class Employe;

/**
* @brief Enumération du status d'un Ticket
*/
enum statutTicket {
    OUVERT = 1,
    RESOLU = 2,
    INSOLUBLE = 3
};

/**
* @brief Un ticket
*/
class Ticket
{
private:
    /**
     * @brief identifiant du ticket
     */
    int  id;
    /**
     * @brief titre du ticket
     */
    QString titre;
    /**
     * @brief nom de la catégorie du ticket
     */
    QString categorie;
    /**
     * @brief nom du logiciel concerné par le ticket
     */
    QString logiciel;
    /**
     * @brief date de création du ticket
     */
    QString dateCreation;
    /**
     * @brief date de prise en charge du ticket
     */
    QString datePriseEnCharge;
    /**
     * @brief date de la dernière modification du ticket
     */
    QString dateDerniereModification;
    /**
     * @brief date de cloture du ticket
     */
    QString dateCloture;
    /**
     * @brief gestionnaire des messages du ticket
     */
    GestionnaireMessages* gm;

    /**
     * @brief statut du ticket
     */
    statutTicket statut;

    /**
     * @brief client qui a déposé le ticket
     */
    Client* client;

    /**
     * @brief employé qui prend en charge le ticket
     */
    Employe* employe;

public:
    /**
    * @brief Constructeur d'un Ticket
    * @param titre Titre du ticket
    * @param categorie Catégorie du ticket
    * @param client Client qui dépose le ticket
    */
    Ticket(QString titre, QString categorie, Client* client);

    /**
    * @brief Constructeur d'un Ticket
    * @param titre Titre du ticket
    * @param categorie Catégorie du ticket
    * @param logiciel Logiciel concerné par le ticket
    * @param client Client qui dépose le ticket
    */
    Ticket(QString titre, QString categorie,  QString logiciel, Client* client);

    /**
    * @brief Constructeur d'un Ticket pour récupération depuis la bdd
    * @param titre Titre du ticket
    * @param categorie Catégorie du ticket
    * @param logiciel Logiciel concerné par le ticket
    * @param dateCreation Date de création
    * @param datePriseEnCharge Date prise en charge
    * @param dateDerniereModification Date de derniere modification
    * @param dateCloture Date de clôture
    * @param statut Statut
    * @param client Client qui a déposé le ticket
    * @param employe Employé qui a pris en charge le ticket
    */
    Ticket(int id, QString titre, QString categorie,  QString logiciel, QString dateCreation,
           QString datePriseEnCharge, QString dateDerniereModification, QString dateCloture,
           int statut, Client* client, Employe* employe);

    /**
    * @brief Getter de l'id du ticket
    * @return id
    */
    inline int getId() const { return id; }
    /**
    * @brief Getter du titre du ticket
    * @return titre
    */
    inline QString getTitre() const { return titre; }
    /**
    * @brief Getter de la catégorie du ticket
    * @return categorie
    */
    inline QString getCategorie() const { return categorie; }
    /**
    * @brief Getter du logiciel concerné par le ticket
    * @return logiciel
    */
    inline QString getLogiciel() const { return logiciel; }
    /**
    * @brief Getter de la date de création du ticket
    * @return dateCreation
    */
    inline QString getDateCreation() const { return dateCreation; }
    /**
    * @brief Getter de la date de prise en charge du ticket
    * @return datePriseEnCharge
    */
    inline QString getDatePriseEnCharge() const { return datePriseEnCharge; }
    /**
    * @brief Getter de la date de dernière modification du ticket
    * @return dateDerniereModification
    */
    inline QString getDateDerniereModification() const { return dateDerniereModification; }
    /**
    * @brief Getter de la date de cloture du ticket
    * @return dateCloture
    */
    inline QString getDateCloture() const { return dateCloture; }

    /**
    * @brief Getter du statut du ticket
    * @return statut
    */
    inline statutTicket getStatut() const{ return statut; }

    /**
    * @brief Getter du statut du ticket
    * @return statut en QString
    */
    inline QString getStatutString() {
        switch(statut){
            case OUVERT:
                return "OUVERT";
            break;
            case RESOLU:
                return "RESOLU";
               break;
            case INSOLUBLE:
                return "INSOLUBLE";
                break;
            default:
                return "ERROR";
            break;
        }
    }
    /**
    * @brief Récupère la liste des messages
    * @return messages du ticket
    */
    QMap<int, Message*> getMessages() const { return gm->getMessages(); }

    /**
    * @brief Getter du client qui a déposé le ticket
    * @return client
    */
    inline Client* getClient() const { return client; }

    /**
    * @brief Getter de l'employé qui prend en charge le ticket
    * @return employe
    */
    inline Employe* getEmploye() const { return employe; }

    /**
    * @brief Setter de l'id du ticket
    * @param id identifiant ticket
    */
    inline void setId(int id) { this->id = id; }
    /**
    * @brief Setter du titre du ticket
    * @param titre Titre ticket
    */
    inline void setTitre(QString titre) { this->titre = titre; }
    /**
    * @brief Setter de la catégorie du ticket
    * @param categorie Catégorie du ticket
    */
    inline void setCategorie(QString categorie) { this->categorie = categorie; }
    /**
    * @brief Setter du logiciel concerné par le ticket
    * @param logiciel Logiciel concerné par le ticket
    */
    inline void setLogiciel(QString logiciel) { this->logiciel = logiciel; }
    /**
    * @brief Setter de la date de création du ticket
    * @param dateCreation  Date de création du ticket
    */
    inline void setDateCreation(QString dateCreation) { this->dateCreation = dateCreation; }
    /**
    * @brief Setter de la date de prise en charge du ticket
    * @param datePriseEnCharge Date de prise en charge du ticket
    */
    inline void setDatePriseEnCharge(QString datePriseEnCharge) { this->datePriseEnCharge = datePriseEnCharge; }
    /**
    * @brief Setter de la date de la dernière modification du ticket
    * @param dateDerniereModification Date de dernière modification du ticket
    */
    inline void setDateDerniereModification(QString dateDerniereModification) { this->dateDerniereModification = dateDerniereModification; }
    /**
    * @brief Setter de la date de cloture du ticket
    * @param dateCloture Date de cloture du ticket
    */
    inline void setDateCloture(QString dateCloture) { this->dateCloture = dateCloture; }
    /**
    * @brief Setter du statut du ticket
    * @param statut
    */
    inline void setStatut(statutTicket statut) { this->statut = statut; }
    /**
    * @brief Setter de l'employé qui prend en charge le ticket
    * @param employe Employé qui prend en charge le ticket
    */
    inline void setEmploye(Employe* employe) { this->employe = employe; }
    /**
    * @brief Cloture le ticket
    * @param statut Statut à mettre
    * @param msg motif de cloture
    * @param redacteur nom de l'utilisateur qui cloture le ticket
    * @return Message contenant le motif de clôture
    */
    Message* cloturerTicket(statutTicket statut, QString msg, QString redacteur);
    /**
    * @brief Ajoute une message au ticket
    * @param msg Message à ajouter
    * @param redacteur Nom du rédacteur du message
    * @return Message ajouté
    */
    Message* ajouterMessage(QString msg, QString redacteur);

    /**
     * @brief Charge les messages du ticket
     * @param messages Messages
     */
    void chargerMessages(GestionnaireMessages* messages);



     ~Ticket();

};

#endif // TICKET_H
