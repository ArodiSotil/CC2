#include <iostream>

using namespace std ;

//////1.2
/*class CDummy
{

public:

    static int n;

    CDummy(){++n ;
     }

    ~CDummy(){ --n; }
};
int CDummy::n = 0;
int main()
{
CDummy a;
CDummy b[5];
CDummy* c = new CDummy ;
cout <<a.n << "\n" ; // prints out 7
delete c;
cout << CDummy::n << "\n" ; // prints out 6
return 0;
}*/

//1.2.2
/***********
class CDummy
{
private:
    static int n;
public:



    CDummy(){++n ;
     }

    ~CDummy(){ --n; }
    static int getN(){return n;}
};
int CDummy::n = 0;
int main()
{
CDummy a;
CDummy b[5];
CDummy* c = new CDummy ;
cout <<a.getN() << "\n" ; // prints out 7
delete c;
cout << CDummy::getN()<< "\n" ; // prints out 6
return 0;
}
********/
////1.3

/***
const string & Person :: getName () const {

return name ;// Doesn ’t modify anything ; trying to modify a

            // data member from here would be a syntax error
}
***/

////1.4

/***
#include <string>
...
string s = " Hello " ;
s += " world ! " ;
if ( s == " Hello world ! " ) {
cout << " Success ! " << endl ;
}
cout << s . substr (6 , 6) << endl ; // Prints " world !"
cout << s . find ( " world " ) ; // ( prints "6")
cout << s . find ( "l" , 5) ; // ( prints "9")

***/

/*class Point
{
    private :
        int x , y ;
    public :
        Point ( int u , int v ) : x ( u ) , y ( v ) {}
        int getX () { return x ; }
        int getY () { return y ; }
        void doubleVal ()
        {
        x *= 2;
        y *= 2;
        }
};
int main ()
{
//const Point myPoint (5 , 3);//al delcararlo como constante los valores no pueden ser modificados
Point myPoint (5 , 3);//correcto no son variables constante lo cual pueden ser modificados
myPoint.doubleVal();
cout << myPoint . getX () << " " << myPoint . getY () << " \ n " ;
return 0;
}*/


//2.2


/*class Point
{
private :
int x , y ;
public :
Point ( int u , int v ) : x( u ) , y( v ) {}
int getX () { return x ; }
int getY () { return y ; }

//void setX ( int newX ) const { x = newX ; }//es una funcion const no se puede modificar;
void setX ( int newX ) { x = newX ; }//correcto puede modificarse (no es una funcion constante
};
int main ()
{
Point p (5 , 3) ;
p.setX (9001) ;
cout << p.getX () << ' ' << p.getY () ;
return 0;
}*/

///////////////2.3
/*class Point

{

    private :
        int x,y;//son variables privadas

     public :
        Point ( int u , int v ) : x( u ) , y( v ) {}
        int getX () { return x ; }
        int getY () { return y ; }
};
 int main ()
 {
Point p (5 , 3) ;
cout << p.x << " " << p . y << "\n" ;
return 0;
 }
 */

 ///////////2.4

 /***
class Point
{
private :
int x , y ;
public :
Point ( int u , int v ) : x ( u ) , y ( v ) {}
int getX () { return x ;}
void setX ( int newX ) ;
};
void Point::setX ( int newX ) { x = newX ; }//a void setX le falta el alcance  Point::setx()
int main ()
 {
Point p (5 , 3) ;
p.setX (0) ;
cout << p . getX () << " " << " \n " ;
return 0;
}
***/

/////2.5

/**
int main(){
int size ;
cin >> size ;
int * nums = new int [ size ];
for ( int i = 0; i < size ; ++ i )
{
cin >> nums [ i ];
}

// Calculations with nums omitted
delete[] nums ;//eliminar un array requiere del [] despues del delete
}

**/

///2.6

/***
class Point
{
private :
int x , y ;
public :
Point ( int u , int v ) : x ( u ) , y ( v ) {}
int getX () { return x ; }
int getY () { return y ; }
};
int main ()
{
Point *p = new Point(5 , 3) ;

cout << p->getX () << ' ' << p->getY () ;
delete p;//eliminar la memoria reservada.. cada vez que hay un new debe de eliminarse deltele
return 0;
}
***/


