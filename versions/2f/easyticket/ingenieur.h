#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "employe.h"

/**
 * @brief la classe qui represente un ingénieur
 */
class Ingenieur :  public Employe
{
public:

    /**
     * @brief constructeur d'un ingenieur
     * @param login d'un ingenieur
     * @param nom d'un ingenieur
     * @param prenom d'un ingenieur
     */
    Ingenieur(QString login, QString nom, QString prenom);

    /**
     * @brief retourne vrai si l'utilisateur est un employé
     * @return valeur du bool
     */
    inline bool estUnEmploye() const {return true;}

    /**
     * @brief retourne vrai si  si l'utilisateur est un ingénieur
     * @return valeur du bool
     */
    inline bool estUnIngenieur() const {return true;}

    /**
     * @brief retourne vrai s si l'utilisateur est un client
     * @return valeur du bool
     */
    inline bool estUnClient() const {return false;}

    /**
     * @brief retourne vrai si  si l'utilisateur est un technicien
     * @return valeur du bool
     */
    inline bool estUnTechnicien() const {return false;}

    /**
     * @brief retourne une QString avec le rôle de l'utilisateur
     * @return rôle de l'utilisateur
     */
    inline QString getRole() const { return "Ingénieur"; }

    /**
     * @brief destructeur pour la classe
     */
    ~Ingenieur();
};

#endif // INGENIEUR_H
