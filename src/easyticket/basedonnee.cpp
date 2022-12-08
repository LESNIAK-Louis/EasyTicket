#include "basedonnee.h"

BaseDonnee::BaseDonnee(){

    //mise en place d'un SGBD SQLITE
    db.setHostName("localhost");
    db.setDatabaseName("baseDonneEasyTicket");
    db.setUserName("guest");
    db.setPassword("1234");
    db.open();

   //creation requete


    //on verifie si la base de donnée a pu etre créer
    if(!db.isOpen()){
        qDebug() << "Erreur de connection a la base de donnée"
        << db.lastError();
    }else{

    creerTableUtilisateur();
    creerTableTicket();
    creerTableMessages();
}

}


void BaseDonnee::creerTableUtilisateur(){


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
    bool result = q.exec("CREATE TABLE IF NOT EXISTS Messages (id TEXT(10)  primary key, contenue TEXT(500),  dateCreation Text(20),idTicket text(10) );");
if (!result ){
      qDebug() << "erreur de creation de la table Message "
               << q.lastError();
  }
}

void BaseDonnee::ajouterUtilisateur(Utilisateur * u){
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

void BaseDonnee::ajouterTicket( Ticket * t){
    q.prepare("INSERT INTO Ticket VALUES (?,?,?,?,?,?,?,?,?,?)");
    q.addBindValue(t->getId());
    q.addBindValue(t->getStatut());
    q.addBindValue(t->getTitre());
    q.addBindValue(t->getCategorie());
    q.addBindValue(t->getLogiciel());
    q.addBindValue(t->getDateCreation());
    q.addBindValue(t->getDatePriseEnCharge());
    q.addBindValue(t->getDateCloture());
    q.addBindValue(t->getClient()->getLogin());
    q.addBindValue("");

   bool result = q.exec();
    if(!result){
        qDebug() << "erreur de la requete ajoutTicket "
                 << q.lastError();
    }
}

void BaseDonnee::ajouterMessage(Message *m ){
   q.prepare("INSERT INTO Messages VALUES (?,?,?,?)");
    q.addBindValue(m->getId());
    q.addBindValue(m->getContenu());
    q.addBindValue(m->getDateMessage());
    q.addBindValue(m->getTicket()->getId());
    bool result = q.exec();
    if(!result){
            qDebug() << "erreur de la requete ajoutMessage "
                     << q.lastError();
        }
}


void BaseDonnee::modifierTicket(Ticket * t){
    q.prepare("UPDATE Ticket SET status=?, categorie=?, logiciel=? ,dateCloture=? WHERE id=?");
     q.addBindValue(t->getStatut());
     q.addBindValue(t->getCategorie());
     q.addBindValue(t->getLogiciel());
     q.addBindValue(t->getDateCloture());
     q.addBindValue(t->getId());
     bool result = q.exec();
     if(!result){
             qDebug() << "erreur de la requete modifierTicket "
                      << q.lastError();
         }
}

void BaseDonnee::RecupererUtilisateur(const QString login,const QString mdp, Utilisateur* u){

    //Recuperation de L'user dans la BDD via le login et mdp saisit
    q.exec("Select  u.login, u.password, u.prenom, u.nom, u.role "
              "From User u "
              "where u.login=? and u.password=? ");

    q.addBindValue(login);
    q.addBindValue(mdp);
    bool result = q.exec();
    //instancie l'utilisateur en fonction de son role
    if(result){

        q.next();
        QString loginR = q.value(0).toString();
        QString prenomR =  q.value(2).toString();
        QString nomR =  q.value(3).toString();
        QString role = q.value(4).toString();

        if(role == "Ingénieur") u = new Ingenieur(loginR,nomR,prenomR);
        if(role == "Client") u = new Client(loginR,nomR,prenomR);
        if(role == "Technicien") u = new Technicien(loginR,nomR,prenomR);


    }else {
        qDebug() << q.lastError();
        qDebug() << "Mission echoué";
    }
}


void BaseDonnee::RecupererTicket(){

}

BaseDonnee::~BaseDonnee(){
    if(db.isOpen()){
        db.close();
    }
}
