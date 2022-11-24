#ifndef MESSAGES_H
#define MESSAGES_H

#include <QString>

class Message
{

public:
    explicit Message();
    Message(QString contenu);
    int getID(){return id;}
    ~Message();

private:
    int id;
    QString contenu;
    QString dateMessage;


};

#endif // MESSAGES_H
