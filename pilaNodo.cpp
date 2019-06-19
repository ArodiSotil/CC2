#include <iostream>

using namespace std;


template <typename T>
class Nodo
{

public:
	T dato;
	Nodo<T> *siguiente;
	Nodo();
	~Nodo();
	Nodo(T);
	void eliminar();
};
template <typename T>
Nodo<T>::Nodo(){
	dato = NULL;
	siguiente = NULL;
}
template <typename T>
Nodo<T>::Nodo(T dato){
	this->dato = dato;
	siguiente = NULL;
}
template <typename T>
Nodo<T>::~Nodo(){

}
template <typename T>
void Nodo<T>::eliminar(){
	if (siguiente)
	{
		siguiente->eliminar();
	}
	delete this;
}



/********PILA*********/
template <typename T>
class Pila
{
private:
	Nodo<T> *nodo;
public:
	Pila();
	~Pila(){}
	void push(T);
	void pop();
	void mostrarPila();
	void eliminarPila();
	
};

template <typename T>
Pila<T>::Pila(){
	nodo=NULL;
}

template <typename T>
void Pila<T>::push(T valor){
	Nodo<T> *nuevoNodo = new Nodo<T>(valor);
	if(!nodo){
		nodo=nuevoNodo;
	}
	else{
		nuevoNodo->siguiente = nodo;
		nodo = nuevoNodo;
	}
}

template <typename T>
void Pila<T>::pop(){
	//T valor;
	Nodo<T> *temporal = nodo;
	if (!nodo)
	{
		cout << "PILA VACIA"<<endl;
		exit(1);
	}
	else{
		//valor = nodo->dato;
		nodo = nodo->siguiente;
		delete temporal;
		//return valor;
	}
}

template <typename T>
void Pila<T>::mostrarPila(){
	T valor;
	Nodo<T> *temporal = nodo;
	if (!nodo)
	{
		cout << "PILA VACIA" <<endl;
		exit(1);
	}
	else
	{
		while(temporal){
			cout << temporal->dato << endl;
			temporal = temporal->siguiente;
		}
	}
}


template <typename T>
void Pila<T>::eliminarPila(){
	nodo->eliminar();
	nodo=0;
}

/////////////////////////////////////////////////////////
template <typename T>
class Cola
{
private:
	Nodo<T> *nodo;
public:
	Cola();
	~Cola(){}
	void push(T);
	void pop();
	void mostrarCola();
	void eliminarCola();
	
};

template <typename T>
Cola<T>::Cola(){
	nodo=NULL;
}

template <typename T>
void Cola<T>::push(T valor){
	Nodo<T> *nuevoNodo = new Nodo<T>(valor);
	Nodo<T> *temporal = nodo;
	if(!nodo){
		nodo=nuevoNodo;
	}
	else{
		while(temporal->siguiente != NULL){
			temporal=temporal->siguiente;

		}
		temporal->siguiente=nuevoNodo;
	}
}

template <typename T>
void Cola<T>::pop(){
	//T valor;
	Nodo<T> *temporal = nodo;
	if (!nodo)
	{
		cout << "PILA VACIA"<<endl;
		exit(1);
	}
	else{
		//valor = nodo->dato;
		nodo = nodo->siguiente;
		delete temporal;
		//return valor;
	}
}

template <typename T>
void Cola<T>::mostrarCola(){
	T valor;
	Nodo<T> *temporal = nodo;
	if (!nodo)
	{
		cout << "PILA VACIA" <<endl;
		exit(1);
	}
	else
	{
		while(temporal){
			cout << temporal->dato << endl;
			temporal = temporal->siguiente;
		}
	}
}


template <typename T>
void Cola<T>::eliminarCola(){
	nodo->eliminar();
	nodo=0;
}
/////////////////////////////////////////////////////////////
int main(){
	int lista[]={1,2,3,4,5,6,7,8,9,0};
	cout << "\t\tPILA\n";
	Pila<int> p;
	for (int i = 0; i < 10; ++i)
	{
		p.push(lista[i]);
	}
	p.mostrarPila();
	cout << "sacando de la Pila "<<endl;
	p.pop(); 
	p.mostrarPila();
	cout << endl;
	p.eliminarPila();

	cout << "\t\tCOLA\n";
	Cola<int> c;
	for (int i = 0; i < 10; ++i)
	{
		c.push(lista[i]);
	}
	c.mostrarCola();
	cout << endl;
	cout << "sacando de la Cola "<<endl;
	c.pop();
	cout << endl;
	c.mostrarCola();
	c.eliminarCola();
	return 0;
}





