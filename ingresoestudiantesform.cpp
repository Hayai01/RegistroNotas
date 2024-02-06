#include "ingresoestudiantesform.h"
#include "ui_ingresoestudiantesform.h"

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

        emit datosIngresados(nombre, apellido, nota1, nota2);
}

