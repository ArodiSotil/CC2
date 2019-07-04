#ifndef DUEDITORIAL_H
#define DUEDITORIAL_H

#include "DuEntidadBase.h"

class DuEditorial : public DuEntidadBase
{
public:
    DuEditorial(int id, const QString &nombre);
    DuEditorial(const QString &nombre);
};

#endif // DUEDITORIAL_H
