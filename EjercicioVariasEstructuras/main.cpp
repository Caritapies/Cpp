#include <stdio.h>

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *pila = NULL;
Nodo *frente = NULL;
Nodo *final = NULL;
Nodo *lista = NULL;

//Prototipos de funciones

void llenarPila();
void llenarCola();
int introducirDatos();
void ListaEnlazadaOrdenada();
void visualizarDatos();

int main()
{
    printf("Ejercicio \n\n");
    printf("AVISO: Para finalizar el llenado, introduzca un Cero (0)\n\n");

    printf("Datos para la pila\n");
    llenarPila();
    printf("\n\nDatos para la cola\n");
    llenarCola();
    ListaEnlazadaOrdenada();
    printf("\n\nLista enlazada ordenada\n");
    visualizarDatos();

    return 0;
}

void llenarPila()
{
    Nodo *nuevo;
    int numero = introducirDatos();

    while(numero!=0)
    {
        nuevo = new Nodo();
        nuevo->dato=numero;
        nuevo->siguiente=pila;
        pila=nuevo;
        numero=introducirDatos();
    }
}

void llenarCola()
{
    Nodo *nuevo;
    int numero=introducirDatos();

    while(numero!=0)
    {
        nuevo = new Nodo;
        nuevo->dato=numero;

        if(final==NULL)
        {
            nuevo->siguiente=NULL;
            frente=nuevo;
            final=nuevo;
        }
        else
        {
            nuevo->siguiente=NULL;
            final->siguiente=nuevo;
            final=nuevo;
        }
        numero=introducirDatos();
    }
}

int introducirDatos()
{
    int x;
    printf("Numero: ");
    scanf("%d",&x);
    return x;
}

void ListaEnlazadaOrdenada()
{
    Nodo *cola,*pivote,*auxiliar,*anterior;
    int valor;

    //Pila en la lista enlazada
    while(pila!=NULL)
    {
        valor=pila->dato;
        pivote = new Nodo();
        pivote->dato=valor;
        if(lista==NULL)
        {
            pivote->siguiente=lista;
            lista=pivote;
        }
        else
        {
            auxiliar=lista;
            if(pivote->dato < auxiliar->dato)
            {
                pivote->siguiente=auxiliar;
                lista=pivote;
            }
            else
            {
                while(auxiliar!=NULL && pivote->dato > auxiliar->dato)
                {
                    anterior=auxiliar;
                    auxiliar=auxiliar->siguiente;
                }
                if(auxiliar!=NULL)
                {
                    anterior->siguiente=pivote;
                    pivote->siguiente=auxiliar;
                }
                else
                {
                    anterior->siguiente=pivote;
                    pivote->siguiente=NULL;
                }
            }
        }
        pila=pila->siguiente;
    }

    //Cola en la lista enlazada
    cola=frente;
    while(cola!=NULL)
    {
        valor=cola->dato;
        pivote = new Nodo();
        pivote->dato=valor;
        if(lista==NULL)
        {
            pivote->siguiente=lista;
            lista=pivote;
        }
        else
        {
            auxiliar=lista;
            if(pivote->dato < auxiliar->dato)
            {
                pivote->siguiente=auxiliar;
                lista=pivote;
            }
            else
            {
                while(auxiliar!=NULL && pivote->dato > auxiliar->dato)
                {
                    anterior=auxiliar;
                    auxiliar=auxiliar->siguiente;
                }
                if(auxiliar!=NULL)
                {
                    anterior->siguiente=pivote;
                    pivote->siguiente=auxiliar;
                }
                else
                {
                    anterior->siguiente=pivote;
                    pivote->siguiente=NULL;
                }
            }
        }
        cola=cola->siguiente;
    }
}

void visualizarDatos()
{
    while(lista!=NULL)
    {
        printf(" %d",lista->dato);
        lista=lista->siguiente;
    }
}