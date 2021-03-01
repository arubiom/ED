
/* 
 * @File:   Cola_Max.cpp
 * @Author: Juan Fernańdez de Cañete
 * 
 * Created on November 24, 2020, 4:16 PM
 */

#include <cassert>
#include <stack>
#include "../inc/Cola_Max.h"

template<class T>
Cola_Max<T>::Cola_Max() {
}

template<class T>
Cola_Max<T>::Cola_Max(const Cola_Max & orig) {
    cola = orig.cola;
}

template<class T>
void Cola_Max<T>::push(const T _x) {
    
    T mayor;

    if (!empty()) {
        if (max() < _x)
            mayor = _x;
        else
            mayor = max();
    }
    else
        mayor = _x;

    cola.push({_x,mayor});
}

template<class T>
void Cola_Max<T>::pop() {
    assert(!empty());
    cola.pop();
}

template<class T>
long unsigned int Cola_Max<T>::size() {
    return cola.size();
}

template<class T>
T Cola_Max<T>::front() {
    assert(!empty());
    return cola.top().x;
}

template<class T>
T Cola_Max<T>::back() {
    assert(!empty());
    stack<Cell> aux=cola;
    while(aux.size()>1)
        aux.pop();
    return aux.top().max;
}

template<class T>
T Cola_Max<T>::max() {
    assert(!empty());
    return cola.top().max;
}

template<class T>
bool Cola_Max<T>::empty() {
    return (cola.empty());
}
