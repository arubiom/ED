/**
 * @file Pila_max.h
 * @author Alejandro Rubio Martinez y Juan Fernandez de Cañete Verdejo
 * @brief A stack made with vectors
 * 
 */
#ifndef PILA_MAX_VD_H
#define PILA_MAX_VD_H

#include <vector>
using namespace std;

template<class T>
class Pila_max {
private:
    struct elemento{  
        T ele; 
        T maximo;
    };

    vector<elemento> pila;
public:
    /**
     * @brief Construct a new Pila_max object
     * 
     */
    Pila_max();
    /**
     * @brief Push a new object to the stack
     * 
     * @param nuevo The element we want to push
     */
    void push(T nuevo);
    /**
     * @brief Get the Top object
     * 
     * @return T The object in the top
     */
    T top();
    /**
     * @brief Get the max object
     * 
     * @return T The max in the top
     */
    T max();
    /**
     * @brief Pop the top element of the stack
     * 
     */
    void pop();
    /**
     * @brief Check if the stack is empty
     * 
     * @return true If it is empty
     * @return false If it has at least 1 element
     */
    bool empty();
};

#include "../src/Pila_max_VD.cpp"
#endif /* PILA_MAX_VD_H */