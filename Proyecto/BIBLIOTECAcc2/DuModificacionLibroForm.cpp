#include "DuModificacionLibroForm.h"
#include "ui_DuModificacionLibroForm.h"
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

#define COLUMN_AUTOR 2
#define COLUMN_EDITORIAL 3

DuModificacionLibroForm::DuModificacionLibroForm(QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuModificacionLibroForm)
{
    ui->setupUi(this);
    mModel = new QSqlRelationalTableModel(this);
    mDelegate = new QSqlRelationalDelegate(this);

    mModel->setTable("libro");
    mModel->setRelation(COLUMN_AUTOR, QSqlRelation("autor", "id", "nombre"));
    mModel->setRelation(COLUMN_EDITORIAL,
                        QSqlRelation("editorial", "id", "nombre"));
    mModel->select();
    const QVector<QString> titulos { "ID", "Título", "Autor", "Editorial" };
    const int tam = titulos.size();
    for (int ix = 0; ix < tam; ++ix) {
        mModel->setHeaderData(ix, Qt::Horizontal, titulos[ix]);
    }
    ui->tableView->setModel(mModel);
    ui->tableView->setItemDelegate(mDelegate);
}

DuModificacionLibroForm::~DuModificacionLibroForm()
{
    delete ui;
}
