#ifndef MESSAGES_H
#define MESSAGES_H

#include <QString>

class Message
{
private:
    int id;
    QString contenu;
    QString dateMessage;

public:
    explicit Message();
    Message(QString contenu);

    inline int getId() const { return id; }
    inline QString getContenu() const { return contenu; }
    inline QString getDateMessage() const { return dateMessage; }

    inline void setId(int id) { this->id = id; }
    inline void setContenu(QString contenu) { this->contenu = contenu; }
    inline void setDateMessage(QString dateMessage) { this->dateMessage = dateMessage; }

    ~Message();
};

#endif // MESSAGES_H
