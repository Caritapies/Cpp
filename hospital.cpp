#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
struct Nodo{
	int codigo;
	string nombre;
    int camasT;
	int camasD = camasT;
	Nodo *siguiente;
};
void insertarlista(Nodo *&,int ,  string, int);
void mostrarlista(Nodo *);
void ingresarPaciente(Nodo *,int numeroDepacientes);
void menu();

int main(){

	menu();
	getch ();
	return 0 ;
}
void menu(){
	int op,dato,camas,numPacientes;
	string nomb;
	Nodo *lista = NULL;
	do{
		cout<<"   Menu  "<<endl;
		cout<<" (1). Ingresar hospital"<<endl;
		cout<<" (2). Ingresar pacientes"<<endl;
		cout<<" (3). Salir."<<endl;
		cin>>op;
		switch(op){
			case 1: cout<<"Digite codigo del Hospital"<<endl;
					cin>>dato;
                    cout<<" Nombre del Hospital"<<endl;
                    cin>>nomb;
                    cout<<" Ingrese Numero de Camas Totales"<<endl;
                    cin>>camas;
					insertarlista(lista,dato, nomb,camas);
					system  ("pause");
					break;
			case 2:
                mostrarlista(lista);

			    system ("pause");
			    break;
		}
	system ("cls");
	}while(op!=3);
}
void insertarlista(Nodo *&lista,int n , string nomb, int camas){

	Nodo *nuevo_nodo =  new Nodo();
	nuevo_nodo->codigo = n;
	nuevo_nodo->nombre = nomb;
	nuevo_nodo->camasT=camas;
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL)&& (aux1->codigo<n)){
		aux2=aux1;
		aux1=aux1->siguiente;
		
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}
	else{
		aux2->siguiente= nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
	
}
void mostrarlista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual !=NULL){

		cout<<"Código:"<<actual->codigo<<". "<<actual->nombre<<" Tiene "<<actual->camasD<<"-"<<actual->camasT<<endl;
		cout<<"-----------------------------------------------------------"<<endl<<endl;
		actual = actual->siguiente;
	}
}
