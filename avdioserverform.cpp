#include "avdioserverform.h"
#include "ui_avdioserverform.h"

AvdioServerForm::AvdioServerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AvdioServerForm)
{
    ui->setupUi(this);
}

AvdioServerForm::~AvdioServerForm()
{
    delete ui;
}
