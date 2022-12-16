#ifndef GESTIONNAIRETICKETS_H
#define GESTIONNAIRETICKETS_H

#include <QMap>
#include "ticket.h"

class Client;

/**
 * @brief Gestionnaire des tickets concernés par un utilisateur
 * @authors Théo JOFFROY, Aboubacar HASSANE CHEKOU KORE
 */
class GestionnaireTickets
{
private:
    /**
     * @brief QMap de la liste des tickets où la clé est l'id du ticket et la valeur est l'objet ticket
     */
    QMap<int,Ticket*> tickets;

public:
    /**
     * @brief Constructeur du gestionnaire de tickets
     */
    GestionnaireTickets();

    /**
     * @brief Getter de la QMap des tickets
     * @return Tickets
     */
    QMap<int, Ticket*> getTickets();
    /**
     * @brief Ajouter un ticket au gestionnaire de tickets
     * @param titre Titre
     * @param categorie Categorie
     * @param logiciel Logiciel
     * @param message Message
     * @param redacteur Redacteur
     * @return Ticket créé
     */
    Ticket& ajouterTicket(QString titre, QString categorie, QString logiciel, QString message, Client& redacteur);
    /**
     * @brief Ajouter un ticket au gestionnaire de tickets
     * @param ticket Ticket
     */
    void ajouterTicket(Ticket& ticket);
    /**
     * @brief Getter d'un ticket via son identifiant
     * @param id
     * @return Ticket correspondant à l'id, NULL sinon
     */
    Ticket& getTicket(int id);

    /**
      * @brief Destructeur du gestionnaire de tickets
      */
    ~GestionnaireTickets();

};

#endif // GESTIONNAIRETICKETS_H
