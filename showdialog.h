#ifndef SHOWDIALOG_H
#define SHOWDIALOG_H

#include <QDialog>
#include <QScopedPointer>
#include <QPalette>
#include <QPixmap>
#include <QResizeEvent>

namespace Ui {
class ShowDialog;
}

class ShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDialog(QWidget *parent = nullptr);
    ~ShowDialog();

    void resizeEvent(QResizeEvent* event)Q_DECL_OVERRIDE;

private:
    Ui::ShowDialog *ui;

    QString imgPath;

public slots:

    ///
    /// \brief slotShowPic 显示图片
    /// \param path
    ///
    void slotShowPic(QString path);
};

#endif // SHOWDIALOG_H
