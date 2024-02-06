#include "menuprincipal.h"
#include <QTranslator>
#include <QApplication>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traduccion;
    QStringList idiomas;
    idiomas << "Spanish" <<"German";

    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "language",
                                                       "Select an Lenguage",
                                                       idiomas);
    if(idiomaSeleccionado=="German"){
        traduccion.load(":/de_de.qm");
    }

    if(idiomaSeleccionado != "Spanish"){
        a.installTranslator(&traduccion);
    }

    MenuPrincipal w;
    w.show();
    return a.exec();
}
