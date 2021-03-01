#include "../inc/Pila_max_VD.h"

template<class T>
Pila_max<T>::Pila_max() {
    pila.clear();
}

template<class T>
void Pila_max<T>::push(T nuevo) {
    T maximo;
    
    if (!pila.empty()) {
        if (max() < nuevo)
            maximo = nuevo;
        else
            maximo = max();
    }
    else
        maximo = nuevo;

    pila.push_back({nuevo,maximo});
}

template<class T>
T Pila_max<T>::top() {
    return pila.back().ele;
}

template<class T>
void Pila_max<T>::pop() {
    if (!pila.empty())
        pila.pop_back();
}

template<class T>
bool Pila_max<T>::empty() {
    return pila.empty();
}

template<class T>
T Pila_max<T>::max() {
    return pila.back().maximo;
}