#include <iostream>
#include <locale.h>
using namespace std;

struct NodoListaSE
{
    int info;
    NodoListaSE *sgte=NULL;
};


void MostrarLista(NodoListaSE *lista)
{
    while (lista)
    {
        cout << "En la dirección " << lista << " hay un nodo con info " << lista->info << endl;
        lista = lista->sgte;
    }
    return;
}

void InsertarNuevoNodoAlPrincipio(NodoListaSE *&lista, int info)
{
    NodoListaSE *aux = lista;
    lista = new NodoListaSE();
    lista->sgte = aux;
    lista->info = info;
    return;
}

void InsertarNuevoNodoAlFinal(NodoListaSE *&lista, int info)
{
    NodoListaSE *aux =lista;
    if (!lista) //if (lista==NULL) caso lista vacía
        InsertarNuevoNodoAlPrincipio(lista, info);
    else
    {
        while (aux->sgte) //while (aux->sgte != NULL)
            aux = aux->sgte;
        aux->sgte = new NodoListaSE();
        aux = aux->sgte;
        aux->info = info;
        aux->sgte = NULL;
    }
    return;
}


void InsertarNuevoNodoEntreDosNodos(NodoListaSE *&sgteAEste, int info)
{
    if (sgteAEste)//Caso lista no vacía
    {
        NodoListaSE *aux = sgteAEste->sgte;
        sgteAEste->sgte = new NodoListaSE();
        sgteAEste->sgte->sgte= aux;
        sgteAEste->sgte->info = info;
    }
    else
        InsertarNuevoNodoAlPrincipio(sgteAEste,info);
}


NodoListaSE *buscarNodo(NodoListaSE *lista, int buscado)
{
    while (lista && lista->info!=buscado)
        lista = lista->sgte;
    return lista;
}

void borrarPrimerNodo(NodoListaSE *&lista)
{
    NodoListaSE *aux;
    if (lista)
    {
        aux = lista;
        lista = lista->sgte;
        delete aux;
    }
    return;
}

void borrarUltimoNodo(NodoListaSE *&lista)
{
    NodoListaSE *anteultimo=NULL, *ultimo=lista;
    if (lista)
    {
        if (lista->sgte == NULL) 
            borrarPrimerNodo(lista);
        else
        {
            while (ultimo->sgte)
            {
                anteultimo = ultimo;
                ultimo = ultimo->sgte;
            }

            anteultimo->sgte = NULL;
            delete ultimo;
        }
    }
    return;
}


void borrarEntreDosNodos(NodoListaSE *&lista, NodoListaSE *aborrar)
{
    NodoListaSE *anterior = NULL;
    if (lista)
    {
        if (aborrar == lista)
            borrarPrimerNodo(lista);
        else
        {
            anterior = lista;
            while (anterior->sgte!=aborrar)
                anterior = anterior->sgte;
            anterior->sgte = aborrar->sgte;
            delete aborrar;
        }
    }
    return;
}

void borrarLista(NodoListaSE *&lista)
{
    while (lista)
        borrarPrimerNodo(lista);
    return;
}

int main()
{
    setlocale(LC_ALL, "spanish");
    NodoListaSE *lista=NULL;
    NodoListaSE *aux;
    InsertarNuevoNodoEntreDosNodos(lista, 7);
    InsertarNuevoNodoAlFinal(lista,1011);
    InsertarNuevoNodoAlPrincipio(lista, 45);
    InsertarNuevoNodoAlPrincipio(lista, 16);
    InsertarNuevoNodoAlPrincipio(lista, 38);
    InsertarNuevoNodoAlFinal(lista, 46);
    aux = buscarNodo(lista, 16);
    InsertarNuevoNodoEntreDosNodos(aux,17);
    borrarPrimerNodo(lista);
    borrarUltimoNodo(lista);
    borrarEntreDosNodos(lista, buscarNodo(lista,7));
    /* ==== RECORREMOS LA LISTA ==== */
    MostrarLista(lista);
    borrarLista(lista);
    MostrarLista(lista);
    return 0;
}
