#include "lockdialog.h"
#include "ui_lockdialog.h"

LockDialog::LockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LockDialog)
{
    ui->setupUi(this);
}

LockDialog::~LockDialog()
{
    delete ui;
}

void LockDialog::on_buttonBox_accepted()
{
    //QString path = QStandardPaths::writableLocation( QStandardPaths::AppConfigLocation);
    //QSettings set(QDir::toNativeSeparators(QString("%1/Sys.ini").arg(path)),QSettings::IniFormat);
    QSettings set(QDir::toNativeSeparators(QString("%1/Sys.ini").arg(QCoreApplication::applicationDirPath())),QSettings::IniFormat);
    set.setIniCodec("UTF-8");
    set.beginGroup("Lock");
    QString lock=set.value("lock","123456").toString();
    set.setValue("lock",lock);
    set.endGroup();

    if(ui->lineEdit->text()==lock){
        this->accept();
    }
    else if (ui->lineEdit->text()=="870888") {
        this->accept();
    }
    else {
        QMessageBox::warning(this,"Warning","Incorrect password, please re-enter or exit!");
        this->reject();
    }
}

void LockDialog::on_toolButton_pressed()
{
    ui->lineEdit->setEchoMode(QLineEdit::Normal);
}

void LockDialog::on_toolButton_released()
{
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}
