/**
 * @file ejer38.cpp
 * @author Alejandro Rubio Martinez
 * @brief Un árbol de selección es un árbol binario en el que cada nodo tiene la etiqueta
 * del menor de sus 2 hijos. Implementar una función:
 * bool selección (bintree<int> & A);
 * que devuelva true si A es árbol de selección y false en caso contrario
 * 
 */

#include <iostream>
#include <string>
#include "./bintree/bintree.h"
using namespace std;
/**
 * @brief Comprueba si un arbol es de seleccion
 * 
 * @param A El arbol que queremos comprobar
 * @return true Si es de seleccion
 * @return false Si no es de seleccion
 */
bool seleccion (const bintree<int> & A);
/**
 * @brief Sobrecarga de la funcion anterior para trabajar con nodos
 * 
 * @param n El nodo que qeuremos comprobar
 * @return true Si es de seleccion
 * @return false Si no es de seleccion
 */
bool _seleccion (const bintree<int>::node & n);

int main() {
    bintree<int> ab(1);

    ab.insert_left(ab.root(), 3);
    ab.insert_right(ab.root(), 1);
    ab.insert_left(ab.root().left(), 4);
    ab.insert_right(ab.root().left(), 3);
    ab.insert_right(ab.root().left().right(), 3);
    ab.insert_left(ab.root().right(), 1);

    string s = seleccion(ab)
                   ? "El arbol introducido es un arbol de seleccion."
                   : "El arbol introducido no es un arbol de seleccion.";
    cout << s << endl;
    return 0;
}

bool seleccion (const bintree<int> & A) {
    return _seleccion(A.root());
}

bool _seleccion (const bintree<int>::node & n) {
    if (n.right().null() && n.left().null())
        return true;
    else if ( n.right().null() && !n.left().null()) {
        if (*n != *n.left())
            return false;
        return _seleccion(n.left());
    }
    else if ( !n.right().null() && n.left().null()) {
        if (*n != *n.right())
            return false;
        return _seleccion(n.right());
    }

    if ((*n == *n.right() && *n < *n.left()) || (*n == *n.left() && *n < *n.right()))
        return _seleccion(n.right()) && _seleccion(n.left());

    return false;
}