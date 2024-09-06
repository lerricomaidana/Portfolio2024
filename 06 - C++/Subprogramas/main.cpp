#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;


void saludar(string nombre)
{
    cout << "Hola " << nombre << ", bienvenido a este programa." << endl;
    return;
}

char menu()
{
    char opcion;
    do
    {
        cout << endl << "====================" << endl;
        cout << "Elija una opción: " << endl;
        cout << "a - Indicar si un número es par." << endl;
        cout << "b - Sumar dos números." << endl;
        cout << "Esc - Salir" << endl<< endl;
        opcion = getch();
    }
    while (opcion!='a' && opcion!='b' && opcion!=27);
    return opcion;
}

bool esPar(int x)
{
    if (!(x%2))
        return true;
    return false;
}

int sumar(int x, int y)

{
    int r;
    r = x+y;
    return r;
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    string s;
    int n1, n2;
    char opcion_elegida;
    cout << "Ingrese su nombre: " << endl;
    cin >> s;
    saludar(s);
    do
    {
        opcion_elegida = menu();
        switch( opcion_elegida)
        {
            case 'a':
                cout << "Ingrese un número:" << endl;
                cin >> n1;
                if (esPar(n1))
                    cout << "Es par." << endl;
                else
                    cout << "No es par." << endl;
            break;
            case 'b':
                cout << "Ingrese los números a sumar:" << endl;
                cin >> n1 >> n2;
                cout << n1 << " + " << n2 << "= " << sumar(n1, n2) << endl;
            break;

        }
    }
    while (opcion_elegida!=27);
    cout << "Adiós " << s << endl;
    return 0;
}
