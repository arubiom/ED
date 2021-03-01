
/* 
 * @File:   Pila_max.cpp
 * @Author: Juan Fernańdez de Cañete y Alejandro Rubio Martinez
 * 
 * Created on November 24, 2020, 4:16 PM
 */

#include "../inc/Pila_max_Cola.h"
#include <cassert>

template<class T>
Pila_max<T>::Pila_max() {
}

template<class T>
Pila_max<T>::Pila_max(const Pila_max<T> & orig) {
    pila=orig.pila;
}

template<class T>
void Pila_max<T>::push(const T _x) {
    
    T mayor;

    if (!empty()) {
        if (max() < _x)
            mayor = _x;
        else
            mayor = max();
    }
    else
        mayor = _x;

    Cola<Cell> aux;
    aux.poner({_x,mayor});
    int n = pila.num_elementos();
    for (int i = 0; i < n; i++) {
        aux.poner(pila.frente());
        pila.quitar();
    }
    n = aux.num_elementos();
    for (int i = 0; i < n; i++) {
        pila.poner(aux.frente());
        aux.quitar();
    }
}

template<class T>
void Pila_max<T>::pop() {
    pila.quitar();
}

template<class T>
long unsigned int Pila_max<T>::size() {
    return pila.num_elementos();
}

template<class T>
T Pila_max<T>::top() {
    assert(size()>0);
    return pila.frente().x;
}

template<class T>
bool Pila_max<T>::empty() {
    if (pila.num_elementos()>0)
        return false;
    else 
        return true;
}

template<class T>
T Pila_max<T>::max() {
    assert(size()>0);
    return pila.frente().max;
}
