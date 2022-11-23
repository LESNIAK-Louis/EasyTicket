#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QObject>

class Employe : public QObject,public Utilisateur
{
    Q_OBJECT
public:
    explicit Employe(QObject *parent = nullptr);


    Employe(std::string login, std::string nom, std::string prenom);
    bool estUnEmploye() const;
    ~Employe();

signals:

};

#endif // EMPLOYE_H
