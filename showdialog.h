#ifndef SHOWDIALOG_H
#define SHOWDIALOG_H

#include <QDialog>
#include <QScopedPointer>
#include <QPalette>
#include <QPixmap>

namespace Ui {
class ShowDialog;
}

class ShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDialog(QWidget *parent = nullptr);
    ~ShowDialog();

private:
    Ui::ShowDialog *ui;

public slots:

    ///
    /// \brief slotShowPic 显示图片
    /// \param path
    ///
    void slotShowPic(QString path);
};

#endif // SHOWDIALOG_H
