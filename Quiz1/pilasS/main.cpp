#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int);
void eliminarPila(Nodo *&);

int main(){
    Nodo *pila1 = NULL,*pila2 = NULL,*pilaAux = NULL,*pila2Aux = NULL;
    int n,nElementos1,nElementos2;
    cout<<"ingrese la cantidad de elementos de la pila 1"<<endl;
    cin>>nElementos1;

    for(int i = 0; i<nElementos1;i++){

        cout<<"Digite un numero: ";
        cin>>n;
        agregarPila(pila1,n);
    }
    cout<<"pila1 llena"<<endl;
    cout<<"ingrese la cantidad de elementos de la pila 2"<<endl;
    cin>>nElementos2;
    for(int i = 0; i<nElementos2;i++){

        cout<<"Digite un numero: ";
        cin>>n;
        agregarPila(pila2,n);
    }
    cout<<"pila 2 llena "<<endl;
    pilaAux = pila1;
    while(pila2!= NULL){
        agregarPila(pilaAux,pila2->dato);
        pila2 = pila2->siguiente;
    }
    for(int i =0; i<nElementos1;i++){
        pila2Aux = pilaAux->siguiente;
        for(int j = 0; j<nElementos2;j++){

            if(pilaAux->dato == pila2Aux->dato){
                eliminarPila(pilaAux);
            }else{
                pila2Aux = pila2Aux->siguiente;
            }

        }
        cout<<pilaAux->dato<<endl;
        pilaAux = pilaAux->siguiente;
    }

}
void eliminarPila(Nodo *&pila){
    Nodo *aux = pila;
    //cout<<aux->dato<<endl;
    pila = aux->siguiente;
    delete aux;

}
void agregarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

}