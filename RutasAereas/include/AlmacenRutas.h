#ifndef ALMACEN_RUTAS_H
#define ALMACEN_RUTAS_H

#include <cassert>
#include <iostream>
#include <string>
#include <list>
#include "Ruta.h"

class AlmacenRutas{
private:
    list<Ruta> almacen;
public:

    class iterator{
	private:
	    list<Ruta>::iterator ait;
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
		iterator(const list<Ruta>::iterator & it);
		/**
         * @brief Overload the ++ operator
         * 
         * @return iterator& The following element
         */
	    iterator & operator++();
		/**
         * @brief Overload the -- operator
         * 
         * @return iterator& The previous operator
         */
	    iterator & operator--();
		/**
         * @brief Overload the = operator
         * 
         * @param it The other iterator
         * @return iterator& The new iterator reference
         */
		iterator & operator=(const iterator  & it);
		/**
         * @brief Overload the == operator
         * 
         * @param it The iterator to compare
         * @return true If they are equal
         * @return false If not
         */
	    bool operator==(const iterator  & it);
		/**
         * @brief Overload the != operator
         * 
         * @param it The iterator to compare
         * @return true If they are not equal
         * @return false If they are equal
         */
	    bool operator!=(const iterator  & it);
		/**
		 * @brief Overload of the * operator
		 * 
		 * @return Ruta& The element which references the iterator
		 */
	    Ruta & operator*()const;

	    friend class Ruta;
		
	    friend class const_iterator;
	};

	class const_iterator{
	private:
	    list<Ruta>::const_iterator ait;
	public:
		/**
		 * @brief Construct a new const iterator object
		 * 
		 */
	    const_iterator();
		/**
         * @brief Construct a new const iterator object
         * 
         * @param it The new const iterator
         */
	    const_iterator(const list<Ruta>::const_iterator & it);
		/**
         * @brief Overload the ++ operator
         * 
         * @return const_iterator& The following element
         */
	    const_iterator & operator=(const const_iterator & it);
		/**
         * @brief Overload the ++ operator
         * 
         * @return const_iterator& The following element
         */
	    const_iterator & operator++();
		/**
         * @brief Overload the -- operator
         * 
         * @return const_iterator& The previous operator
         */
	    const_iterator & operator--();
		/**
         * @brief Overload the == operator
         * 
         * @param it The const_iterator to compare
         * @return true If they are equal
         * @return false If not
         */
	    bool operator==(const const_iterator  & it);
		/**
         * @brief Overload the != operator
         * 
         * @param it The const_iterator to compare
         * @return true If they are not equal
         * @return false If they are equal
         */
	    bool operator!=(const const_iterator  & it);
		/**
		 * @brief Overload of the * operator
		 * 
		 * @return Ruta& The element which references the const_iterator
		 */
	    const Ruta &operator*() const;

	    friend class Ruta;
	};

	/**
	 * @brief Basic constructor of the class
	 * 
	 */
    AlmacenRutas();
	/**
	 * @brief Copy constructor
	 * 
	 * @param AR another object of AlmacenRutas
	 */
    AlmacenRutas(const AlmacenRutas & AR);
	/**
	 * @brief Destructor
	 * 
	 */
    ~AlmacenRutas();
	/**
	 * @brief Leaves the object empty
	 * 
	 */
    void clear();
	/**
	 * @brief Overload of the = operator
	 * 
	 * @param AR another AlmacenRutas object
	 * @return AlmacenRutas& a reference to the changed object
	 */
    AlmacenRutas& operator=(const AlmacenRutas & AR);
	/**
	 * @brief Adds a route to the almacén
	 * 
	 * @param r the route
	 */
    void add(const Ruta & r);
	/**
	 * @brief Overload of the operator +=
	 * 
	 * @param r a route to add
	 * @return AlmacenRutas& a reference to the updated object
	 */
    AlmacenRutas& operator+=(const Ruta & r);
	/**
	 * @brief Returns the route of the specifed code (or an empty one if it doesn't exist)
	 * 
	 * @param cod the code
	 * @return Ruta the route
	 */
    Ruta getRuta(string cod);
	/**
	 * @brief Overload of the >> operator
	 * 
	 * @param is the istream
	 * @param AR the object
	 * @return istream& the istream again
	 */
	friend istream& operator>>(istream &is, AlmacenRutas &AR);
	/**
	 * @brief Overload of the << operator
	 * 
	 * @param os the ostream
	 * @param AR the object
	 * @return ostream& the ostream again
	 */
	friend ostream& operator<<(ostream &os, const AlmacenRutas &AR);
	/**
     * @brief Beginning of Ruta
     * 
     * @return iterator 
     */
    AlmacenRutas::iterator begin();
    /**
     * @brief Ending of Ruta
     * 
     * @return iterator 
     */
    AlmacenRutas::iterator end();
    /**
     * @brief Beginning of Ruta const version
     * 
     * @return iterator 
     */
    AlmacenRutas::const_iterator cbegin() const;

    AlmacenRutas::const_iterator cend() const;
};

#endif