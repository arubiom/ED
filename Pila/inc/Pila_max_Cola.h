
/* 
 * @File:   Pila_max.h
 * @Author: Juan Fernández de Cañete Verdejo y Alejandro Rubio Martinez
 *
 * Created on November 24, 2020, 4:16 PM
 */

#ifndef PILA_MAX_COLA_H
#define PILA_MAX_COLA_H

#include "../inc/cola.h"
using namespace std;

template<class T>
class Pila_max {
public:
    /**
     * @brief Constructor por defecto
     */
    Pila_max();
    /**
     * @brief Constructor de copias
     * @param orig La pila de la que se hará la copia.
     */
    Pila_max(const Pila_max & orig);
    /**
     * @brief Añade un elemento al tope de la pila
     * @param _x integrer a añadir en el tope
     */
    void push(const T _x);
    /**
     * @brief Elimina el elemento situado en el tope de la pila
     */
    void pop();
    /**
     * @brief Tamaño de la pila
     * @return Tamaño de la pila
     */
    long unsigned int size();
    /**
     * @brief Tope de la pila
     * @return Tope de la pila
     */
    T top();
    /**
     * @brief Maximo de la pila
     * @return Maximo de la pila
     */
    T max();
    /**
     * @brief Mira si la pila está vacia
     * @return true si la pila está vacía
     */
    bool empty();
    
private:
    struct Cell {
        T x; // Elemento de la pila
        T max; // Máximo de los elementos de la pila
    };
    Cola<Cell> pila; //Cola del struct Cell anterior
};

#include "../src/Pila_max_Cola.cpp"

#endif /* Pila_max_H */

