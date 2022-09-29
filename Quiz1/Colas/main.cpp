#include <iostream>
#include <stdlib.h>
using namespace std;
struct Nodo
{
    int dato;
    Nodo *siguiente;
};
void insertarNodoCola(Nodo *&frente,Nodo *&final,int dato);

int main(){
    Nodo *frente=nullptr;
    Nodo *final=nullptr;
    int n,nElementos,suma =0;
    int nBuscado;
    cout<<"ingrese la cantidad de elementos de la Cola"<<endl;
	cin>>nElementos;

	for(int i = 0; i<nElementos;i++){

		cout<<"Digite un numero: ";
		cin>>n;
		insertarNodoCola(frente,final,n);
	}

    cout<<"Digite el numero que quiere buscar : ";
    cin>>nBuscado;
    while (frente!=nullptr)
    {
        if(frente->dato == nBuscado){

            cout<<"la suma total hasta el numero "<<nBuscado<<" es "<<suma<<endl;
            break;
        }else{
            suma += frente->dato;
        }
        frente = frente->siguiente;
    }

    return 0;
}
void insertarNodoCola(Nodo *&frente,Nodo *&final,int dato){
    Nodo *nuevoNodo=new Nodo();
    nuevoNodo->dato=dato;
    nuevoNodo->siguiente=nullptr;
    if(frente==nullptr){
        frente=nuevoNodo;
        final=nuevoNodo;
    }
    else{
        final->siguiente=nuevoNodo;
        final=nuevoNodo;
    }
    cout<<"Se inserto un nodo con el dato "<<dato<<"\n";
}
