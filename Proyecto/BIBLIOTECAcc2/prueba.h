#ifndef PRUEBA_H
#define PRUEBA_H

#include <QDialog>

namespace Ui {
class prueba;
}

class prueba : public QDialog
{
    Q_OBJECT

public:
    explicit prueba(QWidget *parent = nullptr);
    ~prueba();

private slots:


    void on_bibliotecario_clicked();

    void on_estudiante_clicked();

private:
    Ui::prueba *ui;
};

#endif // PRUEBA_H
