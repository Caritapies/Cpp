#include <iostream>
#include <stdlib.h>
using namespace std;


struct Nodo
{
    int dato;
    Nodo *siguiente;
};
void insertarCola(Nodo *&frente,Nodo *&final,int dato);

int main(){
    Nodo *frente=nullptr;
    Nodo *final=nullptr;

    int n,numeroElementos,suma =0;
    int x;
    cout<<"ingrese la cantidad de elementos que tendra la cola"<<endl;
    cin>>numeroElementos;

    for(int i = 0; i<numeroElementos;i++){

        cout<<"Digite un numero: ";
        cin>>n;
        insertarCola(frente,final,n);
    }

    cout<<"Digite el numero que quiere buscar : ";
    cin>>x;
    while (frente!=nullptr)
    {
        if(frente->dato == x){

            cout<<"la suma total hasta el numero "<<x<<" es "<<suma<<endl;
            break;

        }else{
            suma += frente->dato;
        }
        frente = frente->siguiente;
    }

    return 0;
}
void insertarCola(Nodo *&frente,Nodo *&final,int dato){
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
}

