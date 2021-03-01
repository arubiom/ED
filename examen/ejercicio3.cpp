/**
 * @file ejercicio2.cpp
 * @author Alejandro Rubio Martinez
 * @brief (1.5 puntos) Dado un árbol binario de enteros A y un nivel en el árbol level, 
 * implementaruna función que encuentre los caminos de longitud mayor o igual que uno desde 
 * cualquier nodo de ese nivel a una hoja en el árbol. Devolver la solución en un vector de listas.
 * @version 0.1
 * @date 2021-01-21
 * 
 * 
 */
#include "./bintree/bintree.h"
#include <vector>
#include <list>
using namespace std;

/**
 * @brief Funcion auxiliar para el uso de la reursividad
 * 
 * @param n Un nodo
 * @param A Un arbol que contiene a ese nodo
 * @param level Un nivel
 * @param v Un vector donde guardaremops el objetivo
 * @return list<int> Una lista con un camino de un nodo a una hoja
 */
list<int> secuenciascaminos (bintree<int>::node n, bintree<int> A, int level, vector<list<int>> v);

int enquenivel (bintree<int>::node w, const bintree<int> & A);

vector<list<int>> secuenciascaminos (bintree<int> A, int level) {
    vector<list<int>> v;
    secuenciascaminos(A.root(), A, level, v);

    vector<list<int>>::iterator it;

    for (it = v.begin(); it != v.end(); ++it)
        if ((*it).size() == 1)
            v.erase(it);

    return v;
}

list<int> secuenciascaminos (bintree<int>::node n, bintree<int> A, int level, vector<list<int>> v) {
    list<int> l;

    if (enquenivel(n,A) >= level)
        l.push_back(*n);
    if (!n.left().null() && !n.right().null()) {
        l = secuenciascaminos(n.left(), A, level, v);
        l = secuenciascaminos(n.right(), A, level, v);
    }
    if (n.left().null() && !n.right().null())
        l = secuenciascaminos(n.right(), A, level, v);
    if (level && n.left().null() && !n.right().null())
        l = secuenciascaminos(n.left(), A, level, v);
    
    v.push_back(l);
    return l;
}

int enquenivel (bintree<int>::node w, const bintree<int> & A) {
    int retval = 0;

    while (w != A.root()) {
        retval++;
        w = w.parent();
    }

    return retval;
}