#include "DuCreadorBaseDeDatos.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QVariant>

DuCreadorBaseDeDatos::DuCreadorBaseDeDatos(const QString &nombreBaseDatos)
{
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        throw QString(QObject::tr("El driver de SQLite no fue cargado"));
    }
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(nombreBaseDatos);
}

void DuCreadorBaseDeDatos::creaBaseDeDatos()
{
    if (!mDb.open()) {
        throw QString(mDb.lastError().text());
    }
    QSqlQuery q;
    if (!q.exec(CREATE_TABLE_AUTOR)) {
        throw q.lastError().text();
    }
    if (!q.exec(CREATE_TABLE_EDITORIAL)) {
        throw q.lastError().text();
    }
    if (!q.exec(CREATE_TABLE_LIBRO)) {
        throw q.lastError().text();
    }
}

void DuCreadorBaseDeDatos::configuraBaseDeDatos()
{
    try {
        DuCreadorBaseDeDatos creadorBaseDatos("./data.db");
        creadorBaseDatos.creaBaseDeDatos();
    } catch (const QString &mensajeError) {
        throw mensajeError;
    }
}

bool DuCreadorBaseDeDatos::existe(const QString &nombreTabla, int id)
{
    QSqlQuery q;
    q.prepare(QString("SELECT count(*) FROM %1 WHERE id = ?")
              .arg(nombreTabla));
    q.addBindValue(id);
    q.exec();
    q.next();

    return q.value(0).toInt() == 1;

}

void DuCreadorBaseDeDatos::elimina(const QString &nombreTabla, int id)
{
    QSqlQuery q;
    q.prepare(QString("DELETE FROM %1 WHERE id = ?").arg(nombreTabla));
    q.addBindValue(id);
    if (!q.exec()) {
        throw q.lastError().text();
    }
}
