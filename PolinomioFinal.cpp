#include<iostream>
#include<math.h>
/*
Wilmer Ricardo Pachon Lopez 20142020056
Camilo Armando Rozo Piñeros 20142020152
*/
using namespace std;

struct Nodo{
  int expo;
  float coef;
  Nodo *sig;
};

class Polinomio{
  int grado;
  Nodo *cab;
  void ordenar();
  void agregar(int,float);
  public:
	 Polinomio(int);
	 void cargar();
	 void mostrar();
	 float evaluar(float);
	 void dividir(float);
	 void derivar();
	 void integrar();
	 Polinomio operator+(Polinomio);
	 Polinomio sumaPoly(Polinomio,Polinomio );
};
Polinomio Polinomio :: sumaPoly(Polinomio a,Polinomio b )
{
	float c;
	 Nodo *p, *q;
	 p = a.cab;
	 q = b.cab;
	 
	 while (p != NULL && q != NULL)
	 { if (p->expo == q->expo)
	 { c = p->coef + q->coef;
	 if (c != 0)
	 agregar(p->expo,c);
	 p = p->sig;
	 q = q->sig;
	 }else
	 if (p->expo > q->expo)
	 { agregar(p->expo,p->coef);
	 p = p->sig;
	 }
	 else {
	 agregar(q->expo,q->coef);
	 q = q->sig;
	 }
	 }
	 while( p != NULL)
	 { agregar(p->expo,p->coef);
	 p = p->sig;
	 }
	 while( q != NULL)
	 { agregar(q->expo,q->coef);
	 q = q->sig;
	 }
	 return *this;
}
Polinomio Polinomio::operator+(Polinomio a)
{
	float c;
 	Nodo *p=cab, *q=a.cab;
 	
 	while (p != NULL && q != NULL)
 		{ 
		 if (p->expo == q->expo)
 			{ 
			 	c = p->coef + q->coef;
 				if (c != 0)
 				agregar(p->expo,c);
 				p = p->sig;
 				q = q->sig;
 				
 			}
			else
 			if (p->expo > q->expo)
 			{
			  	agregar(p->expo,p->coef);
 				p = p->sig;
 			}
 			else {
 				agregar(q->expo,q->coef);
 				q = q->sig;
 			}
 		}
 	while( p != NULL)
 		{ 
		 	agregar(p->expo,p->coef);
 			p = p->sig;
 		}
 	while( q != NULL)
 		{ 
		 	agregar(q->expo,q->coef);
 			q = q->sig;
 		}
 	return *this;
	
}

Polinomio::Polinomio(int grado){
	this->grado=grado;					 
    cab=NULL;
}

void Polinomio::cargar(){
	 int expo;
	 float coef;
	 cout<<"exponente(para terminar -1): ";
	 cin>>expo;
	 while(expo!=-1){
	     cout<<"Coeficiente: ";
	     cin>>coef;
	     agregar(expo,coef);
	     cout<<"exponente(para terminar -1): ";
	     cin>>expo;
	 }
	 ordenar();   
}
void Polinomio::agregar(int expo,float coef){
	 Nodo *p=new Nodo;
	 (*p).expo=expo;
	 (*p).coef=coef;   
	 (*p).sig=cab;
	 cab=p;
}
void Polinomio::mostrar(){
	 Nodo *p=cab;
	 while(p!=NULL){   //while(p)
	   cout<<p->coef<<"X^"<<p->expo<<"+";
	   p=p->sig;
     }
}

void Polinomio::derivar(){
	 Nodo *p=cab;
	 while(p!=NULL){   //while(p)
	   cout<<p->coef*p->expo<<"X^"<<p->expo-1<<"+";
	   p=p->sig;
     }
}


void Polinomio::integrar(){
	 Nodo *p=cab;
	 while(p!=NULL){   //while(p)
	   cout<<p->coef<<"/"<<p->expo+1<<"X^"<<p->expo+1<<"+";
	   p=p->sig;
     }
}

float Polinomio::evaluar(float num ){
	int resultado=0;
	 Nodo *p=cab;
	 while(p!=NULL){   //while(p)
	 resultado=p->coef*pow(num,p->expo)+resultado;	   
	   p=p->sig;
     }
     cout<<resultado;
     return resultado;
}



void Polinomio::ordenar(){
	  Nodo *p,*q;
	  int auxExpo;
	  float auxCoef;
   p=cab;
   while(p->sig){
   	  q=p->sig;
	  while(q){
	     if(p->expo<q->expo	){
		 	auxExpo=p->expo;
			p->expo=q->expo;
			q->expo=auxExpo;
			auxCoef=p->coef;
			p->coef=q->coef;
			q->coef=auxCoef;
			}
		q=q->sig;
		}
	p=p->sig;						 
   }
}

void Polinomio::dividir(float num ){
	 Nodo *p=cab;
	char division;
	cout<<"La division para el divisor "<<"X-"<<num<<"es : \n";	 
	 while(p!=NULL){   //while(p)
	 if(p->expo>1 ){
	 	for(int i=1;i<p->expo;i++)
		cout<<pow(p->coef,i)<<"X^"<<p->expo-i<<"+";	
	   p=p->sig;
     
}}}

char menu(){
  char opcion;
  cout<<"\n   MENU\n";
  cout<<"(C)argar\n";
  cout<<"(M)ostrar\n";
  cout<<"(D)erivar\n";
  cout<<"(I)ntegrar\n";
  cout<<"(E)valuar\n";
  cout<<"(R)egresar\n";
  cout<<"Escoja una opcion: ";
  cin>> opcion;
  return opcion;
}

char menuprincipal(){
	char opcion;
	cout<<"       MENU PRINCIPAL \n "; 
	cout<<"   ESCOJA UNA OPCION  \n"; 
	cout<<"(U)n Polinomio\n";
  	cout<<"(D)os Polinomios\n";	
	cin>> opcion;
  return opcion;
		
}

char menudos(){
	char opcion;
  cout<<"(S)umar dos polinomios\n";
  cout<<"(D)ividir\n";
  cout<<"(R)egresar\n";
  cin>> opcion;
  return opcion;			
}
	 
int main(){
	int n,elemento;
	float x,c;
	char opcion;
	cout<<"De que grado es el polinomio? ";
	cin>>n;
	
	do{
	opcion=menuprincipal();
	Polinomio polinomio(n);
	switch (opcion){	
	case 'U':
	case 'u':
	do{
	opcion=menu();

	   switch (opcion){
		  case 'c':
		  case 'C':	cout<<"Ingrese el polinomio: \n";
		            polinomio.cargar();
		            break;
          case 'm':
		  case 'M':	cout<<"El polinomio almacenado: \n";
		            polinomio.mostrar();
		            cout<<endl;
		            break;
		            
		  case 'd':
		  case 'D':	cout<<"La derivada del polinomio almacenado es: \n";
		            polinomio.derivar();
		            cout<<endl;
		            break;
		  case 'i':
		  case 'I':	cout<<"La integral del polinomio almacenado es : \n";
		            polinomio.integrar();
		            cout<<endl;
		            break;
		            
		  case 'e':
		  case 'E':	
		  			cout<<"Ingrese el numero a evaluar ";
					cin>>n;
					cout<<"Al evaluar con "<<n<<" la respuesta es :" "\n";
		            polinomio.evaluar(n);
		            cout<<endl;
		            break;
		  case 'r':
		  case 'R':	
					menuprincipal();
		            break;
		 
	   }
   		}while(opcion!='r' && opcion!='R');
		case 'd':
		case 'D':
		do{			
		opcion=menudos();
	   switch (opcion){
		  case 's':
		  case 'S':	cout<<"La SUMA es: \n";
		            polinomio.cargar();
		            break;
          case 'd':
		  case 'D':	
		  cout<<"Cargue el  polinomio dividendo: \n";
		  polinomio.cargar();
			cout<<"Cargue el  polinomio divisor de grado 1 de la forma (de la forma (X-a)): \n";

		 cout<<"Ingrese la constante (a): \n";	
		  cin>>c;
		  polinomio.dividir(c);
		            cout<<endl;
		            break;
		            
		  case 'r':
		  case 'R':	
				menuprincipal();
		            break;
	

		 
	   }
   }while(opcion!='r' && opcion!='R');
		
	}
	}while(opcion!='t' && opcion!='T');
	system("pause");
	return 1;

}
