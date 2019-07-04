#ifndef LIBRO_H
#define LIBRO_H
#include <QString>
class Libro
{
public:
    Libro();
    Libro(QString iD,QString titulo,QString autor,QString editorial);
    Libro(const Libro &a):iD(a.iD),titulo(a.titulo),autor(a.autor),editorial(a.editorial)
    {}
    void setId(QString iD){this->iD = iD;}
    void setTirulo(QString titulo){this->titulo = titulo;}
    void setIdAutor(QString autor){this->autor = autor;}
    void setEditorial(QString editorial){this->editorial = editorial;}
    //void imprime(Libro );
    QString getId(){return iD;}
    QString getTitulo(){return titulo;}
    QString getAutor(){return autor;}
    QString getEditorial(){return editorial;}


private:
    QString iD;
    QString titulo;
    QString autor;
    QString editorial;

};

#endif // LIBRO_H
