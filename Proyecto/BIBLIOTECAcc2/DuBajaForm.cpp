#include "DuBajaForm.h"
#include "ui_DuBajaForm.h"
#include "DuSelectorDialog.h"
#include "DuCreadorBaseDeDatos.h"
#include <QMdiSubWindow>
#include <QMessageBox>

DuBajaForm::DuBajaForm(const QString &nombreTabla, QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuBajaForm)
{
    ui->setupUi(this);
    mNombreTabla = nombreTabla;
    setWindowTitle(QString("Baja ")
                   + nombreTabla[0].toUpper()
            + nombreTabla.mid(1));
}

DuBajaForm::~DuBajaForm()
{
    delete ui;
}

void DuBajaForm::on_seleccionarPushButton_clicked()
{
    DuSelectorDialog d("Seleccionar Autor", mNombreTabla, this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    ui->idLineEdit->setText(QString::number(d.id()));
}

void DuBajaForm::on_buttonBox_accepted()
{
    try {
        auto id = ui->idLineEdit->text();
        if (id.isEmpty()) {
            return;
        }
        DuCreadorBaseDeDatos::elimina(mNombreTabla, id.toInt());
    } catch (const QString &mensajeError) {
        QMessageBox::critical(this, tr("Error"), mensajeError);
    }
    subWindowDriver()->close();
}

void DuBajaForm::on_buttonBox_rejected()
{
    subWindowDriver()->close();
}
