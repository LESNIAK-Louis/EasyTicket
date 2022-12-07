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
    ~DialogComboBox();

private:
    Ui::DialogComboBox *ui;
};

#endif // DIALOGCOMBOBOX_H
