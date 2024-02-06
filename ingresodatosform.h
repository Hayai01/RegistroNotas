#ifndef INGRESODATOSFORM_H
#define INGRESODATOSFORM_H

#include <QWidget>

namespace Ui {
class IngresoDatosForm;
}

class IngresoDatosForm : public QWidget
{
    Q_OBJECT

public:
    explicit IngresoDatosForm(QWidget *parent = nullptr);
    ~IngresoDatosForm();

private:
    Ui::IngresoDatosForm *ui;
};

#endif // INGRESODATOSFORM_H
