#include "modoestudiante.h"
#include "ui_modoestudiante.h"
#include "prueba.h"
#include <QFile>
#include <QDebug>
#include <QDataStream>


ModoEstudiante::ModoEstudiante(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModoEstudiante)
{
    ui->setupUi(this);
   /* mModel = new QSqlQueryModel(this);
    mModel->setQuery(QString("SELECT * FROM %1").arg("libro"));
   */
    ui->buscar->setClearButtonEnabled(true);
    ui->tabla->setColumnCount(4);
    QStringList nombreColumnas;
    nombreColumnas<<"ID"<<"TITULO"<<"AUTOR"<<"TIPO";
    ui->tabla->setHorizontalHeaderLabels(nombreColumnas);
    ui->tabla->setColumnWidth(0,50);
    ui->tabla->setColumnWidth(1,350);
    ui->tabla->setColumnWidth(2,200);
    ui->tabla->setColumnWidth(3,100);
}

ModoEstudiante::~ModoEstudiante()
{
    delete ui;
}

inline QDataStream &operator<<(QDataStream &d, Libro &libro){
    return d<<libro.getId()<<libro.getTitulo()<<libro.getAutor()<<libro.getEditorial();
}
QDataStream &operator>>(QDataStream &d, Libro &libro){
    QString id;
    QString titulo;
    QString autor;
    QString editorial;

    d>>id>>titulo>>autor>>editorial;
    libro.setId(id);
    libro.setTirulo(titulo);
    libro.setIdAutor(autor);
    libro.setEditorial(editorial);
    return d;
}
void ModoEstudiante::imprime(Libro a){
    ui->tabla->insertRow(ui->tabla->rowCount());
    ui->tabla->setItem(ui->tabla->rowCount()-1,0,new QTableWidgetItem(a.getId()));
    ui->tabla->setItem(ui->tabla->rowCount()-1,1,new QTableWidgetItem(a.getTitulo()));
    ui->tabla->setItem(ui->tabla->rowCount()-1,2,new QTableWidgetItem(a.getAutor()));
    ui->tabla->setItem(ui->tabla->rowCount()-1,3,new QTableWidgetItem(a.getEditorial()));
}
void ModoEstudiante::on_inicio_clicked()
{
    prueba*ModoEstudiante=new prueba();
    ModoEstudiante->show();
    close();
}

void ModoEstudiante::on_porTitulo_clicked()
{
    ui->tabla->setRowCount(0);
    QString comun("la los de da la el");
    QFile archivo("./libro.txt");
    if(!archivo.open(QIODevice::ReadOnly)){
        qDebug()<<"Error: " << archivo.errorString();
        return;
    }
    //int tam = archivo.;
    //Libro a[];
    Libro a;
    QDataStream datos(&archivo);
    //int i=0;
    QString busca=ui->buscar->text();
    QStringList palabrasBusca;
    palabrasBusca = busca.split(" ");
     // Libro b[]={};
    //int tam=0;
    while (!datos.atEnd()) {

        datos>> a;
        QString name=a.getTitulo();
        QStringList palabrasName;
        palabrasName = name.split(" ");
        if(busca == name){
            imprime(a);
        }
        else{
        for (int i=0;i<palabrasBusca.size();i++) {
            for (int j=0;j<palabrasName.size();j++) {
                if(comun.contains(palabrasBusca.at(i), Qt::CaseInsensitive)){
                    break;
                }

                else if( (palabrasBusca.at(i)==palabrasName.at(j)) && name.contains(palabrasBusca.at(i), Qt::CaseInsensitive)  ){
                //ui->listWidget->addItem(a[i].getId()+" "+a[i].getTirulo()+" "+a[i].getIdAutor()+" "+a[i].getTipo()+" "+QString::number(a->getCantidad()));
                imprime(a);
                //    b[tam]=a;
                  //  tam++;
                }

            }
        }

    }
    }
    /*if(tam>0){
        for (int i=0;i<tam+1;i++) {
            imprime(b[i]);
        }
    }*/
    //delete a;
    archivo.close();
}

void ModoEstudiante::on_porAutor_clicked()
{
    ui->tabla->setRowCount(0);
    QString comun("la los de da la el");
    QFile archivo("./libro.txt");
    if(!archivo.open(QIODevice::ReadOnly)){
        qDebug()<<"Error: " << archivo.errorString();
        return;
    }
    //int tam = archivo.;
    //Libro a[];
    Libro a;
    QDataStream datos(&archivo);
    //int i=0;
    QString busca=ui->buscar->text();
    QStringList palabrasBusca;
    palabrasBusca = busca.split(" ");
     // Libro b[]={};
    //int tam=0;
    while (!datos.atEnd()) {

        datos>> a;
        QString name=a.getAutor();
        QStringList palabrasName;
        palabrasName = name.split(" ");
        if(busca == name){
            imprime(a);
        }
        else{
        for (int i=0;i<palabrasBusca.size();i++) {
            for (int j=0;j<palabrasName.size();j++) {
                if(comun.contains(palabrasBusca.at(i), Qt::CaseInsensitive)){
                    break;
                }

                else if( (palabrasBusca.at(i)==palabrasName.at(j)) && name.contains(palabrasBusca.at(i), Qt::CaseInsensitive)  ){
                //ui->listWidget->addItem(a[i].getId()+" "+a[i].getTirulo()+" "+a[i].getIdAutor()+" "+a[i].getTipo()+" "+QString::number(a->getCantidad()));
                imprime(a);
                //    b[tam]=a;
                  //  tam++;
                }

            }
        }

    }
    }
    /*if(tam>0){
        for (int i=0;i<tam+1;i++) {
            imprime(b[i]);
        }
    }*/
    //delete a;
    archivo.close();
}
