#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodoCentral{
	int dato,x,y;
	nodoCentral* arriba;
	nodoCentral* abajo;
	nodoCentral* izquierda;
	nodoCentral* derecha;
	
	nodoCentral(int dato, int x, int y){
		this->dato=dato;
		this->x=x;
		this->y=y;
		arriba=NULL;
		abajo=NULL;
		izquierda=NULL;
		derecha=NULL;
	}
};


struct listaVertical{
	nodoCentral* primero;
	nodoCentral* ultimo;
	
	listaVertical(){
		primero=NULL;
		ultimo=NULL;
	}
	
	void insertar(nodoCentral* inserta){
		if(vacio()){
			primero=ultimo=inserta;
			
		}else{
			if(inserta->y < primero->y){
				insertarFrente(inserta);
				
			}else if(inserta->y > ultimo->y){
				insertarFinal(inserta);
				
			}else{
				insertarMedio(inserta);
			}
		}

	}

	bool vacio(){
		if(primero==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	void insertarFrente(nodoCentral* inserta){
		primero->arriba = inserta;
		inserta->abajo = primero;
		primero = primero->arriba;
	}
	
	void insertarFinal(nodoCentral* inserta){
		ultimo->abajo = inserta;
		inserta->arriba = ultimo;
		ultimo = ultimo->abajo;

		
	}
	
	void insertarMedio(nodoCentral* inserta){
		nodoCentral* temporal1;
		nodoCentral* temporal2;
		temporal1 = primero;
		while(temporal1->y < inserta->y){
			temporal1 = temporal1->abajo;
			}
			temporal2 = temporal1->arriba;
			
			temporal2->abajo = inserta;
			temporal1->arriba = inserta;
			inserta->abajo = temporal1;
			inserta->arriba = temporal2;
	}
	
	void recorrer(){
		if(!vacio()){
				nodoCentral* temporal = primero;
					while(temporal!=NULL){
						cout<<"y="<<temporal->y<<endl;
						temporal = temporal->abajo;
					}
		}
		else{
			cout<<"Lista Vertical esta vacia";
		}
	}
};




//lista horizontal
struct listaHorizontal{

	nodoCentral* primero;
	nodoCentral* ultimo;

	listaHorizontal(){
		primero=NULL;
		ultimo=NULL;
	}

	void insertar(nodoCentral* inserta){
		if(vacio()){
			primero=ultimo=inserta;

		}
		else{
			if(inserta->x < primero->x){
				insertarFrente(inserta);
			}
			else if(inserta->x > ultimo->x){
				insertarFinal(inserta);
			}
			else{
				insertarMedio(inserta);
			}
		}

	}

	bool vacio(){
		if(primero==NULL){
			return true;
		}
		else{
			return false;
		}
	}

	void insertarFrente(nodoCentral* inserta){
		primero->izquierda = inserta;
		inserta->derecha = primero;
		primero = primero->izquierda;
	}

	void insertarFinal(nodoCentral* inserta){
		ultimo->derecha = inserta;
		inserta->izquierda = ultimo;
		ultimo = ultimo->derecha;
	}

	void insertarMedio(nodoCentral* inserta){
		nodoCentral* temporal1;
		nodoCentral* temporal2;
		temporal1 = primero;
		while(temporal1->x < inserta->x){
			temporal1 = temporal1->derecha;
			}
			temporal2 = temporal1->izquierda;

			temporal2->derecha = inserta;
			temporal1->izquierda = inserta;
			inserta->derecha = temporal1;
			inserta->izquierda = temporal2;
	}

	void recorrer(){
		if(!vacio()){
				nodoCentral* temporal = primero;
				while(temporal!=NULL){
					cout<<"x="<<temporal->x<<endl;
					temporal = temporal->derecha;
				}
		}
		else{
			cout<<"Lista horizontal esta vacia";
		}
	}
	
	
};


//nodos de cabecera
struct nodoCabecera{
	int x;
	nodoCabecera* siguiente;
	nodoCabecera* anterior;
	listaVertical* columna;
	
	nodoCabecera(int x){
		this->x=x;
		columna = new listaVertical();
		siguiente = NULL;
		anterior = NULL;
	}
	
};



struct cabeceras{
	nodoCabecera* primero;
	nodoCabecera* ultimo;

	cabeceras(){
		primero=NULL;
		ultimo=NULL;
	}

	void insertar(nodoCabecera* inserta){
		if(vacio()){
			primero=ultimo=inserta;

		}
		else{
			if(inserta->x < primero->x){
				insertarFrente(inserta);
			}
			else if(inserta->x > ultimo->x){
				insertarFinal(inserta);
			}
			else{
				insertarMedio(inserta);
			}
		}

	}

	bool vacio(){
		if(primero==NULL){
			return true;
		}
		else{
			return false;
		}
	}

	void insertarFrente(nodoCabecera* inserta){
		primero->anterior = inserta;
		inserta->siguiente = primero;
		primero = primero->anterior;
	}

	void insertarFinal(nodoCabecera* inserta){
		ultimo->siguiente = inserta;
		inserta->anterior = ultimo;
		ultimo = ultimo->siguiente;
	}

	void insertarMedio(nodoCabecera* inserta){
		nodoCabecera* temporal1;
		nodoCabecera* temporal2;
		temporal1 = primero;
		while(temporal1->x < inserta->x){
			temporal1 = temporal1->siguiente;
			}
			temporal2 = temporal1->anterior;

			temporal2->siguiente = inserta;
			temporal1->anterior = inserta;
			inserta->siguiente = temporal1;
			inserta->anterior = temporal2;
	}


	void recorrer(){
		if(!vacio()){
				nodoCabecera* temporal = primero;
				while(temporal!=NULL){
					cout<<"x="<<temporal->x<<endl;
					temporal = temporal->siguiente;
				}
		}
		else{
			cout<<"Lista horizontal esta vacia";
		}
	}
	
	
	bool existe(int x){
		if(vacio()){
			return false;
		}
		else{
			nodoCabecera* temporal;
			temporal = primero;
			
			while(temporal!=NULL){
				if(temporal->x == x){
					cout<<"Cabecera numero "<<temporal->x<<" ya existe"<<endl;
					return true;
				}
				else if(temporal->siguiente == NULL){
					cout<<"no existe la cabecera: "<<temporal->x<<endl;
					return false;
				}
				
			temporal = temporal->siguiente;
			}
		}
	}

	nodoCabecera* busqueda(int x){

		if (existe(x)){
			nodoCabecera* temporal;
			temporal = primero;
			while(temporal->x != x){
				temporal = temporal->siguiente;
			}
			cout<<"retornando"<<endl;
  		return temporal;
		}
		else{
			cout<<"no existe"<<endl;
			return(new nodoCabecera(-1));
		}
	}
};




//nodos laterales
struct nodoLaterales{
	int y;
	nodoLaterales* siguiente;
	nodoLaterales* anterior;
	listaHorizontal* Filas;

	nodoLaterales(int y){
		this->y=y;
		Filas = new listaHorizontal();
		siguiente = NULL;
		anterior = NULL;
	}
};

//lista laterales
struct laterales{
	
	nodoLaterales* primero;
	nodoLaterales* ultimo;

	laterales(){
		primero=NULL;
		ultimo=NULL;
	}

	void insertar(nodoLaterales* inserta){
		if(vacio()){
			primero=ultimo=inserta;

		}
		else{
			if(inserta->y < primero->y){
				insertarFrente(inserta);
			}
			else if(inserta->y > ultimo->y){
				insertarFinal(inserta);
			}
			else{
				insertarMedio(inserta);
			}
		}

	}

	bool vacio(){
		if(primero==NULL){
			return true;
		}
		else{
			return false;
		}
	}

	void insertarFrente(nodoLaterales * inserta){
		primero->anterior = inserta;
		inserta->siguiente = primero;
		primero = primero->anterior;
	}

	void insertarFinal(nodoLaterales* inserta){
		ultimo->siguiente = inserta;
		inserta->anterior = ultimo;
		ultimo = ultimo->siguiente;
	}

	void insertarMedio(nodoLaterales* inserta){
		nodoLaterales* temporal1;
		nodoLaterales* temporal2;
		temporal1 = primero;
		while(temporal1->y < inserta->y){
			temporal1 = temporal1->siguiente;
			}
			temporal2 = temporal1->anterior;

			temporal2->siguiente = inserta;
			temporal1->anterior = inserta;
			inserta->siguiente = temporal1;
			inserta->anterior = temporal2;
	}
	
	
	void recorrer(){
		if(!vacio()){
				nodoLaterales* temporal = primero;
				while(temporal!=NULL){
					cout<<"y="<<temporal->y<<endl;
					temporal = temporal->siguiente;
				}
		}
		else{
			cout<<"Lista horizontal esta vacia";
		}
	}
	
	bool existe(int y){
		if(vacio()){
			cout<<"no existe porque la lista esta vacia"<<endl;
			return false;
		}
		else{
			nodoLaterales* temporal;
			temporal = primero;

			while(temporal!=NULL){
				if(temporal->y == y){
					cout<<"el numero lateral si existe: "<<temporal->y<<endl;
					return true;
				}
				else if(temporal->siguiente == NULL){
					cout<<"no se encontro el numero lateral "<<temporal->y<<endl;
					return false;
				}

			temporal = temporal->siguiente;
			}
		}
	}

	nodoLaterales* busqueda(int y){

		if (existe(y)){
			nodoLaterales* temporal;
			temporal = primero;
			while(temporal->y != y){
				temporal = temporal->siguiente;
			}
			cout<<"retornando lateral "<<endl;
  		return temporal;
		}
		else{
			cout<<"no existe"<<endl;
			return(new nodoLaterales(-1));
		}
	}
	
};


typedef struct MatrizOrtogonal{
	cabeceras* c;
	laterales* l;
	
	MatrizOrtogonal(){
		c = new cabeceras();
		l = new laterales();
		
	}
	
	void insertar(int x, int y, int inserta){
		
		nodoCentral* insercion;
		insercion = new nodoCentral(inserta,x,y);
		if(c->existe(x) == false){
			c->insertar(new nodoCabecera(x));
		}
		if(l->existe(y) == false){
			l->insertar(new nodoLaterales(y));
		}
		nodoCabecera* cabeceratemp;
		nodoLaterales* lateraltemp;
		cabeceratemp = c->busqueda(x);
		lateraltemp = l->busqueda(y);
		cabeceratemp->columna->insertar(insercion);
		lateraltemp->Filas->insertar(insercion);
		cout<<"se inserto el valor: "<<inserta<<" en la columna: "<<x<<" fila: "<<y<<endl;

	}
	
	
	void llenar(int x, int y){
		
		int o=0;
		for(int j=0;j<x;j++){
			
			for(int i=0;i<y;i++){
				
				insertar(i,j,o);
				o++;

			}
		}
	}
	
}MatrizOrtogonal;



