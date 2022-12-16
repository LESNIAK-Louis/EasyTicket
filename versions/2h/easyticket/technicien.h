#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "employe.h"

/**
 * @brief represente un technicien dans l'application
 * @author Aboubacar HASSANE CHEKOU KORE
 */
class Technicien : public Employe
{
public:
    /**
     * @brief Constucteur d'un Technicien
     * @param login  d'un Technicien
     * @param nom d'un Technicien
     * @param prenom d'un Technicien
     */
    Technicien(QString login, QString nom, QString prenom);

    /**
     * @brief retourne vrai si l'utilisateur est un employé
     * @return valeur du bool
     */
    inline bool estUnEmploye() const {return true;}

    /**
     * @brief retourne vrai s si l'utilisateur est un client
     * @return valeur du bool
     */
    inline bool estUnClient() const {return false;}

    /**
     * @brief retourne vrai si  si l'utilisateur est un ingénieur
     * @return valeur du bool
     */
    inline bool estUnIngenieur() const {return false;}

    /**
     * @brief retourne vrai si  si l'utilisateur est un technicien
     * @return valeur du bool
     */
    inline bool estUnTechnicien() const {return true;}

    /**
     * @brief retourne une QString avec le rôle de l'utilisateur
     * @return rôle de l'utilisateur
     */
    inline QString getRole() const { return "Technicien"; }

    /**
     * @brief destructeur de la classe
     */
    ~Technicien();
};

#endif // TECHNICIEN_H
