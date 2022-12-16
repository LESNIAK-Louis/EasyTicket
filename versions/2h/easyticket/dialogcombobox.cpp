#include "dialogcombobox.h"
#include "ui_dialogcombobox.h"

DialogComboBox::DialogComboBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogComboBox)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->result = "";
}

void DialogComboBox::addItem(QString item) const{
    ui->comboBoxChoix->addItem(item);
}

void DialogComboBox::on_buttonBox_accepted(){
    this->result = ui->comboBoxChoix->currentText();
}

void DialogComboBox::setTitle(QString string){
    this->setWindowTitle(string);
}

void const DialogComboBox::setMessage(QString string) const {
    ui->labelChoix->setText(string);
}

DialogComboBox::~DialogComboBox()
{
    delete ui;
}
