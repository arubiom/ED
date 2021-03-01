#include <iostream>
#include "../inc/Pila_Max.h"
#include "../inc/Cola_Max.h"
using namespace std;

int main() {
    Pila_max<int> prueba;
    Cola_Max<int> prueba2;
    int primero, segundo;

    cout << "------------------------------------------------------" << endl;
    cout << "PROBANDO LA PILA CON LA OPCION DE COMPILACION INDICADA" << endl;
    cout << "------------------------------------------------------" << endl;
    primero = 4;
    prueba.push(primero);
    cout << prueba.top() << " " << prueba.max() << " == 4 4" << endl;

    primero = 3;
    prueba.push(primero);
    cout << prueba.top()<< " " << prueba.max() << " == 3 4" << endl;

    prueba.pop();

    cout << prueba.top() << " " << prueba.max() << " == 4 4" << endl;

    primero = 6;
    prueba.push(primero);
    cout << prueba.top() << " " << prueba.max() << " == 6 6" << endl;

    prueba.pop();

    cout << prueba.top() << " " << prueba.max() << " == 4 4" << endl;

    prueba.pop();

    if (prueba.empty())
        cout << "Esta vacia";
    else
        cout << "No estavacia";

    cout << " == Esta vacia" << endl;

    cout << "----------------" << endl;
    cout << "PROBANDO LA COLA" << endl;
    cout << "----------------" << endl;

    segundo = 4;
    prueba2.push(segundo);
    cout << prueba2.front() << " " << prueba2.max() << " " << prueba2.back() << " == 4 4 4" << endl;

    segundo = 3;
    prueba2.push(segundo);
    segundo = prueba2.max();
    cout << prueba2.front() << " " << prueba2.max() << " " << prueba2.back() << " == 3 4 4" << endl;

    prueba2.pop();

    cout << prueba2.front() << " " << prueba2.max() << " " << prueba2.back() << " == 4 4 4" << endl;

    segundo = 6;
    prueba2.push(segundo);
    cout << prueba2.front() << " " << prueba2.max() << " " << prueba2.back() << " == 6 6 4" << endl;

    prueba2.pop();

    cout << prueba2.front() << " " << prueba2.max() << " " << prueba2.back() << " == 4 4 4" << endl;

    prueba2.pop();

    if (prueba2.empty())
        cout << "Esta vacia";
    else
        cout << "No estavacia";

    cout << " == Esta vacia" << endl;
}