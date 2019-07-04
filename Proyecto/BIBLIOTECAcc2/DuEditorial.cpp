#include "DuEditorial.h"

DuEditorial::DuEditorial(int id, const QString &nombre)
    : DuEntidadBase(id, nombre)
{
}

DuEditorial::DuEditorial(const QString &nombre)
    : DuEntidadBase(-1, nombre)
{
}
