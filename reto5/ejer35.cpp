/**
 * @file ejer35.cpp
 * @author Alejandro Rubio Martínez
 * @brief Implementar una función:
 * void sumadosarboles bintree<int> A, bintree<int> B, bintree<int> C);
 * que dados 2 árboles binarios A y B  con la misma estructura de ramificación,
 * devuelva un árbol binario C, con la misma estructura y con etiquetas suma delas
 *  etiquetas de A y B en los nodos correspondientes.
 * 
 */

#include "./bintree/bintree.h"
#include <iostream>
using namespace std;
/**
 * @brief Comprueba si dos arboles tienen la misma estructura aprovechando su raiz
 * 
 * @param n1 Raiz del primer arbol
 * @param n2 Raiz del segundo arbol
 * @return true Si tienen la misma estructura
 * @return false Si no tienen la misma estructura
 */
bool _estructura(const bintree<int>::node &n1, const bintree<int>::node &n2);
/**
 * @brief Suma dos arboles con la misma estructura
 * 
 * @param A El primer arbol
 * @param B El segundo arbol
 * @param C El arbol donde almacenamos la suma
 */
void sumadosarboles(const bintree<int> &A, const bintree<int> &B, bintree<int> &C);

int main() {
    bintree<int> A(3), B(10), C;
	A.insert_left(A.root(), 6);
	A.insert_right(A.root(), 9);
	A.insert_left(A.root().right(), 8);
	A.insert_right(A.root().right(), 4);

	B.insert_left(B.root(), 3);
	B.insert_right(B.root(), 11);
	B.insert_left(B.root().right(), 8);
	B.insert_right(B.root().right(), 7);

    sumadosarboles(A, B, C);

    bintree<int>::preorder_iterator it = C.begin_preorder();
	for (; it != C.end_preorder(); ++it) {
		cout << *it << " ";
	}

    cout << endl;
    return 0;
}

bool _estructura(const bintree<int>::node &n1, const bintree<int>::node &n2) {
    if (n1.right().null() && n1.left().null() && n2.right().null() && n2.left().null())
        return true;
    else if (!n1.right().null() && !n1.left().null() && !n2.right().null() && !n2.left().null())
        return _estructura(n1.right(),n2.right()) && _estructura(n1.left(),n2.left());

    return false;
}

void sumadosarboles(const bintree<int> &A, const bintree<int> &B, bintree<int> &C) {
    if (!_estructura(A.root(),B.root())) {
        cerr << "Los árboles no tienen la misma estructura" << endl;
        exit(1);
    }
    
    C = A;

    bintree<int>::const_preorder_iterator itA = A.begin_preorder();
    bintree<int>::const_preorder_iterator itB = B.begin_preorder();
    bintree<int>::preorder_iterator itC = C.begin_preorder();

    for (;itC != C.end_preorder(); ++itC,++itA,++itB)
        *itC = *itB + *itA;
}