
/* 
 * @File:   Cola_Max.h
 * @Author: Juan Fernández de Cañete Verdejo y Alejandro Rubio Martinez
 *
 * Created on November 24, 2020, 4:16 PM
 */

#ifndef COLA_MAX_H
#define COLA_MAX_H

#include <stack>

template<class T>
class Cola_Max {
public:
    /**
     * @brief Constructor por defecto
     */
    Cola_Max();
    /**
     * @brief Constructor de copias
     * @param orig La cola de la que se hará la copia.
     */
    Cola_Max(const Cola_Max & orig);
    /**
     * @brief Añade un elemento a la cola
     * @param _x integrer a añadir a la cola
     */
    void push(const T _x);
    /**
     * @brief Elimina el elemento situado en el frente de la cola
     */
    void pop();
    /**
     * @brief Tamaño de la cola
     * @return Tamaño de la cola
     */
    long unsigned int size();
    /**
     * @brief Frente de la cola
     * @return Frente de la cola
     */
    T front();
    /**
     * @brief Último de la cola
     * @return Último de la cola
     */
    T back();
    /**
     * @brief Máximo de la cola
     * @return Máxima de la cola
     */
    T max();
    /**
     * @brief Mira si la cola está vacia
     * @return true si la cola está vacía
     */
    bool empty();
    
private:
    struct Cell {
        T x; // Elemento de la cola
        T max; // Máximo de los elementos de la cola
    };
    stack<Cell> cola; //Cola del struct Cell anterior
};

#include "../src/Cola_Max.cpp"
#endif /* COLA_MAX_H */

