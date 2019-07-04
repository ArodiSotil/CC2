#include "DuModificacionForm.h"
#include "ui_DuModificacionForm.h"
#include <QSqlTableModel>

DuModificacionForm::DuModificacionForm(const QString &nombreTabla,
                                       QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuModificacionForm)
{
    ui->setupUi(this);
    mModel = new QSqlTableModel(this);
    mModel->setTable(nombreTabla);
    mModel->select();
    ui->tableView->setModel(mModel);
    setWindowTitle(QString("Modificar ")
                   + nombreTabla[0].toUpper()
            + nombreTabla.mid(1));
}

DuModificacionForm::~DuModificacionForm()
{
    delete ui;
}
