#include "mainwindow.h"

#include <QApplication>
#include <basedonnee.h>
#include "utilisateur.h"
#include "ingenieur.h"

FabriqueIdentifiant *FabriqueIdentifiant::instance = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    //test BDD
    Ingenieur * abou ;
    Client * alpha =  new Client("client","asd","xcvx");

    Ticket * t = new Ticket("Reparatin","Sanitaire","twisk",alpha);
    Ticket * t2 = new Ticket("Reparatin2","Sanitaire","twisk",alpha);

    t->setCategorie("plomberie");
    Message * m = new Message("blablalbla","Aboulol",t);

    BaseDonnee * bd = new BaseDonnee();

   // bd->ajouterUtilisateur(abou);
    bd->ajouterTicket(t2);
  //  bd->ajouterMessage(m);
   // bd->modifierTicket(t);
    bd->RecupererUtilisateur("aboubacar","aboubacar",abou);

    return a.exec();

}
