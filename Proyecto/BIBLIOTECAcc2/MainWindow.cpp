#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DuAltaLibroForm.h"
#include "DuAltaAutorForm.h"
#include "DuAltaEditorialForm.h"
#include "DuBajaForm.h"
#include "DuConsultaForm.h"
#include "DuConsultaLibroForm.h"
#include "DuModificacionForm.h"
#include "DuModificacionLibroForm.h"
#include <QMdiSubWindow>
#include <QMessageBox>
#include <prueba.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSubWindow(DuFormBase *form)
{
    auto widgetForm = dynamic_cast<QWidget *>(form);
    auto subWindow = ui->mdiArea->addSubWindow(widgetForm);
    form->setSubWindowDriver(subWindow);
    subWindow->adjustSize();
    subWindow->setWindowIcon(widgetForm->windowIcon());
    subWindow->setWindowTitle(widgetForm->windowTitle());
    subWindow->show();
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionQuitar_aplicacion_triggered()
{
    prueba *ventan = new prueba();
    ventan->show();
    close();
}

void MainWindow::on_actionAltaLibro_triggered()
{
    addSubWindow(new DuAltaLibroForm(this));
}

void MainWindow::on_actionAltaAutor_triggered()
{
    addSubWindow(new DuAltaAutorForm(this));
}

void MainWindow::on_actionAltaEditorial_triggered()
{
    addSubWindow(new DuAltaEditorialForm(this));
}

void MainWindow::on_actionBajaAutor_triggered()
{
    addSubWindow(new DuBajaForm("autor", this));
}

void MainWindow::on_actionBajaLibro_triggered()
{
    addSubWindow(new DuBajaForm("libro", this));
}

void MainWindow::on_actionBajaEditorial_triggered()
{
    addSubWindow(new DuBajaForm("editorial", this));
}

void MainWindow::on_actionConsultaLibro_triggered()
{
    addSubWindow(new DuConsultaLibroForm(this));
}

void MainWindow::on_actionConsultaAutor_triggered()
{
    addSubWindow(new DuConsultaForm("autor", this));
}

void MainWindow::on_actionConsultaEditorial_triggered()
{
    addSubWindow(new DuConsultaForm("editorial", this));
}

void MainWindow::on_actionModificacionLibro_triggered()
{
    addSubWindow(new DuModificacionLibroForm(this));
}

void MainWindow::on_actionModificacionAutor_triggered()
{
    addSubWindow(new DuModificacionForm("autor", this));
}

void MainWindow::on_actionModificacionEditorial_triggered()
{
    addSubWindow(new DuModificacionForm("editorial", this));
}
