#ifndef DUENTIDADBASE_H
#define DUENTIDADBASE_H

#include <QString>

class DuEntidadBase
{
public:
    DuEntidadBase(int id, const QString &nombreDescripcion);
    virtual bool valida() const;

    int id() const
    {
        return mId;
    }

    QString nombreDescripcion() const
    {
        return mNombreDescripcion;
    }

    void setId(int id)
    {
        mId = id;
    }

    void setNombreDescripcion(const QString &nombreDescripcion)
    {
        mNombreDescripcion = nombreDescripcion;
    }
private:
    int mId;
    QString mNombreDescripcion;
};

#endif // DUENTIDADBASE_H
