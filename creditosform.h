#ifndef CREDITOSFORM_H
#define CREDITOSFORM_H

#include <QWidget>

namespace Ui {
class CreditosForm;
}

class CreditosForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreditosForm(QWidget *parent = nullptr);
    ~CreditosForm();

private slots:


    void on_linkGithub_linkActivated(const QString &link);

private:
    Ui::CreditosForm *ui;
};

#endif // CREDITOSFORM_H
