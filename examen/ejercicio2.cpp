/**
 * @file ejercicio2.cpp
 * @author Alejandro Rubio Martinez
 * @brief (1.5 puntos) Se define una  matriz singular  como una  matriz nxn
 *  en la que se vanalternando elementos pares e impares en círculos (siempre
 *  el mismo valor en cada caso).Un ejemplo de este tipo de matrices es la matriz que se muestra.
 * @version 0.1
 * @date 2021-01-21
 * 
 * 
 */
#include <vector>
#include <list>
using namespace std;

/**
 * @brief Utilizaremos un vector de listas para representar la matriz.
 * Cada elemento de la lista será un elemento de la matriz y las 
 * diferentes listas indican filas distintas
 * 
 */
class MatrizSingular {
private:
    vector<list<int>> datos;
public:
    //...

    int& operator()(int fil, int col) {
        list<int>::iterator it = datos[fil].begin();
        for (int i = 0; i < col; ++i) {
            ++it;
        }
        return *it;
    }

    class iterator {
    private:
        vector<list<int>>::iterator it1, final1;
        list<int>::iterator it2, final2;
    public:
        bool operator==(const iterator &i) {
            return it1 == i.it1 && it2 == i.it2;
        }
        bool operator!=(const iterator &i) {
            return it1 != i.it1 && it2 != i.it2;
        }
        int& operator*() {
            return *it2;
        }
        iterator & operator++() {
            ++it2;

            while (*it2 % 2 == 0 && it1 != final1) {
                ++it2;
                if (it2 == final2) {
                    ++it1;
                    it2 = (*it1).begin();
                    final2 = (*it1).end();
                }
            }

            return *this;
        }
        friend class MatrizSingular;
    };
    iterator begin() {
        iterator i;
        i.it1 = datos.begin();
        i.final1 = datos.end();

        i.it2 = (*i.it1).begin();
        i.final2 = (*i.it1).end();
        
        if(*i % 2 == 0)
            ++i;

        return i;
    }

    iterator end() {
        iterator i;
        i.it1 = datos.end();
        i.final1 = datos.end();
        i.it2 = (*i.it1).end();
        i.final2 = (*i.it1).end();
        return i;
    }
};