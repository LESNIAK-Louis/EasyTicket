#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <QObject>

class Technicien : public QObject
{
    Q_OBJECT
public:
    explicit Technicien(QObject *parent = nullptr);

    Technicien(std::string login, std::string nom, std::string prenom);

    boolean estUnTechnicien()const;
    ~Technicien();
signals:

};

#endif // TECHNICIEN_H
