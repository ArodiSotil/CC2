#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#define LENGTH 2
#define WIDTH 3

using namespace std;
//1.1.1
void printNTimes(char *msg,int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<msg<<endl;
	}
}
//1.1.1.3
void print(const long &x)
{
	cout<<x;
}
//1.1.3
/***********
int main()
{
	srand( time(5) );

	int randNum=rand();
	cout<<"A random number: "<<randNum<<endl;
	return 0;
}
**********/
//1.2.1
void setString(char **strPtr)
{
    int x;
    cin>>x;
    if(x<0)
        *strPtr = "Negatives!";
    else
        *strPtr = "Nonnegatives!";
}
//1.2.2
/*********
int *getRandNumPtr()
{
    int x = rand();
    return &x;
}
int main()
{
	int *randNumPtr = getRandNumPtr();
	cout << *randNumPtr; //error
	return 0;
}
***********/
//1.3.1
/*************
int main()
{
  const char *suitNames[] = {"Clubs ", "Diamonds ", "Spades ", "Clubs "};
  cout << "Enter a suit number (1-4): ";
  unsigned int suitNum;
  cin >> suitNum;
  if(suitNum <= 4)
  cout << suitNames[suitNum -1];
}
************/
//1.3.2
/****************
int main()
{
  const int ARRAY_LEN = 100;
  int arr [ ARRAY_LEN ];
  int *p = arr ;
  int *q = & arr [0];
}
*****************/
//problema 2
/*********************
void f(const int a=5)
{
	cout<<a*2<<"\n";
}
int a= 123;
int main()
{
	f(1);
	f(a);
	int b=3;
	f(b);
	int a=4;
	f(a);
	f();


}
***********/

//problema 3.1

/************
void printNum(int);//creo un prototipo antes de main
//tambien podia ponerse la misma funcion antes del main
int main()
{
	printNum(35);
	return 0;
}
void printNum(int number){std::cout<<number;}
***********/

//problea 3.2

/************
void printNum(int number){std::cout<<number;} // declaro un argumento de tipo int
// int number= 35 --- tambien podria glovalizar la varianle number
int main()
{
	int number =35;
	printNum(number);
	return 0;
}
***************/

//problema 3.3
/*************

void doubleNumber(int &num){num=num*2;}//paso por referencia para que asi el valor de num cambie
int main()
{
	int num=35;
	doubleNumber(num);
	std::cout<<num;
	return 0;
}
*************/
//problema 3.4
int difference( const int x, const int y) {
int diff = abs(x -y);
return diff;//retornamos diff
// return abs(x-y); --- desechamos la diferencia y solo retornamos eel abs(x-y);

}
//problema 3.5

int sum( const int x, const int y,const int z) {//agregamos el argumento z
return x+y+z;
}


//problema 3.6

/**************
const int ARRAY_LEN = 10;
int main() {
	int arr[ARRAY_LEN]={10};

	int *xPtr= arr, *yPtr= arr+ARRAY_LEN-1;//agregamos * antes del yPtr para que asi apunte a la ultima direccion del arr
	std::cout << *xPtr<<" "<<*yPtr;
return 0;
}
***********/
//4.1
int sum ( const int x , const int y ) {
    return x + y ;
}

double sum ( const double x , const double y ) {
    return x + y ;
}
//4.2
//Mezclar y combinar un int con un doble hace que sea ambiguo a cuál quieres llamar.
//El compilador podría convertir 1 a doble y llamar a la versión doble de sum,
//o podría convertir 10.0 a un int y llamar a la versión int

//4.3
/***********************
int sum ( const int x , const int y , const int z ) {
    return x + y + z ;
}

int sum ( const int a , const int b , const int c , const int d ) {
    return a + b + c + d ;
}
************/
//4.4
int sum( const int a, const int b, const int c = 0 , const int d = 0){
    return a + b + c + d ;
}

//4.5
int sum( const int numbers [], const int numbersLen ) {
    int sum = 0;
    for(int i = 0; i < numbersLen ; ++i ) {
    sum += numbers [ i];
    }
    return sum;
}
//4.6
/*int sum ( const int numbers [] , const int numbersLen ) {
    return numbersLen == 0 ? 0 : numbers [0] + sum ( numbers + 1 ,
    numbersLen - 1) ;
 }*/
//5.1
double x = rand () / ( double ) RAND_MAX , y = rand () / ( double ) RAND_MAX ;

//5.2
/*int dartsInCircle = 0;
    for(int i = 0; i < n ; ++ i ) {
        double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )
        RAND_MAX ;
        if( sqrt ( x * x + y * y ) < 1 ) {
        ++ dartsInCircle ;
        }
    }
*/
//5.3
double computePi ( const int n){
    srand ( time (0) ) ;
    int dartsInCircle = 0;

    for(int i = 0; i < n ; ++i ) {
        double x = rand () / ( double ) RAND_MAX , y = rand () / ( double )
            RAND_MAX ;
        if( sqrt ( x * x + y * y ) < 1 ) {
            ++ dartsInCircle ;
        }
    }
}

//6.1
void printArray ( const int arr [], const int len ) {
    for(int i = 0; i < len; ++i ) {
        cout << arr [ i];
        if( i < len -1) {
            cout << ", ";
        }
    }
}
//6.2
void reverse (int numbers [] , const int numbersLen ) {

    for(int i = 0; i < numbersLen / 2; ++ i ) {
        int tmp = numbers [ i ];
        int indexFromEnd = numbersLen - i - 1;
        numbers [ i ] = numbers [ indexFromEnd ];
        numbers [ indexFromEnd ] = tmp ;
    }
}

//6.3
void transpose ( const int input [][ LENGTH ] , int output [][ WIDTH ]) {

    for(int i = 0; i < WIDTH ; ++ i ) {
        for (int j = 0; j < LENGTH ; ++ j ) {
            output [ j ][ i ] = input [ i ][ j ];
        }
    }
}

//6.4 Se devolvería un puntero al primer elemento de la matriz,
//pero la matriz se habría ido Fuera de alcance, invalida el puntero.

//6.5

void reverse (int numbers [] , const int numbersLen ) {
    for(int i = 0; i < numbersLen / 2; ++ i ) {
            int tmp = *( numbers + i ) ;
            int indexFromEnd = numbersLen - i - 1;
            *( numbers + i ) = *( numbers + indexFromEnd ) ;
            *( numbers + indexFromEnd ) = tmp ;
    }
}

//7.1
int stringLength ( const char * str ) {
    int length = 0;
    while (*( str + length )!= '\0') {
        ++ length ;
    }
    return length ;
}

//7.2
void swap (int &x, int & y ) {
    int tmp = x ;
    x = y ;
    y = tmp;
}
//7.3
void swap (int *x , int * y ) {

    int tmp = * x ;
    *x = *y;
    *y = tmp;
}
//7.4
void swap (int ** x , int ** y ) {

    int *tmp = *x ;
    *x = *y ;
    *y = tmp ;
}

//7.5
/*
1.	 char *nthCharPtr = &oddOrEven[5];
2.	 nthCharPtr -= 2; or nthCharPtr = oddOrEven + 3;
3.	 cout << *nthCharPtr;
4.	 char **pointerPtr = &nthCharPtr;
5.	 cout << pointerPtr;
6.	 cout << **pointerPtr;
7.	 nthCharPtr++; to point to the next character in oddOrEven (i.e. one character past
     the location it currently points to)
8.	 cout << nthCharPtr - oddOrEven;

 */





 // r^2 is 1 , and a/4 = dartsInCircle /n, yielding this for pi:


int main(){


return 0;
}
