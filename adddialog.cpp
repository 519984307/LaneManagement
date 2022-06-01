#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button==ui->buttonBox->button(QDialogButtonBox::Ok)){

        QMap<QString,QString> item;
        item.insert("Plate",ui->lineEdit->text().trimmed());
        item.insert("ValidTime",ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss"));
        item.insert("Department",ui->lineEdit_2->text());
        item.insert("Blacklist",QString::number(ui->checkBox->isChecked()));
        item.insert("Validity",QString::number(ui->checkBox_2->isChecked()));
        item.insert("Name",ui->lineEdit_3->text());

        emit signalAddItem(item);
    }
}
