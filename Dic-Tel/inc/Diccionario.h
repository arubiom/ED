/**
 * @file Diccionario.h
 * @author Alejandro Rubio Marínez
 * @brief Class which represents a dictionary using lists from stl
 * @note Las nuevas funciones implementadas son operator<<, empty, erase, operator+
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <list>
#include <iostream>
using namespace std;

/**
 * @brief Datas from the dictionary
 * 
 * @tparam key The key associated to a data 
 * @tparam info All the information about that key
 */
template<class T, class U>
struct data {
    T key;
    list<U> info;
};

template<class T,class U>
class Dictionary {
private:
    list<data<T,U>> dict;
    
    /**
     * @brief Copy  a dcitionary
     * 
     * @param D The dictionary we want to copy
     */
    void copy(const Dictionary<T,U>& D);
    /**
     * @brief Erase a full dictionary
     * 
     */
    void clear();

public:
    class Iterator {
    private:
        typename list<data<T,U>>::iterator it;

    public:
        /**
         * @brief Get the iterator
         * 
         * @return list<data<T,U>>::iterator The list iterator
         */
        typename list<data<T,U>>::iterator get() const;
        /**
         * @brief Construct a new Iterator object
         * 
         */
        Iterator();
        /**
         * @brief Construct a new Iterator object
         * 
         */
        Iterator(typename list<data<T,U>>::iterator iter);
        /**
         * @brief Overload the ++ operator
         * 
         * @param iter The iterator we want to increment
         * @return it* A pointer to the new iterator
         */
        typename list<data<T,U>>::iterator& operator++();
        /**
         * @brief Overload the -- operator
         * 
         * @param iter The iterator we want to decrement
         * @return it* A pointer to the new iterator
         */
        Iterator& operator--();
        /**
         * @brief Overload the = operator
         * 
         * @param iter The iterator we want to copy
         * @return Iterator The new iterator
         */
        Iterator operator=(typename Dictionary<T,U>::Iterator iter);
        /**
         * @brief Overload the != operator
         * 
         * @param iter The iterator we will compare
         * @return Iterator& False if its equal, true if not
         */
        bool operator!=(const typename Dictionary<T,U>::Iterator & iter);
        /**
         * @brief Overload the == operator
         * 
         * @param iter The iterator we will compare
         * @return Iterator& True if its equal, false if not
         */
        bool operator==(const typename Dictionary<T,U>::Iterator & iter);
        /**
         * @brief Overload the * pointer operator
         * 
         * @return list<data<T,U>> 
         */
        data<T,U> & operator*();
    };
    class Const_Iterator {
    private:
        typename list<data<T,U>>::const_iterator it;

    public:
        /**
         * @brief Construct a new Iterator object
         * 
         */
        Const_Iterator();
        /**
         * @brief Construct a new Iterator object
         * 
         */
        Const_Iterator(typename list<data<T,U>>::const_iterator iter);
        /**
         * @brief Get the iterator
         * 
         * @return list<data<T,U>>::iterator The iterator
         */
        typename list<data<T,U>>::const_iterator getConst() const;
        /**
         * @brief Overload the ++ operator
         * 
         * @param iter The iterator we want to increment
         * @return it* A pointer to the new iterator
         */
        typename list<data<T,U>>::const_iterator& operator++();
        /**
         * @brief Overload the -- operator
         * 
         * @param iter The iterator we want to decrement
         * @return it* A pointer to the new iterator
         */
        Const_Iterator& operator--();
        /**
         * @brief Overload the = operator
         * 
         * @param iter The iterator we want to copy
         * @return Iterator The new iterator
         */
        Const_Iterator operator=(typename Dictionary<T,U>::Const_Iterator iter);
        /**
         * @brief Overload the != operator
         * 
         * @param iter The iterator we will compare
         * @return Iterator& True if its equal, false if not
         */
        bool operator!=(const typename Dictionary<T,U>::Const_Iterator & iter);
        /**
         * @brief Overload the * pointer operator
         * 
         * @return list<data<T,U>> 
         */
        const data<T,U> & operator*();
    };

    /**
     * @brief Construct a new Dictionary object
     * 
     */
    Dictionary();
    /**
     * @brief Construct a new Dictionary object
     * 
     * 
     * @param D The object from we construct
     */
    Dictionary(const Dictionary<T,U> & D);
    /**
     * @brief Destroy the Dictionary object
     */
    ~Dictionary();
    /**
     * @brief Overload the = operator
     * 
     * @param D The new Dictionary object
     * @return Dictionary The object copied
     */
    Dictionary<T,U> & operator=(const Dictionary<T,U> &D);
    /**
     * @brief Checks if a key is in the dictionary
     * 
     * @param p The key we want to search
     * @param it_out The iterator to the key
     * @return true If it is in the dictionary
     * @return false If it is not
     */
    bool searchKey(const T &p, Iterator &it_out);
    /**
     * @brief Insert a new object to thedicctionary
     * 
     * @param key The key to we want to introduce 
     * @param info The info about that key we want to introduce
     */
    void insert(const T& key,const list<U> &info);
    /**
     * @brief Add new information to a key
     * 
     * @param s The information we want to add
     * @param p The key where we will add it
     */
    void addMeaning(const U & s ,const T &p);
    /**
     * @brief Get the Info object
     * 
     * @param p The key
     * @return list<U> 
     */
    list<U>  getInfo(const T & p);
    /**
     * @brief Get the number of keys
     * 
     * @return int The number of keys
     */
    int size()const;
    /**
     * @brief Check if the dictionary is empty
     * 
     * @return true If it is empty
     * @return false If it is not
     */
    bool empty() const;
    /**
     * @brief Delete one key with all its information
     * 
     * @param it The position where the key is
     */
    void erase(Iterator & it);
    /**
     * @brief Return the begining of the dictionary
     * 
     * @return list<data<T,U> >::iterator& The beginning
     */
    typename Dictionary<T,U>::Iterator begin();
    /**
     * @brief Return the end of the dictionary
     * 
     * @return list<data<T,U> >::iterator& The end
     */
    typename Dictionary<T,U>::Iterator end();
    /**
     * @brief Return the const begining of the dictionary
     * 
     * @return list<data<T,U> >::iterator& The const beginning
     */
    typename Dictionary<T,U>::Const_Iterator cbegin() const;
    /**
     * @brief Return the const end of the dictionary
     * 
     * @return list<data<T,U> >::iterator& The const end
     */
    typename Dictionary<T,U>::Const_Iterator cend() const;
};

/**
 * @brief Overload the << operator
 * 
 * @param os The stremam of data
 * @param D The dictionary we want to print
 * @return ostream& The stream of data
 */
template<class T,class U>
ostream& operator<<(ostream& os, const Dictionary<T,U>& D);
/**
 * @brief Overload the + operator
 * 
 * @param D1 The first dictionary
 * @param D2 The second dictionary
 * @return Dictionary<T,U>& 
 */
template<class T, class U>
Dictionary<T,U> operator+(const Dictionary<T,U> & D1, const Dictionary<T,U> & D2);

#include "../src/Diccionario.cpp"
#endif