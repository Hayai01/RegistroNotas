#ifndef INGRESOESTUDIANTESFORM_H
#define INGRESOESTUDIANTESFORM_H

#include <QWidget>

namespace Ui {
class IngresoEstudiantesForm;
}

class IngresoEstudiantesForm : public QWidget
{
    Q_OBJECT

public:
    explicit IngresoEstudiantesForm(QWidget *parent = nullptr);
    ~IngresoEstudiantesForm();
signals:
    void datosIngresados(QString nombre, QString apellido, double nota1, double nota2);

private slots:
    void on_pushButton_released();

private:
    Ui::IngresoEstudiantesForm *ui;
};

#endif // INGRESOESTUDIANTESFORM_H
