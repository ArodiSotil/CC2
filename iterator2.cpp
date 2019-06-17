#include <iostream>

using namespace std;
template <typename T>
class Nodo
{
public:
	T dato;
	Nodo<T> *siguiente;
	Nodo(){
		dato=NULL;
		siguiente=NULL;
	}
	Nodo(T dato){
		this->dato = dato;
		siguiente=NULL;
	}
	~Nodo(){}
	void eliminar(){
		if (siguiente)
		{
			siguiente->eliminar();
		}
		delete this;
	}

	
};

template <typename T>
class ListaNodo
{
public:
	Nodo<T> *nodo;
	int cantidad=0;
	ListaNodo(){
		nodo=NULL;
	}
	~ListaNodo(){}
	void insertar(T valor){
		Nodo<T> *nuevoNodo = new Nodo<T>(valor);
		nuevoNodo->siguiente=nodo;
		nodo=nuevoNodo;
		cantidad++;
	}
	void insertarFinal(T valor){
		Nodo<T> *nuevoNodo = new Nodo<T>(valor);
		Nodo<T> *auxiliar = nodo;
		if(!nodo){
			nodo = nuevoNodo;
		}
		else{
			while(auxiliar->siguiente != NULL){
				auxiliar=auxiliar->siguiente;
			}
			auxiliar->siguiente=nuevoNodo;
		}
		cantidad++;
	}
	void llenar(){
		cout << "\t\tIngrese Lista enlazada.\n\n";
		T valor;
		int tamanio;
		cout << "Ingrese el Tamanio: ";
		cin >>tamanio;
		fflush(stdin);
		for (int i = 0 ; i < tamanio; ++i)
		{
			cout << "Elemento: ";
			cin >> valor;
			insertar(valor);
		}
	}
	void insertarPosicion(T valor, int pos){
		Nodo<T> *nuevoNodo=new Nodo<T>(valor);
		Nodo<T> *antes = nodo;
		if (!nodo)
		{
			nodo=nuevoNodo;
		}
		else{
			if (pos == 1)
			{
				nuevoNodo->siguiente=nodo;
				nodo=nuevoNodo;
			}
			else{
				for (int i = 1; i < pos-1; ++i)
				{
					antes = antes->siguiente;
					if (antes->siguiente ==NULL)
					{
						break;
					}
					
				}

				nuevoNodo->siguiente = antes->siguiente;
				antes->siguiente = nuevoNodo;
				
			}
		}
		cantidad++;
	}
	void ordenar(){
		T temp;
		Nodo<T> *temporal=nodo;
		Nodo<T> *tempNodo= temporal;

		while(temporal){
			tempNodo=temporal;
			while(tempNodo->siguiente != NULL){
				tempNodo=tempNodo->siguiente;
				if(temporal->dato > tempNodo->dato){
					temp =temporal->dato;
					temporal->dato = tempNodo->dato;
					tempNodo->dato=temp;
				}
				
			}
			temporal = temporal->siguiente;
		}
	}
	void insertarEnOrden(T valor){
		Nodo<T> *nuevoDato = new Nodo<T>(valor);
		Nodo<T> *temporal = nodo;
		if(!nodo){
			nodo = nuevoDato;
		}
		else{
			if (nodo->dato > nuevoDato->dato)
			{
				nuevoDato->siguiente = nodo;
				nodo=nuevoDato;
			}
			else{
				while((temporal->siguiente != NULL) /*&& (temporal->siguiente->dato >= valor)*/){
					if (temporal->siguiente->dato >= valor)
					{
						nuevoDato->siguiente=temporal->siguiente;
						temporal->siguiente=nuevoDato;
						break;
					}
					temporal=temporal->siguiente;
				}
				if (temporal->siguiente==NULL)
				{
					temporal->siguiente = nuevoDato;
				}
			}
		}
		cantidad++;
	}
	void imprimir(){
		Nodo<T> *temporal = nodo;
		cout << "Lista enlazada: ";
		if (!nodo)
		{
			cout << "Vacio\n";
		}
		else{
			while(temporal){
				cout << temporal->dato <<" ";
				if (temporal->siguiente==NULL)
				{
					cout <<endl;
				}
				temporal=temporal->siguiente;
			}
		}
	}
	void eliminarDato(T valor){
		//Nodo<T> *nuevoNodo = new Nodo<T>(valor);
		Nodo<T> *temporal = nodo;
		Nodo<T> *sig = temporal->siguiente;
		int cont=0;
		if (!nodo)
		{
			cout << "LISTA VACIA:\n";
		}
		else{
			if (nodo->dato == valor)
			{
				nodo=nodo->siguiente;
				delete temporal;
			}
			else{
				while(sig){
					if(sig->dato == valor){

						Nodo<T> *aux = sig;
						temporal->siguiente=sig->siguiente;
						delete aux;
						cont++;
						cantidad--;
						break;
					}
					temporal=temporal->siguiente;
					sig=sig->siguiente;

				}
				if(cont == 0){
					cout <<"no estas\n"; 
				}
			}

		}
	}
	void eliminarPos(int pos){
		Nodo<T> *temporal = nodo;
		Nodo<T> *sig = temporal->siguiente;
		int i=2;
		if (!nodo)
		{
			cout << "LISTA VACIA:\n";
		}
		else{
			if (pos == 1)
			{
				nodo=nodo->siguiente;
				delete temporal;
			}
			else if(pos <= cantidad){
					while(sig){
						if(i==pos){

							Nodo<T> *aux = sig;
							temporal->siguiente=sig->siguiente;
							delete aux;

							cantidad--;
							break;
							
						}
						temporal=temporal->siguiente;
						sig=sig->siguiente;
						i++;
					}
				
				
			}
			else
				cout <<"Es mayor que el tamanio de la lista.\n";

		}
	}
	void eliminarNodos(){
		nodo->eliminar();
		nodo=0;
	}

};
template <typename T>
class Iterator
	{
	public:
		//NodoLinked<T> *lista;
		Nodo<T> *nodo;
		Iterator(){
			
		}

		~Iterator(){}

		
		Iterator<T> operator ++(int){
			Iterator<T> iterator = *this;
			++*this;
			return iterator;
		}
		Iterator<T>& operator ++(){
			if (nodo)
			{
				nodo = nodo->siguiente;
			}
			
			return *this;
		}
		Iterator<T> operator =(const ListaNodo<T> a){
			this->nodo=a.nodo;
			return *this;
		}
		
		T operator *(){
			return nodo->dato;
		}
		bool operator !=(const Iterator<T> &ite){
			return nodo != ite.nodo;
		}
		
		
	};	
int main(){
	string lista[6]={"carlos","pedro","elsa","brenda","delma","fabiola"};
	ListaNodo<string> a;
	for (int i = 0; i < 6; ++i)
	{
		a.insertar(lista[i]);
	}
	
	//a.llenar();
	a.imprimir();
	cout << "\nIngresando el valor SANTIAGO a la ultima posicion.\n\n";
	a.insertarFinal("santiago");
	a.imprimir();
	cout <<"\nInsertando Arodi en la posicion 4.\n\n";
	a.insertarPosicion("Arodi",4);
	a.imprimir();
	cout << "\nOrdenando la lista.\n\n";
	a.ordenar();
	a.imprimir();
	cout << "\nInsertando JOSE segun orden.\n\n";
	a.insertarEnOrden("jose");
	a.imprimir();
	cout << "\nEliminando ELSA de nuestra lista.\n\n";
	a.eliminarDato("elsa");
	a.imprimir();
	cout << "\nEliminando la posicion 4.\n\n";
	a.eliminarPos(4);
	a.imprimir();
	//cout << a.cantidad;

	cout << "\n\n\t\tITERATOR\n\n";
	Iterator<string> it;
	it=a;
	//cout << *it;
	//cout << it;
	/*while(!it){
		cout << *it << endl;
		it++;
	}*/
	for (int i = 0; i < a.cantidad; ++i)
	{
		cout << *it << endl;

		++it;
	}

	cout << endl <<"DIFERENCIA"<<endl;
	Iterator<string> it2;
	string lista1[2]={"juana","maria"};
	ListaNodo<string> a1;
	for (int i = 0; i < 2; ++i)
	{
		a1.insertar(lista1[i]);
	}
	a1.imprimir();
	cout << endl;
	it2=a1;
	if (it != it2){
		cout << "LOS DOS ITERADORES SON DIFERENTES";
	}
		
	a.eliminarNodos();


	return 0;
	
}