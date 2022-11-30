#ifndef GESTIONNAIREMESSAGES_H
#define GESTIONNAIREMESSAGES_H

#include <QObject>
#include <QMap>
#include "message.h"

/**
 * @brief classe qui gerent les messsages d'un ticket
 */
class GestionnaireMessages
{
private:
    /**
     * @brief table (clé = id, Messages) qui gere les messages d'un ticket
     */
    QMap<int,Message*> messages;

public:
    /**
     * @brief constructeur d'un message
     */
    GestionnaireMessages();

    /**
     * @brief renvoie la listes des messages
     * @return
     */
    QMap<int,Message*> getMessages();
    /**
     * @brief renvoie un messages parti
     * @param id du message a acceder
     * @return retourne le messages
     */
    Message* getMessage(int id);

    /**
     * @brief ajoute un messages dans son gestionnaire
     * @param message a ajouter
     */
    void ajouterMessage(Message* mes);

    /**
      * destructeur de la classe
      */
    ~GestionnaireMessages();
};

#endif // GESTIONNAIREMESSAGES_H
