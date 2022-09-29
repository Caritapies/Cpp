#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int);
void mostrarPila(Nodo *pila);

int main(){
    Nodo *pila = NULL;
    int opcion,n;

    while(true) {
        cout << "Ingresa la opcion que quieres hacer: \n"
                "1. Insertar elemento a la pila \n"
                "2. Mostrar elementos de la pila \n"
                "3. salir";


        cin>>opcion;
        if(opcion == 1){
            cout<<"ingresa el elemento de la pila";
            cin>>n;
            agregarPila(pila,n);
        }
        if(opcion == 2){
            mostrarPila(pila);
        }
        else if(opcion == 3){
            break;
        }
    }

	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
    cout<<"\nElemento "<<n<<" agregado a pila correctamente"<<endl;
}
void mostrarPila(Nodo *pila){
    cout<<pila->dato<<endl;
}

