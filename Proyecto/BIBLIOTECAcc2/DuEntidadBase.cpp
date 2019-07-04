#include "DuEntidadBase.h"

DuEntidadBase::DuEntidadBase(int id, const QString &nombreDescripcion)
    : mId(id)
    , mNombreDescripcion(nombreDescripcion)
{
}

bool DuEntidadBase::valida() const
{
    return !mNombreDescripcion.isEmpty();
}
//BUSCA QUE ES ISeMOY
