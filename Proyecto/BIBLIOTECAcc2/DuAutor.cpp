#include "DuAutor.h"

DuAutor::DuAutor(int id, const QString &nombre)
    : DuEntidadBase(id, nombre)
{
}

DuAutor::DuAutor(const QString &nombre)
    : DuEntidadBase(-1, nombre)
{
}
