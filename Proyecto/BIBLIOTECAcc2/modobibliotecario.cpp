#include "modobibliotecario.h"
#include "ui_modobibliotecario.h"
#include "mainwindow.h"
#include <fstream>
#include <string>
#include <iostream>
#include "prueba.h"
//#include "administrar.h"
using namespace std;

ModoBibliotecario::ModoBibliotecario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModoBibliotecario)
{
    ui->setupUi(this);
    ui->lineEditContrasenia->setPlaceholderText("Contraseña");
    ui->lineEditContrasenia->setEchoMode(QLineEdit::Password);
}

ModoBibliotecario::~ModoBibliotecario()
{
    delete ui;
}

void ModoBibliotecario::on_inicio_clicked()
{

    prueba*ModoBibliotecario=new prueba();
    ModoBibliotecario->show();
    close();

}

void ModoBibliotecario::on_aceptar_clicked()
{
    QString contra_ingresada=ui->lineEditContrasenia->text();
    string contrasenia = contra_ingresada.toUtf8().constData();
    ifstream lectura("C:\\Users\\IdOrA\\Documents\\text\\contrasenia.txt",ios::in);
    string contra;


    if(!lectura){
        ui->mensaje->setText("error");
    }
    else {
        getline(lectura,contra);
        if(contrasenia == contra){
            ui->mensaje->setText("contraseña correcta");
            MainWindow *ventana = new MainWindow();
            ventana->show();
            close();
        }
        else {
            ui->mensaje->setText("contraseña incorrecta");
        }
    }
}
