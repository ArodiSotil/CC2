#include "DuAltaLibroForm.h"
#include "ui_DuAltaLibroForm.h"
#include "DuSelectorDialog.h"
#include "DuLibro.h"
#include <QMdiSubWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "libro.h"
#include <QDataStream>
#include <QFile>
#include <QDebug>




DuAltaLibroForm::DuAltaLibroForm(QWidget *parent)
    : DuFormBase(parent)
    , ui(new Ui::DuAltaLibroForm)
{
    ui->setupUi(this);
}
inline QDataStream &operator<<(QDataStream &d, Libro &libro){
    return d<<libro.getId()<<libro.getTitulo()<<libro.getAutor()<<libro.getEditorial();
}
DuAltaLibroForm::~DuAltaLibroForm()
{
    delete ui;
}

void DuAltaLibroForm::on_buttonBox_accepted()
{
    DuLibro libro(ui->nombreLineEdit->text(),
                  ui->autorLineEdit->text().toInt(),
                  ui->editorialLineEdit->text().toInt());
    if (!libro.valida()) {
        return;
    }
    QSqlQuery q;
    q.prepare("INSERT INTO libro (nombre,idAutor,idEditorial) VALUES (?,?,?)");
    q.addBindValue(libro.nombreDescripcion());
    q.addBindValue(libro.idAutor());
    q.addBindValue(libro.idEditorial());
    if (!q.exec()) {
        QMessageBox::critical(this, tr("Error"), q.lastError().text());
        return;
    }

    /*QSqlQuery a;
    a.prepare("SELECT nombre FROM autor WHERE id = ?");
    a.addBindValue(libro.idAutor());

    QString autor= a.value(0).toByteArray().constData();

    QSqlQuery t;
    t.prepare("SELECT nombre FROM editorial WHERE id = ?");
    t.addBindValue(libro.idEditorial());

    QString tipo = t.value(0).toByteArray().constData();

    QSqlQuery l;
    l.prepare("SELECT id FROM libro WHERE nombre = ?");
    l.addBindValue(libro.nombreDescripcion());

    QString id = l.value(0).toByteArray().constData();
    */

    Libro lib("",libro.nombreDescripcion(),au,tip);

    QFile archivo("./libro.txt");
    if(!archivo.open(QIODevice::Append)){
        qDebug()<<"Error: " << archivo.errorString();
        return;
    }
    QDataStream datos(&archivo);
    datos.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    datos<<lib;

    archivo.flush();
    archivo.close();







    subWindowDriver()->close();
   /* q.prepare(QString("SELECT count(*) FROM %1 WHERE id = ?")
              .arg(nombreTabla));
    q.addBindValue(id);
    q.exec();
    q.next();*/
}

void DuAltaLibroForm::on_buttonBox_rejected()
{
    subWindowDriver()->close();
}

void DuAltaLibroForm::on_autorSeleccionarPushButton_clicked()
{
    DuSelectorDialog d("Seleccionar Autor", "autor", this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    ui->autorLineEdit->setText(QString::number(d.id()));
    au=d.descrip();
}

void DuAltaLibroForm::on_editorialSeleccionarPushButton_clicked()
{
    DuSelectorDialog d("Seleccionar Editorial", "editorial", this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    ui->editorialLineEdit->setText(QString::number(d.id()));
    tip=d.descrip();

}
