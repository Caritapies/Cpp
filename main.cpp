#include <iostream>
#include <conio.h>

using namespace std;
struct Nodo{
    int codigo;
    string nombre;
    int camasT;
    int camasD;
    Nodo *siguiente;
};
void insertarlista(Nodo *&,int ,  string, int);
void mostrarlista(Nodo *);
void ingresarPaciente(Nodo *,int codigo);
void menu();
void porcentajes(Nodo *);
void moverPaciente(Nodo *,int codigoHospitalAntiguo, int codigoHospitalNuevo);
bool sacarPaciente(Nodo *, int codigo);
void eliminarLista(Nodo *,int codigo);

int main(){

    menu();
    getch ();
    return 0 ;
}
void menu(){
    int op,dato,camas;
    int hospitalAntiguo, hospitalNuevo;
    int codigo;
    string nomb;
    Nodo *lista = NULL;
    do{
        cout<<"   Menu  "<<endl;
        cout<<" (1). Ingresar hospital"<<endl;
        cout<<" (2). Mostrar hospitales"<<endl;
        cout<<" (3). Ingresar paciente"<<endl;
        cout<<" (4). Porcentaje de Camas Disponible en el Departamento"<<endl;
        cout<<" (5). Mover Paciente."<<endl;
        cout<<" (6). Sacar Paciente"<<endl;
        cout<<" (7). Eliminar hospital"<<endl;
        cout<<" (8). Salir."<<endl;
        cin>>op;
        switch(op){
            case 1: cout<<"Digite codigo del Hospital"<<endl;
                cin>>dato;
                cout<<" Nombre del Hospital"<<endl;
                cin>>nomb;
                cout<<" Ingrese Numero de Camas Totales"<<endl;
                cin>>camas;
                insertarlista(lista,dato, nomb,camas);

                break;
            case 2:
                mostrarlista(lista);

                break;
            case 3 :
                mostrarlista(lista);
                cout<<"Ingrese el codigo del hospital "<<endl;
                cin>>codigo;
                ingresarPaciente(lista,codigo);
                break;
            case 4 :
                porcentajes(lista);
                break;
            case 5 :
                mostrarlista(lista);
                cout<<"ingrese el codigo del hospital actual"<<endl;
                cin>>hospitalAntiguo;
                cout<<"Ingrese el codigo del nuevo hospital"<<endl;
                cin>>hospitalNuevo;
                moverPaciente(lista,hospitalAntiguo,hospitalNuevo);
            case 6:
                mostrarlista(lista);
                cout<<"Ingrese el codigo del hospital "<<endl;
                cin>>codigo;
                sacarPaciente(lista,codigo);
                break;
            case 7:
                mostrarlista(lista);
                cout<<"Ingrese el codigo del hospital que quiere borrar"<<endl;
                cin>>codigo;
                eliminarLista(lista,codigo);
        }
    }while(op!=8);
}
void insertarlista(Nodo *&lista,int n , string nomb, int camas){

    Nodo *nuevo_nodo =  new Nodo();
    nuevo_nodo->codigo = n;
    nuevo_nodo->nombre = nomb;
    nuevo_nodo->camasT=camas;
    nuevo_nodo->camasD = camas;
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
    double porcentaje;
    while(actual !=NULL){
        porcentaje=(actual->camasD * 100 )/actual->camasT;
        cout<<"Codigo:"<<actual->codigo<<". "<<actual->nombre<<" Tiene "<<actual->camasD<<"-"<<actual->camasT<<" porcentaje de cama disponible :"<<porcentaje<<"%"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        actual = actual->siguiente;
    }
}
void ingresarPaciente(Nodo *lista,int codigo){
    Nodo *aux = new Nodo();
    aux = lista;
    while(aux!= NULL && aux->camasD != 0){
        if(aux->codigo == codigo){
            cout<<"Se han ingresado al hospital "<<aux->nombre<<" el paciente"<<endl;
            aux->camasD -= 1;
            break;
        }
        aux = aux->siguiente;
    }

}
void porcentajes(Nodo *lista){
    int sumCamD = 0,sumCamT = 0,porCama;
    Nodo *aux = new Nodo();
    aux=lista;
    while(aux!= NULL){
        sumCamD += aux->camasD;
        sumCamT += aux->camasT;
        aux = aux->siguiente;
    }
    porCama = (sumCamD * 100)/sumCamT;
    cout<<" El Porcentaje de Camas Disponibles Son :"<<porCama<<"%"<<endl;
}
void moverPaciente(Nodo *lista,int codigoHospitalAntiguo, int codigoHospitalNuevo){

    if(sacarPaciente(lista,codigoHospitalAntiguo)){
        ingresarPaciente(lista,codigoHospitalNuevo);
    }else{
        cout<<"No se pudo realizar el movimiento"<<endl;
    }

}
bool sacarPaciente(Nodo *lista,int codigoHospital){
    Nodo *aux = new Nodo();
    aux = lista;
    while(aux!= NULL && aux->camasD < aux->camasT){
        if(codigoHospital == aux ->codigo){
            aux->camasD += 1;
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

void eliminarLista(Nodo *lista,int codigo) {
    if (lista != NULL) {
        Nodo *aux1;
        Nodo *aux2 = NULL;

        aux1 = lista;
        while ((aux1 != NULL) && aux1->codigo != codigo) {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if (aux1 == NULL) {
            cout << "El Codigo del Hospital no se Encontro." << endl;
        } else {
            aux2->siguiente = aux1->siguiente;
            delete aux1;
        }

    }
}