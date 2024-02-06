#include "ingresoestudiantesform.h"
#include "ui_ingresoestudiantesform.h"
#include "QMessageBox"

IngresoEstudiantesForm::IngresoEstudiantesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IngresoEstudiantesForm)
{
    ui->setupUi(this);
}

IngresoEstudiantesForm::~IngresoEstudiantesForm()
{
    delete ui;
}

void IngresoEstudiantesForm::on_pushButton_released()
{
    QString nombre = ui->nombresLineEdit->text();
    QString apellido = ui->apellidosLineEdit->text();
    double nota1 = ui->nota1LineEdit->text().toDouble();
    double nota2 = ui->nota2LineEdit->text().toDouble();

    // Verificar si las notas están dentro del rango de 0 a 50
    if (nota1 >= 0 && nota1 <= 50 && nota2 >= 0 && nota2 <= 50) {
        // Emitir la señal solo si las notas están dentro del rango permitido
        emit datosIngresados(nombre, apellido, nota1, nota2);
        close(); // Cerrar la ventana
    } else {
        // Mostrar un mensaje de advertencia si las notas están fuera del rango
        QMessageBox::warning(this, tr("Advertencia"), tr("Las notas deben estar en un rango de 0 a 50."));
    }
}

