#include "utilitaires.h"
#include <QDateTime>

QString getDateEtHeureActuelle(){
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
}

QString getDateActuelle(){
    return QDateTime::currentDateTime().toString("yyyy-MM-dd");;
}
