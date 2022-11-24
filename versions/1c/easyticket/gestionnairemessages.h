#ifndef GESTIONNAIREMESSAGES_H
#define GESTIONNAIREMESSAGES_H

#include <QObject>
#include "message.h"
#include "QMap"

class GestionnaireMessages : public QObject
{
    Q_OBJECT
public:
    explicit GestionnaireMessages(QObject *parent = nullptr);
    GestionnaireMessages();
    QMap<int,Message*> getMessages();
    Message* getMessage(int id);
    void ajouterMessage(Message* mes);

private:

QMap<int,Message*> gm1;
signals:

};

#endif // GESTIONNAIREMESSAGES_H
