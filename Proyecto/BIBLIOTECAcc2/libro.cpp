#include "libro.h"


Libro::Libro()
{
    iD="";
    titulo="";
    autor="";
    editorial="";

}

Libro::Libro(QString iD, QString titulo, QString autor, QString editorial)
{
    this->iD=iD;
    this->titulo=titulo;
    this->autor=autor;
    this->editorial=editorial;
}
