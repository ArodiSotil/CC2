#ifndef DUAUTOR_H
#define DUAUTOR_H

#include "DuEntidadBase.h"

class DuAutor : public DuEntidadBase
{
public:
    DuAutor(int id, const QString &nombre);
    DuAutor(const QString &nombre);
};

#endif // DUAUTOR_H
