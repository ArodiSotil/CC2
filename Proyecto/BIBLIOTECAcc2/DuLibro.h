#ifndef DULIBRO_H
#define DULIBRO_H

#include "DuEntidadBase.h"

class DuLibro : public DuEntidadBase
{
public:
    DuLibro(int id, const QString &nombre, int idAutor, int idEditorial);
    DuLibro(const QString &nombre, int idAutor, int idEditorial);
    bool valida() const override;

    int idAutor() const
    {
        return mIdAutor;
    }

    int idEditorial() const
    {
        return mIdEditorial;
    }

    void setIdAutor(int id)
    {
        mIdAutor = id;
    }

    void setIdEditorial(int id)
    {
        mIdEditorial = id;
    }
private:
    int mIdAutor;
    int mIdEditorial;
};

#endif // DULIBRO_H
