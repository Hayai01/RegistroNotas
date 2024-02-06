#include "menuprincipal.h"
#include "ui_menuprincipal.h"
#include "ingresoestudiantesform.h"
#include <QTableWidgetItem>

MenuPrincipal::MenuPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
       ui->calificacionesTable->setColumnCount(6);
       QStringList headers = {"Nombre", "Nota 1", "Nota 2", "Nota Final", "Estado", "Nota Mínima"};
       ui->calificacionesTable->setHorizontalHeaderLabels(headers);

}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}




void MenuPrincipal::recibirDatosEstudiante(const QString &nombre, const QString &apellido, double nota1, double nota2)
{
    // Procesa los datos recibidos, por ejemplo, agregándolos a la tabla de calificaciones
    int rowCount = ui->calificacionesTable->rowCount();
    ui->calificacionesTable->setRowCount(rowCount + 1);

    QTableWidgetItem *itemNombre = new QTableWidgetItem(nombre + " " + apellido);
    ui->calificacionesTable->setItem(rowCount, 0, itemNombre);

    QTableWidgetItem *itemNota1 = new QTableWidgetItem(QString::number(nota1));
    ui->calificacionesTable->setItem(rowCount, 1, itemNota1);

    QTableWidgetItem *itemNota2 = new QTableWidgetItem(QString::number(nota2));
    ui->calificacionesTable->setItem(rowCount, 2, itemNota2);

    // Calcula la nota final, estado, nota mínima, etc., según sea necesario
}

void MenuPrincipal::on_actionRegistro_triggered()
{
    IngresoEstudiantesForm *ingresoEstudiantesForm = new IngresoEstudiantesForm(this);

        // Conectar la señal datosIngresados del formulario con el slot recibirDatosEstudiante de MenuPrincipal
        connect(ingresoEstudiantesForm, &IngresoEstudiantesForm::datosIngresados, this, &MenuPrincipal::recibirDatosEstudiante);

        // Establecer la ventana de ingreso de estudiantes como modal
        ingresoEstudiantesForm->setWindowModality(Qt::WindowModal);

        ingresoEstudiantesForm->show();
}
