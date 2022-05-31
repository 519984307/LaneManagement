#include "showdialog.h"
#include "ui_showdialog.h"

ShowDialog::ShowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowDialog)
{
    ui->setupUi(this);
}

ShowDialog::~ShowDialog()
{
    delete ui;
}

void ShowDialog::slotShowPic(QString path)
{
    QPalette palette;

    QScopedPointer<QPixmap> labelPix(new QPixmap());
    labelPix.data()->load(path);
    palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->label->size(), Qt::IgnoreAspectRatio)));
    ui->label->setPalette(palette);
}
