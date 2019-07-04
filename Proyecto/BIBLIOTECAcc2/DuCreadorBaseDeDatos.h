#ifndef DUCREADORBASEDEDATOS_H
#define DUCREADORBASEDEDATOS_H

#include <QSqlDatabase>

#define CREATE_TABLE_AUTOR \
    "CREATE TABLE IF NOT EXISTS autor" \
    "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
    ", nombre TEXT NOT NULL)"

#define CREATE_TABLE_EDITORIAL \
    "CREATE TABLE IF NOT EXISTS editorial" \
    "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
    ", nombre TEXT NOT NULL)"

#define CREATE_TABLE_LIBRO \
    "CREATE TABLE IF NOT EXISTS libro" \
    "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
    ", nombre TEXT NOT NULL" \
    ", idAutor INTEGER NOT NULL" \
    ", idEditorial INTEGER NOT NULL)"

class DuCreadorBaseDeDatos
{
public:
    DuCreadorBaseDeDatos(const QString &nombreBaseDatos);
    void creaBaseDeDatos();
    static void configuraBaseDeDatos();
    static bool existe(const QString &nombreTabla, int id);
    static void elimina(const QString &nombreTabla, int id);
private:
    QSqlDatabase mDb;
};

#endif // DUCREADORBASEDEDATOS_H
