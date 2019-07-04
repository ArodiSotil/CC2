#include "DuConsultaLibroForm.h"
#include "ui_DuConsultaLibroForm.h"
#include <QSqlQueryModel>

#define SELECT_LIBRO \
    "SELECT libro.id as ID, libro.nombre AS Título, " \
    "autor.nombre as Autor, editorial.nombre AS Editorial " \
    "FROM libro INNER JOIN autor, editorial WHERE" \
    " libro.idAutor = autor.id AND libro.idEditorial = editorial.id"

DuConsultaLibroForm::DuConsultaLibroForm(QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuConsultaLibroForm)
{
    ui->setupUi(this);
    mModel = new QSqlQueryModel(this);
    mModel->setQuery(SELECT_LIBRO);
    ui->tableView->setModel(mModel);
}

DuConsultaLibroForm::~DuConsultaLibroForm()
{
    delete ui;
}
