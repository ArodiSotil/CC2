#include "prueba.h"
#include "ui_prueba.h"
#include "MainWindow.h"
#include "DuCreadorBaseDeDatos.h"
#include "modoestudiante.h"
#include "modobibliotecario.h"

prueba::prueba(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prueba)
{

    ui->setupUi(this);
}

prueba::~prueba()
{
    delete ui;
}

void prueba::on_bibliotecario_clicked()
{
    ModoBibliotecario *ventana= new ModoBibliotecario();
    ventana->show();
    close();
}



void prueba::on_estudiante_clicked()
{
    ModoEstudiante *ventana = new ModoEstudiante();
    ventana->show();
    close();
}
