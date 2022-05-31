#include "databaseform.h"
#include "ui_databaseform.h"

DataBaseForm::DataBaseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBaseForm)
{
    ui->setupUi(this);
}

DataBaseForm::~DataBaseForm()
{
    delete ui;
}
