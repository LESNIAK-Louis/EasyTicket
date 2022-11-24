#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "utilisateur.h"

/**
 * @brief la classe qui represente un employée
 */
class Employe : public Utilisateur
{
public:

    /**
     * @brief Construction d'un employé
     * @param login d'un employé
     * @param nom d'un employé
     * @param prenom d'un employé
     */
    Employe(QString login, QString nom, QString prenom);

    /**
     * @brief retourne vreai si c'est un employé
     * @return valeur du bool
     */
    bool estUnEmploye() const;


    /**
     * @brief Destructeur d'Employe
     */
    ~Employe();
};

#endif // EMPLOYE_H
