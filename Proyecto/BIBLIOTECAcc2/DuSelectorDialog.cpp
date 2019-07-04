#include "DuSelectorDialog.h"
#include "ui_DuSelectorDialog.h"
#include <QSqlQueryModel>

#define ID_COLUMN 0
#define DES_COLUMNA 1

DuSelectorDialog::DuSelectorDialog(const QString &tituloDeVentana,
                                   const QString &nombreTabla,
                                   QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DuSelectorDialog)
{
    ui->setupUi(this);
    mId = -1;
    mModel = new QSqlQueryModel(this);
    mModel->setQuery(QString("SELECT * FROM %1").arg(nombreTabla));
    ui->tableView->setModel(mModel);
    setWindowTitle(tituloDeVentana);
}

DuSelectorDialog::~DuSelectorDialog()
{
    delete ui;
}

void DuSelectorDialog::on_buttonBox_accepted()
{
    const int rowCount = mModel->rowCount();
    if (rowCount == 0) {
        return;
    }
    const int currentRow = ui->tableView->currentIndex().row();
    mId = mModel->index(currentRow, ID_COLUMN).data().toInt();
    descripcion = mModel->index(currentRow,DES_COLUMNA).data().toString();
    accept();
}

void DuSelectorDialog::on_buttonBox_rejected()
{
    reject();
}
