#include "utilitaires.h"
#include <QDateTime>

QString getDateEtHeureActuelle(){
    return QDateTime::currentDateTime().toString("dd/MM/yy hh:mm");
}

QString getDateActuelle(){
    return QDateTime::currentDateTime().toString("dd/MM/yy");;
}
