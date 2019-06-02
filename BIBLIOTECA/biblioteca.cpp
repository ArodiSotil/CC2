#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Biblioteca
{
   public:
       char nombreLibro[100],autorNombre[50],codigoLibro[20],nombrePublicacion[50];
       int q,B,p;
       Biblioteca()
       {
           strcpy(nombreLibro,"Libro sin nombre");
           strcpy(autorNombre,"Autor sin nombre");
           strcpy(codigoLibro,"Libro sin ID");
           strcpy(nombrePublicacion,"Libro sin publicación");
           q=0;
           B=0;
           p=0;
       }
          void get();//menu
          void student();//estudiante
          void pass();//verificar contraseña
          void Bibliotecararian();//bibliotecario
          void password();//cambiar cotraseña
          void llenarDatos();//llenar datos libro
          void show(int);//mostrar detalles del libro
          void booklist(int);//listar libros
          void modify();//modificar , agregar, eliminar
          void see(int);//buscar libro
          int branch(int);//tipo de materia
          void issue();//presar libro
          void der(char[],int,int);//verificar libro para prestamo
          void multa(int,int,int,int,int,int);//en Proceso
};
void Biblioteca::llenarDatos()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tIngresar los Detalles \n";
                    cout<<"\n\t\tIngresa nombre del libro : ";
                    cin.getline(nombreLibro,100);
                    for(i=0;nombreLibro[i]!='\0';i++)
                    {
                    if(nombreLibro[i]>='a'&&nombreLibro[i]<='z')
                       nombreLibro[i]-=32;
                    }
                    cout<<"\n\t\tIngresa el nombre del autor : ";
                    cin.getline(autorNombre,50);
                    cout<<"\n\t\tIngresa el nombre de la publicacion : ";
                    cin.getline(nombrePublicacion,50);
                    cout<<"\n\t\tIngresa el id del libro : ";
                    cin.getline(codigoLibro,20);
                    cout<<"\n\t\tIngresa el precio del libro : ";
                    cin>>p;
                    cout<<"\n\t\tIngresa la cantidad del libro : ";
                    cin>>q;
}
void Biblioteca::show(int i)
{
    cout<<"\n\t\tNombre del libro : "<<nombreLibro<<endl;
    cout<<"\n\t\tNombre del autor del libro : "<<autorNombre<<endl;
    cout<<"\n\t\tID del libro : "<<codigoLibro<<endl;
    cout<<"\n\t\tPublicacion del libro : "<<nombrePublicacion<<endl;
    if(i==2)
    {
        cout<<"\n\t\tPrecio del Libro : "<<p<<endl;
        cout<<"\n\t\tCantidad del libro : "<<q<<endl;
    }
}
  void Biblioteca::booklist(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("libros.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tArchivo no encontrado.";
                else
                {
                    cout<<"\n\t    ************ Lista de libros ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPresiona una tecla para continuar.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    Bibliotecararian();
    }
  void Biblioteca::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Por favor escoge un a funcion :-\n";
    cout<<"\n\t\t1.Modificacion de archivos actuales\n\n\t\t2.Añadir un nuevo libro\n\n\t\t3.Eliminar un libro\n\n\t\t4.Atras\n";
    cout<<"\n\n\t\tIngresa tu eleccion: ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("libros.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tArchivo no encontrado\n";
                        cout<<"\n\t\tPresiona una tecla para continuar.....";
                        getch();
                        system("cls");
                        Bibliotecararian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPor favor elige una opcion :-\n";
                        cout<<"\n\t\t1.Buscar por nombre de libro\n\n\t\t2.Buscar por Id de libro\n";
                        cout<<"\n\t\tIngresa tu eleccion : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tIngresa el nombre del libro : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("libros.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&nombreLibro[i]!='\0'&&st1[i]!='\0'&&(st1[i]==nombreLibro[i]||st1[i]==nombreLibro[i]+32);i++);
                                        if(nombreLibro[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                llenarDatos();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tIngresa el Id del libro : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("libros.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&codigoLibro[i]!='\0'&&st1[i]!='\0'&&st1[i]==codigoLibro[i];i++);
                                        if(codigoLibro[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                llenarDatos();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tEntrada incorrecta.....:(\n";
                            cout<<"\n\t\tPresiona una tecla para continuar.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tLibro no encontrado.\n";
                            cout<<"\n\t\tPresiona una tecla para continuar.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tActualizacion exitosa!.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    llenarDatos();
                    ofstream outf("libros.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tLibro añadido exitosamente.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("libros.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tArchivo no encontrado\n";
                        cout<<"\n\t\tPresiona una tecla para continuar.....";
                        getch();
                        intf1.close();
                        system("cls");
                        Bibliotecararian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPor favor elige una opcioin para la eliminacion:-\n";
                        cout<<"\n\t\t1.Por nombre del libro\n\n\t\t2.Por id del libro\n";
                        cout<<"\n\t\tIngresa tu eleccion : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tIngresa el nombre del libro : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("libros.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&nombreLibro[i]!='\0'&&st1[i]!='\0'&&(st1[i]==nombreLibro[i]||st1[i]==nombreLibro[i]+32);i++);
                                        if(nombreLibro[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("libros.txt");
                    rename("temp.txt","libros.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tIngresa el Id del libro : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("libros.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&codigoLibro[i]!='\0'&&st1[i]!='\0'&&st1[i]==codigoLibro[i];i++);
                                        if(codigoLibro[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("libros.txt");
                    rename("temp.txt","libros.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tEntrada incorrecta.....:(\n";
                            cout<<"\n\t\tPresiona una tecla para continuar.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tLibro no encontrado.\n";
                            cout<<"\n\t\tPresiona una tecla para continuar.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tEliminacion exitosa.\n";

    }
    else if(i==4)
    {
    system("cls");
    Bibliotecararian();
    }
    else
    {
    cout<<"\n\t\tEntrada incorrecta.\n";
    cout<<"\n\t\tPresiona una tecla para continuar.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPresiona una tecla para continuar.....";
    getch();
    system("cls");
    Bibliotecararian();

  }
  int Biblioteca::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>ELige una rama(derivacion) :-\n";
      cout<<"\n\t\t1.Matematica\n\n\t\t2.Fisica\n\n\t\t3.Quimica\n\n\t\t4.historia\n\n\t\t5.Literatura\n\n\t\t6.Civica\n\n\t\t7.Ir al menu\n";
      cout<<"\n\t\tIngresa tu eleccion : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  student();
                  else
                    Bibliotecararian();
          default : cout<<"\n\t\tPor favor ingresa una opcion correcta :(";
                    getch();
                    system("cls");
                    branch(x);
        }
  }
  void Biblioteca::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("libros.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tArchivo no encontrado.\n";
            cout<<"\n\t\t->Presiona una tecla para continuar.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            Bibliotecararian();
        }

      system("cls");
      cout<<"\n\t\tPor favor elige una opcion :-\n";
      cout<<"\n\t\t1.Buscar por nombre\n\n\t\t2.Buscar por ID de libro\n";
      cout<<"\n\t\tIngresa tu eleccion : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tIngresa el nombre del libro : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&nombreLibro[i]!='\0'&&ch[i]!='\0'&&(ch[i]==nombreLibro[i]||ch[i]==nombreLibro[i]+32);i++);
            if(nombreLibro[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tLibro encontrado :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tIngresa el ID del libro : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&codigoLibro[i]!='\0'&&ch[i]!='\0'&&ch[i]==codigoLibro[i];i++);
              if(codigoLibro[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tLibro encontrado :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPor favor ingresa una opcion correcta :(";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tEste libro no esta disponible :( \n";

    cout<<"\n\t\tPresiona una tecla para continuar.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    Bibliotecararian();


  }
void Biblioteca::issue()//alquilar libro
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Por favor elige un a opcion :-\n";
    cout<<"\n\t\t1.Edicion del libro\n\n\t\t2.Ver edicion del libro\n\n\t\t3.Buscar estudiante que emitió libro\n\n\t\t4.libro de reemision\n\n\t\t5.Devolver libro\n\n\t\t6.Regresar al menu\n\n\t\tIngresa tu eleccion : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Por favor ingresa los detalles :-\n";
    cout<<"\n\t\tIngresa el nombre del libro : ";
    cin.getline(nombreLibro,100);
    cout<<"\n\t\tIngresa el ID del libro : ";
    cin.getline(codigoLibro,20);
    //strcpy(st,codigoLibro);
    der(codigoLibro,b,1);
    cout<<"\n\t\tIngresa el nombre del estudiante : ";
    cin.getline(autorNombre,100);
    cout<<"\n\t\tIngresa el ID del estudiante: ";
    cin.getline(nombrePublicacion,20);
    cout<<"\n\t\tIngresa la fecha : ";
    cin>>q>>B>>p;
    ofstream outf("estudiante.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tEmision exitosa.\n";
    }
    else if(i==2)
    {
    ifstream intf("estudiante.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->Los detalles son :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tNombre del estudiante : "<<autorNombre<<"\n\t\t"<<"ID del estudiante : "<<nombrePublicacion<<"\n\t\t"<<"Nombre del libro : "<<nombreLibro<<"\n\t\t"<<"ID del libro : "<<codigoLibro<<"\n\t\t"<<"Fecha : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Por favor ingresa los detalles :-\n";
        cout<<"\n\n\t\tIngresa el nombre del estudiante : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tIngresa el ID del estudiante: ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("estudiante.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;nombrePublicacion[i]!='\0'&&st1[i]!='\0'&&st1[i]==nombrePublicacion[i];i++);
              if(nombrePublicacion[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->Los detalles son :-\n";
                      cout<<"\n\t\tNombre del estudiante : "<<autorNombre;
                      cout<<"\n\t\tID del estudiante : "<<nombrePublicacion;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Detalles del libro *******\n";
                  cout<<"\n\t\tNombre del libro : "<<nombreLibro;
                  cout<<"\n\t\tID del libro : "<<codigoLibro;
                  cout<<"\n\t\tFecha : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNingun registro encontrado.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Por favor ingresa los detalles:-\n";
    cout<<"\n\n\t\tIngresa el ID del estudiante : ";
    cin.getline(st,50);
    cout<<"\n\t\tIngresa el ID del libro : ";
    cin.getline(st1,20);
    fstream intf("estudiante.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;codigoLibro[i]!='\0'&&st1[i]!='\0'&&st1[i]==codigoLibro[i];i++);
            for(j=0;nombrePublicacion[j]!='\0'&&st[j]!='\0'&&st[j]==nombrePublicacion[j];j++);
            if(codigoLibro[i]=='\0'&&nombrePublicacion[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\n\t\tIngresa nueva fecha : ";
                    cin>>q>>B>>p;
                    multa(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tReemision exitosa."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Por favor ingresa los detalles :-\n";
    cout<<"\n\t\tIngresa el Id del libro : ";
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\n\t\tIngresa el ID del estudiante : ";
    cin.getline(st,20);
    cout<<"\n\t\tIngresa la fecha actual : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("estudiante.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;codigoLibro[i]!='\0'&&st1[i]!='\0'&&st1[i]==codigoLibro[i];i++);
            for(j=0;nombrePublicacion[j]!='\0'&&st[j]!='\0'&&st[j]==nombrePublicacion[j];j++);
            if(codigoLibro[i]=='\0'&&nombrePublicacion[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    multa(q,B,p,d,m,y);
                    cout<<"\n\t\tDevuelto exitosamente.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("estudiante.txt");
    rename("temp.txt","estudiante.txt");
    }
    else if(i==6)
    {
    system("cls");
    Bibliotecararian();
    }
    else
        cout<<"\n\t\tEntrada incorrecta.\n";

    cout<<"\n\n\t\tPresiona una tecla para continuar.....";
    getch();
    system("cls");
    Bibliotecararian();
}
void Biblioteca::multa(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tLa multa total es : "<<n2;

}
void Biblioteca::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("libros.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&codigoLibro[i]!='\0'&&st[i]!='\0'&&st[i]==codigoLibro[i];i++);
        if(codigoLibro[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tLibro no encontrado.\n";
        cout<<"\n\n\t\tPresiona una tecla para continuar.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Biblioteca::get()
{
   int i;
        cout<<"\n\t*********** SISTEMA DE GESTION BIBLIOTECA ***********\n"<<"\n\t\t\t     C C 2\n";
        cout<<"\n\t\t>>Por favor elija una opcion para ingresar \n";
        cout<<"\n\t\t1.Estudiante\n\n\t\t2.Bibliotecario\n\n\t\t3.Salir\n";
        cout<<"\n\t\tIngresa tu eleccion : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPor favor ingresa una opcion correcta :(";
            getch();
            system("CLS");
           get();
        }
}
void Biblioteca::student()
{
    int i;
        cout<<"\n\t************ BIENVENIDO ESTUDIANTE ************\n";
        cout<<"\n\t\t>>Por favor elige una opcion:\n";
        cout<<"\n\t\t1.Ver lista de libros\n\n\t\t2.Buscar un libro\n\n\t\t3.Ir al menu principal\n\n\t\t4.Salir\n";
        cout<<"\n\t\tIngresa tu eleccion : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPor favor elige un aopcion corecta :(";
                getch();
                system("cls");
                student();
            }
}
void Biblioteca::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tIngresa la contrasenia : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        Bibliotecararian();
    }
    else
    {
        cout<<"\n\n\t\tContrasenia incorrecta.\n\n\t\Intentar de nuevo.....\n";
        getch();
        system("cls");
        get();
    }
}
void Biblioteca::Bibliotecararian()
{
    int i;
        cout<<"\n\t************ BIENVENIDO BIBLIOTECARIO ************\n";
        cout<<"\n\t\t>>Por favor elige una opcion:\n";
        cout<<"\n\t\t1.Ver lista de libro\n\n\t\t2.Buscar un libro\n\n\t\t3.Modificar / agregar libro\n\n\t\t4.libro de emision\n\n\t\t5.Ir al menu principal\n\n\t\t6.Cambiar contrasenia\n\n\t\t7.Salir\n";
        cout<<"\n\t\tIngresa tu eleccion: ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:password();
                    break;
            case 7:exit(0);
            default:cout<<"\n\t\tPor favor ingresa una opcion correcta :(";
            getch();
            system("cls");
            Bibliotecararian();
        }
}
void Biblioteca::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\n\t\tIngresa la contrasenia antigua : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**La contraseña debe ser menor a 20 caracteres y no debe tener espacios**\n\n";
        cout<<"\n\t\tIngresa la nueva contraseña : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tNo seguiste las instrucciones \n\n\t\tPresiona una tecla para volver a intentarlo.....";
                getch();
                system("cls");
                password();
                Bibliotecararian();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tTu contrasenia ha sido cambiada con exito!.";
        cout<<"\n\t\tPresiona un atecla para continuar......";
        getch();
        system("cls");
        Bibliotecararian();
    }
    else
    {
        cout<<"\n\n\t\tContrasenia incorrecta.....\n";
        cout<<"\n\t\tPresiona 1 para reintentar y 2 para menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            Bibliotecararian();
        }
    }
}
int main()
{
    Biblioteca obj;
    obj.get();
    getch();
    return 0;
}
