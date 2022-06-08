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

void ShowDialog::resizeEvent(QResizeEvent *event)
{
    if(imgPath.isEmpty()){
        return;
    }
    Q_UNUSED(event)

    QPalette palette;

    QScopedPointer<QPixmap> labelPix(new QPixmap());
    labelPix.data()->load(imgPath);
    palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->label->size(), Qt::IgnoreAspectRatio)));
    ui->label->setPalette(palette);
}

void ShowDialog::slotShowPic(QString path)
{
    imgPath=path;

    QPalette palette;

    QScopedPointer<QPixmap> labelPix(new QPixmap());
    labelPix.data()->load(path);
    palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->label->size(), Qt::IgnoreAspectRatio)));
    ui->label->setPalette(palette);
}
