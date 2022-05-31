#ifndef DATABASEFORM_H
#define DATABASEFORM_H

#include <QWidget>

namespace Ui {
class DataBaseForm;
}

class DataBaseForm : public QWidget
{
    Q_OBJECT

public:
    explicit DataBaseForm(QWidget *parent = nullptr);
    ~DataBaseForm();

private:
    Ui::DataBaseForm *ui;
};

#endif // DATABASEFORM_H
