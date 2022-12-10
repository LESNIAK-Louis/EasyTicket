#ifndef MESSAGES_H
#define MESSAGES_H

#include <QString>

class Ticket;
/**
 * @brief Classe d'un Message
 */
class Message
{
private:
    /**
     * @brief identifiant du message
     */
    int id;

    /**
     * @brief contenu du message
     */
    QString contenu;
    /**
     * @brief date de la création du message
     */
    QString dateMessage;
    /**
     * @brief rédacteur du message
     */
    QString redacteur;
    /**
     * @brief ticket auquel appartient le message
     */
    Ticket* ticket;

public:
    /**
     * @brief Constructeur d'un Message
     * @param contenu Contenu textuel du message
     * @param redacteur Rédacteur du message
     * @param ticket Ticket auquel appartient le message
     */
    Message(QString contenu, QString redacteur, Ticket* ticket);

    /**
     * @brief Constructeur d'un Message
     * @param id ID du message
     * @param contenu Contenu textuel du message
     * @param date Date du message
     * @param redacteur Rédacteur du message
     */
    Message(int id, QString contenu, QString date, QString redacteur);

    /**
     * @brief Getter de l'identifiant du message
     * @return id
     */
    inline int getId() const { return id; }
    /**
     * @brief Getter du contenu du message
     * @return contenu
     */
    inline QString getContenu() const { return contenu; }
    /**
     * @brief Getter de la date de création du message
     * @return dateMessage
     */
    inline QString getDateMessage() const { return dateMessage; }

    /**
     * @brief Getter du rédacteur du message
     * @return redacteur
     */
    inline QString getRedacteur() const { return redacteur; }

    /**
     * @brief Getter du ticket auquel appartient le message
     * @return ticket
     */
    inline Ticket* getTicket() const { return ticket; }

    /**
     * @brief Setter de l'identifiant du message
     * @param id Identifiant du message
     */
    inline void setId(int id) { this->id = id; }
    /**
     * @brief Setter du contenu du message
     * @param contenu Contenu textuel du message
     */
    inline void setContenu(QString contenu) { this->contenu = contenu; }
    /**
     * @brief Setter de la date de création du message
     * @param dateMessage Date de création du message
     */
    inline void setDateMessage(QString dateMessage) { this->dateMessage = dateMessage; }

    /**
     * @brief Destructeur de l'objet Message
     */
    ~Message();
};

#endif // MESSAGES_H
