/**
 * @file ejer32.cpp
 * @author Alejandro Rubio Martinez
 * @brief Implementa una función booleana que devuelva true si la estructura de ramificación
 *  de unárbol binario de enteros ab2 coincide con la de algún subárbol de otro árbol binario
 *  ab1(deben coincidir también los valores de las etiquetas)
 * 
 */

#include "./bintree/bintree.h"
#include <iostream>
using namespace std;

/**
 * @brief Check if a tree is a subtree from another
 * 
 * @param ab1 The subtree
 * @param ab2 The big tree
 * @return true If it is a subtree
 * @return false If it is not a subtree
 */
bool es_subarbol(const bintree<int>::node & ab1, const bintree<int>::node & ab2);

int main() {
    bintree<int> T1(12);
    T1.insert_left(T1.root(), 5);
    T1.insert_right(T1.root(), 7);
    T1.insert_left(T1.root().right(), 3);
    T1.insert_right(T1.root().right(), 4);

    bintree<int> T2(12);
    T2.insert_left(T2.root(), 5);

    cout << "Comprobemos si el arbol {12,5,NULL} esta contenido en {12,5,4,NULL,NULL,3,4}" << endl;

    if (es_subarbol(T1.root(), T2.root()))
        cout << "El segundo esta contenido en el primero" << endl;
    else
        cout << "El segundo no esta contenido en el primero" << endl;

    bintree<int> T3(12);
    T3.insert_right(T3.root(),7);
    T3.insert_right(T3.root().right(),3);

    cout << "Comprobemos ahora si {12,NULL,7,NULL,NULL,NULL,3} esta contenido en {12,5,4,NULL,NULL,3,4}" << endl;

    if (es_subarbol(T1.root(),T3.root()))
        cout << "El segundo esta contenido en el primero" << endl;
    else
        cout << "El segundo no esta contenido en el primero" << endl;
}

bool es_subarbol(const bintree<int>::node & ab1, const bintree<int>::node & ab2) {
    if (ab1.left().null() && ab1.right().null() && ab2.left().null() && ab2.right().null()) {
        if (*ab1 == *ab2)
            return true;
        else
            return false;
    }

    if ((ab1.left().null() && !ab2.left().null()) || (ab1.right().null() && !ab2.right().null()))
        return false;

    if (*ab1 == *ab2) {
        if (ab2.right().null())
            return es_subarbol(ab1.left(), ab2.left());

        if (ab2.left().null())
            return es_subarbol(ab1.right(), ab2.right());

        return es_subarbol(ab1.left(), ab2.left()) && es_subarbol(ab1.right(), ab2.right());
    }
    return es_subarbol(ab1.left(), ab2) || es_subarbol(ab1.right(), ab2);    
}