#include <iostream>
#include <conio.h>

using namespace std;


struct NodoListaSEItem
{
    char info;
    NodoListaSEItem *sgte = NULL;
};


void push(NodoListaSEItem *&l, char i)
{
    NodoListaSEItem *paux = new NodoListaSEItem();
    paux->info = i;
    paux->sgte = l;
    l = paux;
    return;
}

char pop(NodoListaSEItem *&l,bool &pudoquitar)
{
    char dato;
    if (!l)
        pudoquitar = false;
    else
    {
        pudoquitar = true;
        NodoListaSEItem *paux = l;
        l = l->sgte;
        dato= paux->info;
        delete paux;
    }
    return dato;
}


void queue(NodoListaSEItem *&l, char i)
{
    NodoListaSEItem *paux = new NodoListaSEItem();
    paux->info = i;
    paux->sgte = l;
    l = paux;
    return;
}



char dequeue(NodoListaSEItem *&l,bool &pudoquitar)
{
    char dato;
    if (!l)
        pudoquitar = false;
    else
    {
        pudoquitar = true;
        NodoListaSEItem *pauxant = NULL;
        NodoListaSEItem *paux = l;
        while (paux->sgte)
        {
            pauxant = paux;
            paux = paux->sgte;
        }
        dato = paux->info;
        delete paux;
        if (pauxant)
            pauxant->sgte = NULL;
        else 
            l = NULL;
    }
    return dato;
}


int main()
{
    NodoListaSEItem *pila = NULL;
    NodoListaSEItem *cola = NULL;
    char c;
    char charpila, charcola;
    bool pudoquitar;
    c = getche();
    while (c != 13)
    {
        push(pila, c);
        queue(cola, c);
        c = getche();
    }
    bool escapicua = true;
    while(pila && cola && escapicua)
    {
        charpila = pop(pila,pudoquitar);
        charcola = dequeue(cola, pudoquitar);
        cout << "Compara el char de la pila: '" << charpila
            << "' con el char de la cola '" << charcola << "'." << endl;
        if (charcola != charpila)
            escapicua = false;
    }
    if (escapicua)
        cout << "El n mero es capic a." << endl;
    else
        cout << "El n mero no es capic a." << endl;
    //Lipiar toda la pila y la cola
    while (pila)
        pop(pila, pudoquitar);
    while (cola)
        dequeue(cola, pudoquitar);
    return 0;
}
