#ifndef GESTIONNAIREMESSAGES_H
#define GESTIONNAIREMESSAGES_H

#include <QObject>
#include <QMap>
#include "message.h"
#include "gestionnaire.h"

/**
 * @brief classe qui gere les messages d'un ticket
 * @authors Théo JOFFROY, Aboubacar HASSANE CHEKOU KORE
 */
template<> class Gestionnaire<Message>
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
    Gestionnaire<Message>();

    /**
     * @brief renvoie la listes des messages
     * @return
     */
    QMap<int,Message*> getCollection();
    /**
     * @brief renvoie un messages parti
     * @param id du message a acceder
     * @return retourne le messages
     */
    Message& getItem(int id);

    /**
     * @brief ajoute un messages dans son gestionnaire
     * @param message a ajouter
     */
    void ajouterItem(Message& msg);

    /**
      * destructeur de la classe
      */
    ~Gestionnaire<Message>();
};

#endif // GESTIONNAIREMESSAGES_H
