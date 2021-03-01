#ifndef RUTA_H
#define RUTA_H

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "Punto.h"

using namespace std;

class Ruta{
private:
    vector<Punto> ruta;
    string codigo;
public:
    class iterator{
	private:
	    vector<Punto>::iterator rit;
	public:
        /**
         * @brief Construct a new iterator object
         * 
         */
	    iterator();
        /**
         * @brief Construct a new iterator object
         * 
         * @param it The new iterator
         */
        iterator(const vector<Punto>::iterator & it);
        /**
         * @brief Overload the ++ operator
         * 
         * @return iterator& The following element
         */
	    iterator & operator ++();
        /**
         * @brief Overload the = operator
         * 
         * @param it The other iterator
         * @return iterator& The new iterator reference
         */
        iterator & operator=(const iterator & it);
        /**
         * @brief Overload the -- operator
         * 
         * @return iterator& The previous operator
         */
	    iterator & operator --();
        /**
         * @brief Overload the == operator
         * 
         * @param it The iteraotr to compare
         * @return true If they are equal
         * @return false If not
         */
	    bool operator==(const iterator  & it);
        /**
         * @brief Overload the != operator
         * 
         * @param it The iterator to compare with
         * @return true If they are not equal
         * @return false If they are equal
         */
	    bool operator!=(const iterator  & it);
        /**
         * @brief Overload the * operator
         * 
         * @return const Punto& The element which references the iterator
         */
	    const Punto & operator*()const;

	    friend class Punto;
		
	    friend class const_iterator;
	};

	class const_iterator{
	private:
	    vector<Punto>::const_iterator rit;
	public:
        /**
         * @brief Construct a new const iterator object
         * 
         */
	    const_iterator();
        /**
         * @brief Construct a new const iterator object
         * 
         * @param it Another iterator
         */
	    const_iterator(const vector<Punto>::const_iterator & it);
        /**
         * @brief Overload the = operator
         * 
         * @param it Other iterator
         * @return const_iterator& The new iterator reference
         */
	    const_iterator & operator=(const const_iterator & it);
        /**
         * @brief Overload the ++ operator
         * 
         * @return const_iterator& The following element
         */
	    const_iterator & operator++();
        /**
         * @brief Overload the -- iterator
         * 
         * @return const_iterator&  The previous element
         */
	    const_iterator & operator--();
        /**
         * @brief Overload the == operator
         * 
         * @param it The iterator to compare with
         * @return true If they are equal
         * @return false If not
         */
	    bool operator==(const const_iterator  & it);
        /**
         * @brief Overload the != operator
         * 
         * @param it Another operator
         * @return true If they are not equal
         * @return false If not
         */
	    bool operator!=(const const_iterator  & it);
        /**
         * @brief Overload the * operator
         * 
         * @return const Punto& A reference to the element in that position
         */
	    const Punto &operator*()const;

	    friend class Punto;
	};
    /**
     * @brief Basic constructor
     * 
     */
    Ruta();
    /**
     * @brief Copy constructor
     * 
     * @param otra Ruta
     */
    Ruta(const Ruta &otra);

    Ruta& operator=(const Ruta &r);
    /**
     * @brief Destroy the Ruta object
     * 
     */
    ~Ruta();
    /**
     * @brief Leaves the object empty
     * 
     */
    void clear();
    /**
     * @brief Returns the whole vector of Puntos
     * 
     * @return vector<Punto> 
     */
    vector<Punto> getRuta() const;
    /**
     * @brief Overload the [] operator
     * 
     * @param i The position we will return
     * @return Punto& A reference to the point
     */
    Punto & operator[](int i);
    /**
     * @brief Overload the [] operator const version
     * 
     * @param i The position where we will go
     * @return Punto The point in that position
     */
    Punto operator[](int i) const;
    /**
     * @brief Returns the size of the vector "ruta"
     * 
     * @return int the size
     */
    int size() const;
    // /**
    //  * @brief Overload of operator <
    //  * 
    //  * @param R another route
    //  * @return true if the code is lexically lower
    //  * @return false otherwise
    //  */
    // bool operator<(const Ruta &R);
    /**
     * @brief Sets the code of a route
     * 
     * @param cod The new code
     */
    void setCod(string cod);
    /**
     * @brief Returns the code of a route
     * 
     * @return string The code
     */
    string getCod() const;
    /**
     * @brief Beggining of Ruta
     * 
     * @return iterator 
     */
    Ruta::iterator begin();
    /**
     * @brief Ending of Ruta
     * 
     * @return iterator 
     */
    Ruta::iterator end();
    /**
     * @brief Beggining of Ruta const version
     * 
     * @return iterator 
     */
    Ruta::const_iterator cbegin();
    /**
     * @brief Ending of Ruta const version
     * 
     * @return iterator 
     */
    Ruta::const_iterator cend();
    /**
     * @brief Operator to load a route from a file or input
     * 
     * @param is The input
     * @param R The route
     * @return istream& The istream (so it can be used multiple times)
     */
    friend istream & operator>>(istream &is, Ruta &R);
    /**
     * @brief Operator to print a route
     * 
     * @param os The output
     * @param R The route
     * @return ostream& The ostream (so it can be used multiple times)
     */
    friend ostream & operator<<(ostream &os, const Ruta &R);
};

#endif