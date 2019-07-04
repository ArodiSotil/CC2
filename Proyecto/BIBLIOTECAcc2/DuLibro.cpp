#include "DuLibro.h"
#include "DuAutor.h"
#include "DuEditorial.h"
#include "DuCreadorBaseDeDatos.h"

DuLibro::DuLibro(int id, const QString &nombre, int idAutor, int idEditorial)
    : DuEntidadBase(id, nombre)
    , mIdAutor(idAutor)
    , mIdEditorial(idEditorial)
{
}

DuLibro::DuLibro(const QString &nombre, int idAutor, int idEditorial)
    : DuEntidadBase(-1, nombre)
    , mIdAutor(idAutor)
    , mIdEditorial(idEditorial)
{
}

bool DuLibro::valida() const
{
    return DuEntidadBase::valida()
            && DuCreadorBaseDeDatos::existe("autor", idAutor())
            && DuCreadorBaseDeDatos::existe("editorial", idEditorial());
}
