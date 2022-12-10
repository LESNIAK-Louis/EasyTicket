#include "basedonnee.h"

BaseDonnee::BaseDonnee(){

    //mise en place d'un SGBD SQLITE
    db.setHostName("localhost");
    db.setDatabaseName("../easyticket/database");
    db.open();

   //creation requete


    //on verifie si la base de donnée a pu etre créer
    if(!db.isOpen()){
        qDebug() << "Erreur de connection a la base de donnée"
        << db.lastError();
    }else{

   // creerTableUtilisateur();
   // creerTableTicket();
   // creerTableMessages();
}

}


void BaseDonnee::creerTableUtilisateur(){

QSqlQuery q;
bool result = q.exec("CREATE TABLE IF NOT EXISTS User (login TEXT(10)  primary key, password TEXT(20),"
                     "prenom text(20), nom text(20),role text(20) );");
if (!result ){
    qDebug() << "erreur de creation de la table User "
               << q.lastError();
  }
}


void BaseDonnee::creerTableTicket(){
    QSqlQuery q;
  bool result =   q.exec("CREATE TABLE IF NOT EXISTS Ticket (id TEXT(10) primary key,"
                         "status Text(10), titre TEXT(20),"
                         " categorie TEXT(20),logiciel TEXT(20),"
                         "dateCreation TEXT(20),datePriseEnCharge TEXT(20),"
                         "dateCloture TEXT(20),"
                         "idClient Text(10),idEmploye Text(10))");
  if (!result ){
      qDebug() << "erreur de creation de la table Ticket "
                 << q.lastError();
    }
}

void BaseDonnee::creerTableMessages(){
    QSqlQuery q;
    bool result = q.exec("CREATE TABLE IF NOT EXISTS Messages (id TEXT(10)  primary key, contenue TEXT(500),  dateCreation Text(20),idTicket text(10) );");
if (!result ){
      qDebug() << "erreur de creation de la table Message "
               << q.lastError();
  }
}

int BaseDonnee::getNombreTickets(){
    QSqlQuery q;
    q.prepare("Select Count(*) From Tickets");
    bool result = q.exec();
    if(!result){
        qDebug() << "erreur de la requete getNombreTickets "
                 << q.lastError();
    }else{
        q.next();
        return q.value(0).toInt();
    }
    return 0;
}

int BaseDonnee::getNombreMessages(){
    QSqlQuery q;
    q.prepare("Select Count(*) From Messages");
    bool result = q.exec();
    if(!result){
        qDebug() << "erreur de la requete getNombreMessages "
                 << q.lastError();
    }else{
        q.next();
        return q.value(0).toInt();
    }
    return 0;
}

void BaseDonnee::ajouterUtilisateur(Utilisateur * u){
    QSqlQuery q;
    q.prepare("INSERT INTO USER VALUES (?, ?,?,?,?);");
    q.addBindValue(u->getLogin());
    q.addBindValue(u->getPassword());
    q.addBindValue(u->getPrenom());
    q.addBindValue(u->getNom());
    q.addBindValue(u->getRole());
    bool result = q.exec();
    if(!result){
        qDebug() << "erreur de la requete ajoutUtilisateur "
                 << q.lastError();
    }
}

void BaseDonnee::ajouterTicket(Ticket * t){
    QSqlQuery q;
    q.prepare("INSERT INTO Tickets (id, titre, categorie, logiciel, dateCreation, datePriseEnCharge, dateDerniereModification, dateCloture, statut, client, employe) VALUES (?,?,?,?,?,?,?,?,?,?,?)");
    q.addBindValue(t->getId());
    q.addBindValue(t->getTitre());
    q.addBindValue(t->getCategorie());
    q.addBindValue(t->getLogiciel());
    q.addBindValue(t->getDateCreation());
    q.addBindValue(QVariant(QVariant::Date));
    q.addBindValue(t->getDateDerniereModification());
    q.addBindValue(QVariant(QVariant::Date));
    q.addBindValue(t->getStatut());
    q.addBindValue(t->getClient()->getLogin());
    q.addBindValue(QVariant(QVariant::String));

   bool result = q.exec();
    if(!result){
        qDebug() << "erreur de la requete ajoutTicket "
                 << q.lastError();
    }
}

void BaseDonnee::ajouterMessage(Message *m){
    QSqlQuery q;
    q.prepare("INSERT INTO Messages (id, idTicket, contenu, dateMessage, redacteur) VALUES (?,?,?,?,?)");
    q.addBindValue(m->getId());
    q.addBindValue(m->getTicket()->getId());
    q.addBindValue(m->getContenu());
    q.addBindValue(m->getDateMessage());
    q.addBindValue(m->getRedacteur());
    bool result = q.exec();
    if(!result){
            qDebug() << "erreur de la requete ajoutMessage "
                     << q.lastError();
        }
}


void BaseDonnee::modifierTicket(Ticket * t){
    QSqlQuery q;
     q.prepare("UPDATE Tickets SET statut=?, categorie=?, datePriseEnCharge=?, dateDerniereModification=?, dateCloture=?, employe=? WHERE id=?");
     q.addBindValue(t->getStatut());
     q.addBindValue(t->getCategorie());
     q.addBindValue(t->getDatePriseEnCharge());
     q.addBindValue(t->getDateDerniereModification());
     q.addBindValue(t->getDateCloture());
     if(t->getEmploye() != NULL)
        q.addBindValue(t->getEmploye()->getLogin());
     else
        q.addBindValue(QVariant(QVariant::String));
     q.addBindValue(t->getId());
     bool result = q.exec();
     if(!result){
         qDebug() << "erreur de la requete modifierTicket "
                  << q.lastError();
     }
}

Utilisateur* BaseDonnee::recupererUtilisateur(const QString login,const QString mdp){
    QSqlQuery q;

    Utilisateur* u;
    //Recuperation de L'user dans la BDD via le login et mdp saisit
    q.prepare("Select *"
              "From Utilisateurs u "
              "where u.login=? and u.mdp=? ");

    q.addBindValue(login);
    q.addBindValue(mdp);
    bool result = q.exec();
    //instancie l'utilisateur en fonction de son role
    if(result){

        if(q.next()){
        QString loginR = q.value(0).toString();
        QString nomR =  q.value(2).toString();
        QString prenomR =  q.value(3).toString();
        QString role = q.value(4).toString();

        if(role == "Ingénieur") u = new Ingenieur(loginR,nomR,prenomR);
        else if(role == "Client") u = new Client(loginR,nomR,prenomR);
        else if(role == "Technicien") u = new Technicien(loginR,nomR,prenomR);

        }else{
            qDebug() << "utilisateur introuvable";

        }

    }else {
        qDebug() << q.lastError();
        qDebug() << "Mission echoué";
    }
    return u;
}

Utilisateur* BaseDonnee::recupererUtilisateur(const QString login){
    QSqlQuery q;

    Utilisateur* u;
    //Recuperation de L'user dans la BDD via le login
    q.prepare("Select *"
              "From Utilisateurs u "
              "where u.login=?");

    q.addBindValue(login);
    bool result = q.exec();
    //instancie l'utilisateur en fonction de son role
    if(result){

        if(q.next()){
        QString loginR = q.value(0).toString();
        QString nomR =  q.value(2).toString();
        QString prenomR =  q.value(3).toString();
        QString role = q.value(4).toString();

        if(role == "Ingénieur") u = new Ingenieur(loginR,nomR,prenomR);
        else if(role == "Client") u = new Client(loginR,nomR,prenomR);
        else if(role == "Technicien") u = new Technicien(loginR,nomR,prenomR);

        }else{
            qDebug() << "utilisateur introuvable";

        }

    }else {
        qDebug() << q.lastError();
        qDebug() << "Mission echoué";
    }
    return u;
}

GestionnaireTickets* BaseDonnee::recupererTickets(Utilisateur* u, GestionnaireUtilisateurs* gu){
    QSqlQuery q;

    GestionnaireTickets* tickets = new GestionnaireTickets();
    if(u->estUnClient()){
        q.prepare("Select t.id, t.titre, t.categorie, t.logiciel, t.dateCreation, t.datePriseEnCharge, t.dateDerniereModification, t.dateCloture, t.statut, t.client, t.employe "
                      "From Tickets t "
                      "Where t.client = ? "
                      "Order by t.dateDerniereModification DESC");
    }else{
        q.prepare("Select t.id, t.titre, t.categorie, t.logiciel, t.dateCreation, t.datePriseEnCharge, t.dateDerniereModification, t.dateCloture, t.statut, t.client, t.employe "
                      "From Tickets t "
                      "Where t.employe = ? "
                      "Or t.employe IS NULL "
                      "Order by t.dateDerniereModification");
    }
    q.addBindValue(u->getLogin());
    bool result = q.exec();

    if(result){

        while(q.next()){
            int id = q.value(0).toInt();
            QString titre = q.value(1).toString();
            QString categorie = q.value(2).toString();
            QString logiciel = q.value(3).toString();
            QString dateCreation = q.value(4).toString();
            QString datePriseEnCharge = q.value(5).toString();
            QString dateDerniereModification = q.value(6).toString();
            QString dateCloture = q.value(7).toString();
            int statut = q.value(8).toInt();
            QString loginClient = q.value(9).toString();
            QString loginEmploye = q.value(10).toString();

            Client* client = NULL;
            Employe* employe = NULL;
            if(loginClient == u->getLogin()){
                client = (Client*)u;
                if(loginEmploye != NULL){
                    employe = (Employe*)recupererUtilisateur(loginEmploye);
                    gu->ajouterUtilisateur(employe);
                }
            }else{
                employe = (Employe*)u;
                if(loginClient != NULL){
                    client = (Client*)recupererUtilisateur(loginClient);
                    gu->ajouterUtilisateur(client);
                }
            }

            Ticket* t = new Ticket(id, titre, categorie, logiciel, dateCreation, datePriseEnCharge, dateDerniereModification,
                                   dateCloture, statut, client, employe);

            tickets->ajouterTicket(t);
        }
    }else {
        qDebug() << q.lastError();
        qDebug() << "Mission echoué";
    }
    return tickets;
}

GestionnaireMessages* BaseDonnee::recupererMessages(Ticket* t){
    QSqlQuery q;

    GestionnaireMessages* messages = new GestionnaireMessages();
    q.prepare("Select m.id, m.contenu, m.dateMessage, m.redacteur "
                  "From Tickets t, Messages m "
                  "Where t.id = m.idTicket "
                  "And m.idTicket = ? "
                  "Order by m.dateMessage ASC");

    q.addBindValue(t->getId());
    bool result = q.exec();
    if(result){

        while(q.next()){
            int id = q.value(0).toInt();
            QString contenu = q.value(1).toString();
            QString dateMessage = q.value(2).toString();
            QString redacteur = q.value(3).toString();

            Message* m = new Message(id, contenu, dateMessage, redacteur);

            messages->ajouterMessage(m);

        }
    }else {
        qDebug() << q.lastError();
        qDebug() << "Mission echoué";
    }
    return messages;
}

BaseDonnee::~BaseDonnee(){
    if(db.isOpen()){
        db.close();
    }
}
