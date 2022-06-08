#ifndef AVDIOSERVERFORM_H
#define AVDIOSERVERFORM_H

#include <QWidget>

namespace Ui {
class AvdioServerForm;
}

class AvdioServerForm : public QWidget
{
    Q_OBJECT

public:
    explicit AvdioServerForm(QWidget *parent = nullptr);
    ~AvdioServerForm();

private:
    Ui::AvdioServerForm *ui;
};

#endif // AVDIOSERVERFORM_H
