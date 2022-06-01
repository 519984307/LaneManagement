#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QMap>
#include <QAbstractButton>
#include <QPushButton>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

private:
    Ui::AddDialog *ui;

signals:

    ///
    /// \brief signalAddItem 添加数据
    /// \param item
    ///
    void signalAddItem(QMap<QString, QString> item);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // ADDDIALOG_H
