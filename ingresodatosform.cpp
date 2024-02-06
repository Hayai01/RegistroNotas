#include "ingresodatosform.h"
#include "ui_ingresodatosform.h"

IngresoDatosForm::IngresoDatosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IngresoDatosForm)
{
    ui->setupUi(this);
}

IngresoDatosForm::~IngresoDatosForm()
{
    delete ui;
}
