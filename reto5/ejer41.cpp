/**
 * @file ejer41.cpp
 * @author Alejandro Rubio Martinez
 * @brief Implementar una función
 *   int enquenivel (bintree<int>:: node w, bintree<int> & A);
 * que  devuelva el nivel del nodo w en el árbol A (la raíz está a nivel 0).
 * 
 */

#include <iostream>
#include "./bintree/bintree.h"
using namespace std;

/**
 * @brief Devuelve en que nivel esta un nodo en un arbol A
 * 
 * @param w 
 * @param A 
 * @return int 
 */
int enquenivel (bintree<int>::node w, const bintree<int> & A);

int main() {
    bintree<int> A(3);
	A.insert_left(A.root(), 6);
	A.insert_right(A.root(), 9);
	A.insert_left(A.root().right(), 8);
	A.insert_right(A.root().right(), 4);

    int nivel = enquenivel(A.root().right().right(),A);

    cout << "Esta en el nivel " << nivel << endl;
}

int enquenivel (bintree<int>::node w, const bintree<int> & A) {
    int retval = 0;

    while (w != A.root()) {
        retval++;
        w = w.parent();
    }

    return retval;
}