#include "dialogcombobox.h"
#include "ui_dialogcombobox.h"

DialogComboBox::DialogComboBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogComboBox)
{
    ui->setupUi(this);
}

DialogComboBox::~DialogComboBox()
{
    delete ui;
}
