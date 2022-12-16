#include "utilisateur.h"

Utilisateur::Utilisateur(QString m_login, QString m_nom, QString m_prenom){
    this->login = m_login;
    this->nom = m_nom;
    this->prenom = m_prenom;

    gestionnaireTickets = new GestionnaireTickets();
}

Message* Utilisateur::cloturerTicket(Ticket& ticket, statutTicket statut, QString motif){
   if(&ticket != NULL){
       return &(ticket.cloturerTicket(statut, motif, QString(getPrenom() + " " + getNom())));
   }
   return nullptr;
}

void Utilisateur::chargerTickets(GestionnaireTickets& tickets) {

    delete gestionnaireTickets;
    this->gestionnaireTickets = &tickets;
}

Utilisateur::~Utilisateur()
{
    delete gestionnaireTickets;
}
