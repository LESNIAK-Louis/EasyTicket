#ifndef CLIENT_H
#define CLIENT_H

#include "utilisateur.h"

/**
 * @brief represente un client dans l'application
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
     * @brief retourne vrai si c'est un client
     * @return
     */
    bool estUnClient();

    /**
     * @brief createur d'un ticket sans categorie definie
     * @param login d'un client
     * @param nom d'un client
     * @param prenom d'un client
     */
    void creerTicket(QString titre, QString categorie, QString message);

    /**
     * @brief createur d'un ticket sans categorie definie
     * @param login d'un client
     * @param nom d'un client
     * @param prenom d'un client
     */
    void creerTicket(QString titre, QString categorie, QString logiciel, QString message);

    /**
     * @briefDestructeur de client
     */
    ~Client();
};

#endif // CLIENT_H
