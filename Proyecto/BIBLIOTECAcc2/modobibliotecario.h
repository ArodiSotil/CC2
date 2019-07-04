#ifndef MODOBIBLIOTECARIO_H
#define MODOBIBLIOTECARIO_H

#include <QWidget>

namespace Ui {
class ModoBibliotecario;
}

class ModoBibliotecario : public QWidget
{
    Q_OBJECT

public:
    explicit ModoBibliotecario(QWidget *parent = nullptr);
    ~ModoBibliotecario();

private slots:
    void on_inicio_clicked();

    void on_aceptar_clicked();

private:
    Ui::ModoBibliotecario *ui;

};

#endif // MODOBIBLIOTECARIO_H
