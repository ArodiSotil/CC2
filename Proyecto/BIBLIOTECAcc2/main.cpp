#include "prueba.h"
#include <QApplication>
#include <DuCreadorBaseDeDatos.h>
#include <qmessagebox.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prueba w;
    a.setStyle("fusion");
    try {
        DuCreadorBaseDeDatos::configuraBaseDeDatos();
    } catch (const QString &mensajeError) {
        QMessageBox::critical(nullptr, QObject::tr("Error"), mensajeError);
        return EXIT_FAILURE;
    }
    w.show();

    return a.exec();
}
