#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "utilisateur.h"

/**
 * @brief la classe qui represente un employée
 */
class Employe : public Utilisateur
{
protected:
    /**
     * @brief Construction d'un employé
     * @param login d'un employé
     * @param nom d'un employé
     * @param prenom d'un employé
     */
    Employe(QString login, QString nom, QString prenom);

public:
    /**
     * @brief retourne vrai si l'utilisateur est un employé
     * @return valeur du bool
     */
    inline bool estUnEmploye() const {return true;}

    /**
     * @brief retourne vrai si l'utilisateur est un ingénieur
     * @return valeur du bool
     */
    virtual inline bool estUnIngenieur() const = 0;

    /**
     * @brief retourne vrai si l'utilisateur est un technicien
     * @return valeur du bool
     */
    virtual inline bool estUnTechnicien() const = 0;

    /**
     * @brief retourne une QString avec le rôle de l'utilisateur
     * @return rôle de l'utilisateur
     */
    virtual inline QString getRole() const = 0;

    /**
     * @brief Destructeur d'Employe
     */
    ~Employe();
};

#endif // EMPLOYE_H
