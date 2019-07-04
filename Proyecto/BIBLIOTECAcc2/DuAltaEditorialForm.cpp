#include "DuAltaEditorialForm.h"
#include "ui_DuAltaEditorialForm.h"
#include "DuEditorial.h"
#include <QMdiSubWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

DuAltaEditorialForm::DuAltaEditorialForm(QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuAltaEditorialForm)
{
    ui->setupUi(this);
}

DuAltaEditorialForm::~DuAltaEditorialForm()
{
    delete ui;
}

void DuAltaEditorialForm::on_buttonBox_accepted()
{
    DuEditorial editorial(ui->nombreLineEdit->text());
    if (!editorial.valida()) {
        return;
    }
    QSqlQuery q;
    q.prepare("INSERT INTO editorial (nombre) VALUES (?)");
    q.addBindValue(editorial.nombreDescripcion());
    if (!q.exec()) {
        QMessageBox::critical(this, tr("Error"), q.lastError().text());
        return;
    }
    subWindowDriver()->close();
}

void DuAltaEditorialForm::on_buttonBox_rejected()
{
    subWindowDriver()->close();
}
