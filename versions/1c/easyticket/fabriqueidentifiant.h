#ifndef FABRIQUEIDENTIFIANT_H
#define FABRIQUEIDENTIFIANT_H


class FabriqueIdentifiant
{
private:
    static FabriqueIdentifiant *instance;
    unsigned int idTicket;
    unsigned int idMessage;

    FabriqueIdentifiant(){
        idMessage = 0;
        idTicket = 0;
    }

public:
      static FabriqueIdentifiant* getInstance()
      {
          if(instance == NULL)
              instance = new FabriqueIdentifiant();
          return instance;
      }

      void resetIdTicket()
      {
        this->idTicket = 0;
      }

      void resetIdMessage()
      {
        this->idMessage = 0;
      }

      unsigned int getIdMessage(){ return this->idMessage++; }
      unsigned int getIdTicket(){ return this->idTicket++; }

};

#endif // FABRIQUEIDENTIFIANT_H
