#include<iostream>
using namespace std;
struct Nodo{
	int elemento;
	Nodo *siguiente;
};
class ListaDinamica{
	protected:
	Nodo *cabeza;
	public:
	ListaDinamica(){
		cabeza=NULL;
	}	
	void agregar(int);
	void mostrar();
	int eliminar();
	void eliminar(int);
	Nodo *buscar(int);
	void ordenar();
	bool vacia();
};	
void ListaDinamica::agregar(int elemento){
	Nodo *p=new Nodo;
	(*p).elemento=elemento;
	(*p).siguiente=cabeza;
	cabeza=p;
}
Nodo *ListaDinamica::buscar(int elemento){
	Nodo *p=cabeza;
	while(p!=NULL){
		if(p->elemento==elemento){
			return p;
		}
		p=p->siguiente;
	}
	return NULL;
}
void ListaDinamica::mostrar(){
	Nodo *p=cabeza;
	while(p!=NULL){
		cout<<p->elemento<<" ";
		p=p->siguiente;
	}		
}
int ListaDinamica::eliminar(){
	int info;
	Nodo *p=cabeza;
	Nodo *q=cabeza->siguiente;
	while(q->siguiente!=NULL){
		p=q;
		q=q->siguiente;
	}
	p->siguiente=NULL;
	info = q->elemento;
	delete q;
	return info;
}
void ListaDinamica::eliminar(int elemento){
	Nodo *p=cabeza;
	Nodo *temp;
	if(p->elemento==elemento){
		cabeza = p->siguiente;
		delete p;
	}else{
		//while(p)
	}
}
bool ListaDinamica::vacia(){
	return cabeza==NULL;
}
class Cola:public ListaDinamica{
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
class Pila:public ListaDinamica
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
	Cola lista;
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
					cout<<"El elemento se encuentra en "<<lista.buscar(elemento);
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
					elemento=lista.eliminar();
					cout<<"Eliminar ultimo elemento.El elemento eliminado es: "<<lista.eliminar();		
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
