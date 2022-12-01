#include "utilisateur.h"

Utilisateur::Utilisateur(QString m_login, QString m_nom, QString m_prenom){
    this->login = m_login;
    this->nom = m_nom;
    this->prenom = m_prenom;

    gestionnaireTickets = new GestionnaireTickets();
}

void Utilisateur::cloturerTicket(Ticket* ticket, statutTicket statut, QString motif){
   if(ticket != NULL){
       ticket->cloturerTicket(statut, motif, QString(getPrenom() + " " + getNom()));
   }
}

Utilisateur::~Utilisateur()
{
    delete gestionnaireTickets;
}
