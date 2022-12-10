#ifndef FABRIQUEIDENTIFIANT_H
#define FABRIQUEIDENTIFIANT_H

/**
 * @brief Fabrique qui retourne de maniére unique des identifiant pour Messages et Tickets
 */
class FabriqueIdentifiant
{
private:
    /**
     * @brief Instance Unique de la fabrique
     */
    static FabriqueIdentifiant *instance;

    /**
     * @brief ID d'un ticket
     */
    unsigned int idTicket;

    /**
     * @brief ID Message
     */
    unsigned int idMessage;

    /**
     * @brief constructeur de la classe
     */
    FabriqueIdentifiant(){
        idMessage = 0;
        idTicket = 0;
    }

public:
    /**
       * @brief retourne l'instance unique de la fabrique
       * @return
       */
      static FabriqueIdentifiant* getInstance()
      {
          if(instance == NULL)
              instance = new FabriqueIdentifiant();
          return instance;
      }

      /**
       * @brief renitialise l'id des tickets
       */
      void resetIdTicket()
      {
        this->idTicket = 0;
      }

      /**
       * @brief reset l'id des messages
       */
      void resetIdMessage()
      {
        this->idMessage = 0;
      }

      /**
       * @brief retourne un id unique
       * @return id du messages
       */
      unsigned int getIdMessage(){ return this->idMessage++; }

      /**
       * @brief retourne l'id d'un ticket
       * @return id du ticket
       */
      unsigned int getIdTicket(){ return this->idTicket++; }

      /**
       * @brief setter de l'id des tickets
       */
      void setIdTicket(int id)
      {
        this->idTicket = id;
      }

      /**
       * @brief setter de l'id des messages
       */
      void setIdMessage(int id)
      {
        this->idMessage = id;
      }


};

#endif // FABRIQUEIDENTIFIANT_H
