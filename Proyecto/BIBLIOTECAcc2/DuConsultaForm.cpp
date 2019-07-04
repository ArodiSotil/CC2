#include "DuConsultaForm.h"
#include "ui_DuConsultaForm.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

DuConsultaForm::DuConsultaForm(const QString &nombreTabla, QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuConsultaForm)
{
    ui->setupUi(this);
    mModel = new QSqlQueryModel(this);
    mModel->setQuery(QString("SELECT * FROM %1").arg(nombreTabla));
    ui->tableView->setModel(mModel);
    setWindowTitle(QString("Consulta ")
                   + nombreTabla[0].toUpper()
            + nombreTabla.mid(1));
}

DuConsultaForm::~DuConsultaForm()
{
    delete ui;
}
