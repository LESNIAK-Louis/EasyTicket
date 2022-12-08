#ifndef DIALOGCOMBOBOX_H
#define DIALOGCOMBOBOX_H

#include <QDialog>

namespace Ui {
class DialogComboBox;
}

class DialogComboBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogComboBox(QWidget *parent = nullptr);

    inline QString const getStringResult() const {return result;};
    void addItem(QString item) const;
    void setTitle(QString string);
    void const setMessage(QString string) const;

    ~DialogComboBox();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogComboBox *ui;
    QString result;
};

#endif // DIALOGCOMBOBOX_H
