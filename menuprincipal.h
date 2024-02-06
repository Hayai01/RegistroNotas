#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QMainWindow>
#include "ingresoestudiantesform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuPrincipal; }
QT_END_NAMESPACE

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    MenuPrincipal(QWidget *parent = nullptr);
    ~MenuPrincipal();
public slots:
    void recibirDatosEstudiante(const QString &nombre, const QString &apellido, double nota1, double nota2);
private slots:
    void on_actionRegistro_triggered();

    void on_actionGuardar_Datos_triggered();

private:
    Ui::MenuPrincipal *ui;
    void inicializarTablaCalificaciones();
    QString calcularEstado(double notaFinal) const;
    double calcularNotaRemedial(double notaFinal) const;
};
#endif // MENUPRINCIPAL_H
