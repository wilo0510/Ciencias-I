#include<iostream>
using namespace std;
struct Nodo{
	int elemento;
	Nodo *siguiente;
	Nodo* ant;
};
class ListaDoble{
	protected:
	Nodo *cabeza;
	Nodo *fin;
	public:
	ListaDoble(){
		cabeza=fin=NULL;
	}	
	void agregar(int);
	void mostrar();
	int eliminar();
	void eliminar(int);
	void InsertarDer(int,int);
	void InsertarIzq(int,int);
	Nodo *buscar(int);
	void ordenar();
	bool vacia();
};	
void ListaDoble::agregar(int elemento){
	Nodo *p=new Nodo;
	(*p).elemento=elemento;
	(*p).siguiente=cabeza;
	(*p).ant=NULL;
	if (cabeza)
		(*cabeza).ant=p;
	else
		fin=p;
	cabeza=p;
}
Nodo *ListaDoble::buscar(int elemento){
	Nodo *p=cabeza;
	while(p!=NULL){
		if(p->elemento==elemento){
			return p;
		}
		p=p->siguiente;
	}
	return NULL;
}
void ListaDoble::mostrar(){
	Nodo *p=cabeza;
	while(p!=NULL){
		cout<<p->elemento<<" ";
		p=p->siguiente;
	}		
}
int ListaDoble::eliminar(){
	Nodo *p=fin,*q;
	int elemento;
	q=p->ant;
	elemento=p->elemento;
	
	if (cabeza==p)
		cabeza=NULL;
	else
		p->ant->siguiente=p->siguiente;
	fin=p->ant;
	delete p;
	return elemento;
}
void ListaDoble::eliminar(int elemento){
	Nodo *p=cabeza;
	Nodo *temp;
	if(p->elemento==elemento){
		cabeza = p->siguiente;
		delete p;
	}else{
		//while(p)
	}
}
bool ListaDoble::vacia(){
	return cabeza==NULL;
}



class Cola:public ListaDoble{
	private:
		Nodo * fin;
	public:
		Cola(){
			cabeza=fin=NULL;
		}
		void agregar(int);
		int eliminar();
};

void Cola::agregar(int elemento)
{
		Nodo *p=new Nodo;
		(*p).elemento=elemento;
		p->siguiente=NULL;
		if(cabeza)
		fin->siguiente=p;
		else
		cabeza=p;
		fin=p;
}
int Cola::eliminar()
{
	int elemento=cabeza->elemento;
	Nodo *p=cabeza;
	cabeza=cabeza->siguiente;
	delete p;
	return elemento;
}
class Pila:public ListaDoble
{	

	public:
		Pila()
		{
			cabeza=NULL;
		}
		int eliminar();
};
int Pila::eliminar()
{
	int elemento=cabeza->elemento;
	Nodo *p=cabeza;
	cabeza=cabeza->siguiente;
	delete p;
	return elemento;
}
char menu(){
	char opcion;
	cout<<"\n MENU \n";
	cout<<"(A)gregar \n";
	cout<<"(E)liminar \n";
	cout<<"(M)ostrar \n";
	cout<<"(B)uscar \n";
	cout<<"(O)rdenar \n";
	cout<<"(S)alir \n";
	cout<<"Escoja una opcion: ";
	cin>>opcion;
	return opcion;			
}
int main(){
	ListaDoble lista;
	char opcion;
	int elemento;
	do{opcion=menu();
		switch(opcion){
			case'a':
			case'A':
				cout<<"Digite el elemento: ";
				cin>>elemento;
				lista.agregar(elemento);
				break;
			case 'm':
			case 'M':
				cout<<"\n Los elementos almacenados ; \n";
				lista.mostrar();
				break;
			case 'b':
			case 'B':
				cout<<"Ingrese el elemento a buscar \n";
				cin>>elemento;
				if(lista.buscar(elemento))
				{
					cout<<"El elemento se encuentra en "<<lista.buscar();
				}
				else
				{
					cout<<"no esta";
				}
					
				break;
			case 'e':
			case 'E':
				if(!lista.vacia())
				{
				
					cout<<"Digite el elemento a eliminar : ";
					cin>>elemento;
					cout<<"Eliminar ultimo elemento.El elemento eliminado es: "<<lista.eliminar(elemento);		
				}
				else
				{
					cout<<"No hay elementos para eliminar";
				}
				break;		
		}
	}while(opcion!='s' && opcion!='S');
	lista.agregar(20);
	cout<<"Elementos almacenados :\n";
	lista.mostrar();
}
