#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class DuFormBase;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionAcerca_de_triggered();
    void on_actionQuitar_aplicacion_triggered();
    void on_actionAltaLibro_triggered();
    void on_actionAltaAutor_triggered();
    void on_actionAltaEditorial_triggered();    
    void on_actionBajaAutor_triggered();
    void on_actionBajaLibro_triggered();
    void on_actionBajaEditorial_triggered();
    void on_actionConsultaLibro_triggered();
    void on_actionConsultaAutor_triggered();
    void on_actionConsultaEditorial_triggered();
    void on_actionModificacionLibro_triggered();
    void on_actionModificacionAutor_triggered();
    void on_actionModificacionEditorial_triggered();
private:
    void addSubWindow(DuFormBase *form);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
