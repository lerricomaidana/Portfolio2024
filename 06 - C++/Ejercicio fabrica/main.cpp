/*
Se realiza una inspección en una fábrica de pinturas, y se detectaron 20
infracciones. De cada infracción se tomó nota de los siguientes datos:
- Tipo de Infracción (1, 2, 3, ó 4)
- Motivo de la infracción
- Valor de la multa
- Gravedad de la infracción (‘L’,‘M’, ‘G’)
Se pide informar al final del proceso:
 Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
 La leyenda “Clausurar fábrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean
mayor a 3.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int i, tipo;
    float valor, sumal, sumam, sumag;
    char gravedad;
    int clausurafabrica = 0;
    char motivo[400];
    sumal = 0; sumam = 0; sumag = 0;
    for(i=1;i<=5;i++)
    {
        cout << "***** Datos de la infraccion nro " << i << " *****" << endl;
        cout << "Tipo de infraccion 1,2,3 o 4: " << endl;
        cin >> tipo;
        while(tipo < 1 || tipo > 4)
        {
            cout << "Vuelva a ingresar un tipo valido (1,2,3 o 4)" << endl;
            cin >> tipo;
        }
        cout << "Motivo de infraccion:" << endl;
        getchar();
        fgets(motivo, 400, stdin);
        cout << "Valor:" << endl;
        cin >> valor;
        cout << "Gravedad (L,M o G):" << endl;
        cin >> gravedad;
        while(gravedad != 'L' && gravedad != 'M' && gravedad !='G')
        {
            cout << "Vuelva a ingresar una gravedad valida (L,M o G):" << endl;
            cin >> gravedad;
        }
        switch(gravedad)
        {
            case 'L':
                sumal+= valor;
                break;
            case 'M':
                sumam+= valor;
                break;
            case 'G':
                sumag+= valor;
                break;
        }
        if ((tipo==3 || tipo==4) && (gravedad='G'))
            clausurafabrica++;

    }
    cout << "Infracciones G a pagar $" << sumag << endl;
    cout << "Infracciones M a pagar $" << sumam << endl;
    cout << "Infracciones L a pagar $" << sumal << endl;
    if (clausurafabrica > 3 )
        cout << "CLAUSURA FABRICA"  << endl;
    return 0;
}
