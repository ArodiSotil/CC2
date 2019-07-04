#include "DuAltaAutorForm.h"
#include "ui_DuAltaAutorForm.h"
#include "DuAutor.h"
#include <QMdiSubWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

DuAltaAutorForm::DuAltaAutorForm(QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuAltaAutorForm)
{
    ui->setupUi(this);
}

DuAltaAutorForm::~DuAltaAutorForm()
{
    delete ui;
}

void DuAltaAutorForm::on_buttonBox_accepted()
{
    DuAutor autor(ui->nombreLineEdit->text());
    if (!autor.valida()) {
        return;
    }
    QSqlQuery q;
    q.prepare("INSERT INTO autor (nombre) VALUES (?)");
    q.addBindValue(autor.nombreDescripcion());
    if (!q.exec()) {
        QMessageBox::critical(this, tr("Error"), q.lastError().text());
        return;
    }
    subWindowDriver()->close();
}

void DuAltaAutorForm::on_buttonBox_rejected()
{
    subWindowDriver()->close();
}
