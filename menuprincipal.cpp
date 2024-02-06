#include "menuprincipal.h"
#include "ui_menuprincipal.h"
#include "ingresoestudiantesform.h"
#include "ingresodatosform.h"

#include <QFileDialog>
#include <QTextStream>
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

    double notaFinal = nota1 + nota2;
    QString estado = calcularEstado(notaFinal);
    double notaRemedial = calcularNotaRemedial(notaFinal);


    int rowCount = ui->calificacionesTable->rowCount();
    ui->calificacionesTable->setRowCount(rowCount + 1);

    QTableWidgetItem *itemNombre = new QTableWidgetItem(nombre + " " + apellido);
    ui->calificacionesTable->setItem(rowCount, 0, itemNombre);

    QTableWidgetItem *itemNota1 = new QTableWidgetItem(QString::number(nota1));
    ui->calificacionesTable->setItem(rowCount, 1, itemNota1);

    QTableWidgetItem *itemNota2 = new QTableWidgetItem(QString::number(nota2));
    ui->calificacionesTable->setItem(rowCount, 2, itemNota2);

    QTableWidgetItem *itemNotaFinal = new QTableWidgetItem(QString::number(notaFinal));
    ui->calificacionesTable->setItem(rowCount, 3, itemNotaFinal);

    QTableWidgetItem *itemEstado = new QTableWidgetItem(estado);
    ui->calificacionesTable->setItem(rowCount, 4, itemEstado);

    QTableWidgetItem *itemNotaRemedial = new QTableWidgetItem(QString::number(notaRemedial));
    ui->calificacionesTable->setItem(rowCount, 5, itemNotaRemedial);
}

QString MenuPrincipal::calcularEstado(double notaFinal) const
{
    if (notaFinal < 25) {
        return "Reprobado";
    } else if (notaFinal < 70) {
        return "Remedial";
    } else {
        return "Aprobado";
    }
}

double MenuPrincipal::calcularNotaRemedial(double notaFinal) const
{
    if (notaFinal < 70) {
        return (70 - 0.4 * notaFinal) / 0.6;
    } else {
        return 0.0;
    }
}


void MenuPrincipal::on_actionRegistro_triggered()
{
    IngresoEstudiantesForm *ingresoEstudiantesForm = new IngresoEstudiantesForm();


        connect(ingresoEstudiantesForm, &IngresoEstudiantesForm::datosIngresados, this, &MenuPrincipal::recibirDatosEstudiante);


        ingresoEstudiantesForm->setWindowModality(Qt::ApplicationModal);

        ingresoEstudiantesForm->show();
}


void MenuPrincipal::on_actionGuardar_Datos_triggered()
{

    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar archivo CSV"), "", tr("Archivos CSV (*.csv)"));

        if (filePath.isEmpty())
            return;


        if (!filePath.endsWith(".csv", Qt::CaseInsensitive)) {
            filePath += ".csv";
        }

        if (filePath.isEmpty())
            return;


        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }


        QTextStream out(&file);


        QStringList headers;
        for (int i = 0; i < ui->calificacionesTable->columnCount(); ++i) {
            headers << ui->calificacionesTable->horizontalHeaderItem(i)->text();
        }
        out << headers.join(",") << "\n";


        for (int row = 0; row < ui->calificacionesTable->rowCount(); ++row) {
            QStringList rowData;
            for (int column = 0; column < ui->calificacionesTable->columnCount(); ++column) {
                QTableWidgetItem *item = ui->calificacionesTable->item(row, column);
                if (item) {
                    rowData << item->text();
                } else {
                    rowData << "";
                }
            }
            out << rowData.join(",") << "\n";
        }


        file.close();
}

