#ifndef DIALOGCOMBOBOX_H
#define DIALOGCOMBOBOX_H

#include <QDialog>

namespace Ui {
/**
 * @brief Classe qui contrôle le GUI de la boîte de dialogue qui contient la combobox
 * @author Louis LESNIAK
 */
class DialogComboBox;
}

class DialogComboBox : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Constructeur de la boîte de dialogue
     * @author Louis LESNIAK
     * @param parent Parent
     */
    explicit DialogComboBox(QWidget *parent = nullptr);

    /**
     * @brief Retourne le choix de la combobox
     * @author Louis LESNIAK
     * @return Résultat de la combobox
     */
    inline QString const getStringResult() const {return result;}

    /**
     * @brief Ajoute un élément à la combobox
     * @author Louis LESNIAK
     * @param item Elément à ajouter
     */
    void addItem(QString item) const;

    /**
     * @brief Setter du titre
     * @author Louis LESNIAK
     * @param string Titre à afficher
     */
    void setTitle(QString string);

    /**
     * @brief Setter du message
     * @author Louis LESNIAK
     * @return string Message à afficher
     */
    void const setMessage(QString string) const;

    /**
     * @brief Destructeur de la boîte de dialogue
     * @author Louis LESNIAK
     */
    ~DialogComboBox();

private slots:
    void on_buttonBox_accepted();

private:

    /**
     * @brief Elément du UI
     */
    Ui::DialogComboBox *ui;

    /**
     * @brief Valeur sélectionnée dans la combobox
     */
    QString result;
};

#endif // DIALOGCOMBOBOX_H
