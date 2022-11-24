#ifndef GESTIONNAIRETICKETS_H
#define GESTIONNAIRETICKETS_H

#include <QMap>
#include "ticket.h"

/**
 * @brief Gestionnaire des tickets concernés par un utilisateur
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
     * @brief Getter d'un ticket via son identifiant
     * @param id
     * @return Ticket correspondant à l'id, NULL sinon
     */
    Ticket* getTicket(int id);

    /**
     * @brief Ajouter un ticket au gestionnaire de tickets
     * @param ticket à ajouter
     */
    void ajouterTicket(Ticket* ticket);

    /**
      * @brief Destructeur du gestionnaire de tickets
      */
    ~GestionnaireTickets();

};

#endif // GESTIONNAIRETICKETS_H
