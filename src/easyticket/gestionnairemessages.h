#ifndef GESTIONNAIREMESSAGES_H
#define GESTIONNAIREMESSAGES_H

#include <QObject>
#include <QMap>
#include "message.h"


class GestionnaireMessages
{
private:
    QMap<int,Message*> messages;

public:
    GestionnaireMessages();

    QMap<int,Message*> getMessages();
    Message* getMessage(int id);
    void ajouterMessage(Message* mes);

    ~GestionnaireMessages();
};

#endif // GESTIONNAIREMESSAGES_H
