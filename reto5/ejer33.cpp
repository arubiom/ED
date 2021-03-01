/**
 * @file ejer33.cpp
 * @author Alejandro Rubio Martinez
 * @brief Implementar una función para determinar si un árbol binario tiene más
 *  de un camino desdeuna hoja a la raíz cuya suma de etiquetas sea igual a k.
 */

#include "./bintree/bintree.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Comprueba si hay MAS de UN camino de suma k entre la hoja y la raiz
 * 
 * @param arb El arbol que vamos a comprobar
 * @param k El valor de la suma que buscamos
 * @return true Si la suma es la obtenida
 * @return false Si la suma no es la obtenida
 */
bool suma_k(bintree<int> arb, int k);
/**
 * @brief SObrecarga la funcion anterior para trabajar con nodos
 * 
 * @param arb La raiz del arbol que queremos comprobar
 * @param k La suma que queremos buscar
 * @return true Si hay mas de un camino
 * @return false Si hay uno o nigun camino
 */
bool _suma_k(bintree<int>::node arb, int k);
/**
 * @brief Suma desde una hoja hasta la raiz de un arbol
 * 
 * @param n La hoja
 * @param k La suma que queremos
 * @return int 1 si suma k 0 si no
 */
int sum(bintree<int>::node n, int k);

int main() {
    int k = 14;
    bintree<int> ab(7);

    ab.insert_left(ab.root(), 1);
    ab.insert_right(ab.root(), 4);
    ab.insert_left(ab.root().left(), 6);
    ab.insert_right(ab.root().left(), 8);
    ab.insert_right(ab.root().left().right(), 4);
    ab.insert_left(ab.root().right(), 3);

    string s = suma_k(ab, k)
                   ? "La suma de ramas se repite mas de una vez para el valor k."
                   : "El numero de ramas que suman el valor k es de una o ninguna.";
    cout << s << endl;
    return 0;
}

bool suma_k(bintree<int> arb, int k) {
    if (_suma_k(arb.root(),k > 1))
        return true;
    return false;
}

bool _suma_k(bintree<int>::node arb, int k) {
    int check = 0;

    if (!arb.left().null() && !arb.right().null()) {
        check += _suma_k(arb.left(), k) + _suma_k(arb.right(), k);
    }
    else if (!arb.left().null()) {
        check += _suma_k(arb.left(),k);
    }
    else if (!arb.right().null()) {
        check += _suma_k(arb.right(), k);
    }

    check += sum(arb, k);

    return check;
}

int sum(bintree<int>::node n, int k) {
    int suma = 0;
    while(!n.parent().null()) {
        suma += *n;
        n = n.parent();
    }

    if (suma == k)
        return 1;
    return 0;
}