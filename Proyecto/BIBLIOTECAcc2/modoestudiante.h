#ifndef MODOESTUDIANTE_H
#define MODOESTUDIANTE_H
#include "libro.h"

#include <QWidget>

namespace Ui {
class ModoEstudiante;
}
class QSqlQueryModel;
class ModoEstudiante : public QWidget
{
    Q_OBJECT

public:
    explicit ModoEstudiante(QWidget *parent = nullptr);
    ~ModoEstudiante();
    void imprime(Libro);

private slots:
    void on_inicio_clicked();

    void on_porTitulo_clicked();

    void on_porAutor_clicked();

private:
    Ui::ModoEstudiante *ui;
    QSqlQueryModel *mModel;
};

#endif // MODOESTUDIANTE_H
