#include "utilitaires.h"
#include <iostream>
#include <QDateTime>

QString getDateEtHeureActuelle(){
    return QDateTime::currentDateTime().toString("dd/MM/yy hh:mm");
}

QString getHeureActuelle(){
    return QDateTime::currentDateTime().toString("hh:mm");;
}
