/**
 * @file guiatlf.h
 * @author Alejandro Rubio Martinez
 * @brief The implementation os the class Guia_Tlf
 * 
 * @note Las funciones implementadas son empty, changeName, searchName, intersect
 */
#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Overload the >> operator
 * 
 * @param is The stream of data
 * @param d The datas
 * @return istream& The stream of datas
 */
istream & operator>>(istream &is,pair<string,string> &d);	  

class Guia_Tlf{
private:
	map<string,string> datos; 
					
public:
	class Iterator {
    private:
        map<string,string>::iterator it;

    public:
        /**
         * @brief Get the iterator
         * 
         * @return map<string,string>::iterator The list iterator
         */
        map<string,string>::iterator get() const;
        /**
         * @brief Construct a new Iterator object
         * 
         */
        Iterator();
        /**
         * @brief Construct a new Iterator object
         * 
         */
        Iterator(map<string,string>::iterator iter);
        /**
         * @brief Overload the ++ operator
         * 
         * @param iter The iterator we want to increment
         * @return it* A pointer to the new iterator
         */
        Guia_Tlf::Iterator operator++();
        /**
         * @brief Overload the -- operator
         * 
         * @param iter The iterator we want to decrement
         * @return it* A pointer to the new iterator
         */
        Guia_Tlf::Iterator operator--();
        /**
         * @brief Overload the = operator
         * 
         * @param iter The iterator we want to copy
         * @return Iterator The new iterator
         */
        Guia_Tlf::Iterator operator=(Guia_Tlf::Iterator iter);
        /**
         * @brief Overload the != operator
         * 
         * @param iter The iterator we will compare
         * @return Iterator& False if its equal, true if not
         */
        bool operator!=(const Guia_Tlf::Iterator & iter);
        /**
         * @brief Overload the == operator
         * 
         * @param iter The iterator we will compare
         * @return Iterator& True if its equal, false if not
         */
        bool operator==(const Iterator & iter);
        /**
         * @brief Overload the * pointer operator
         * 
         * @return list<data<T,U>> 
         */
        pair<const string,string> & operator*();
    };
    class Const_Iterator {
    private:
        map<string,string>::const_iterator it;

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
        Const_Iterator(map<string,string>::const_iterator iter);
        /**
         * @brief Get the iterator
         * 
         * @return list<data<T,U>>::iterator The iterator
         */
        map<string,string>::const_iterator getConst() const;
        /**
         * @brief Overload the ++ operator
         * 
         * @param iter The iterator we want to increment
         * @return it* A pointer to the new iterator
         */
        Guia_Tlf::Const_Iterator operator++();
        /**
         * @brief Overload the -- operator
         * 
         * @param iter The iterator we want to decrement
         * @return it* A pointer to the new iterator
         */
        Const_Iterator operator--();
        /**
         * @brief Overload the = operator
         * 
         * @param iter The iterator we want to copy
         * @return Iterator The new iterator
         */
        Const_Iterator operator=(Guia_Tlf::Const_Iterator iter);
        /**
         * @brief Overload the != operator
         * 
         * @param iter The iterator we will compare
         * @return Iterator& True if its equal, false if not
         */
        bool operator!=(const Guia_Tlf::Const_Iterator & iter);
        /**
         * @brief Overload the * pointer operator
         * 
         * @return list<data<T,U>> 
         */
        const pair<const string,string> & operator*();
    };
	/**
	 * @brief Construct a new Guia_Tlf object
	 * 
	 */
	Guia_Tlf();
	/**
	 * @brief Construct a new Guia_Tlf object
	 * 
	 * @param gt The other guide
	 */
	Guia_Tlf(const Guia_Tlf & gt);
	/**
	 * @brief Destroy the Guia_Tlf object
	 * 
	 */
	~Guia_Tlf();
	/**
	 * @brief Overload the = opeartor
	 * 
	 * @param gt The other guide
	 * @return Guia_Tlf& A pointer to the guide
	 */
	Guia_Tlf & operator=(const Guia_Tlf & gt);
	/**
	 * @brief Get the map object
	 * 
	 * @return map<string,string> The map of the Guide 
	 */
	map<string,string> get() const;
	/**
	 * @brief Overload the [] operator
	 * 
	 * @param nombre The position
	 * @return string& A pointer
	 */
	string & operator[](const string &nombre);
	/**
	 * @brief Get a telephone
	 * 
	 * @param nombre The position
	 * @return string The telephone
	 */
	string  gettelefono(const string & nombre);
	/**
	 * @brief Insert a new telephone contact
	 * 
	 * @param nombre The contact
	 * @param tlf The tlf
	 * @return pair<map<string,string>::iterator,bool>  ture if it is ok false if it is not
	 */
	pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);
	/**
	 * @brief Insert a new telephone contact
	 * 
	 * @param p 
	 * @return pair<map<string,string>::iterator,bool> true if it is ok false it is not
	 */
	pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);
	/**
	 * @brief Delete a contact
	 * 
	 * @param nombre Who we want to delete
	 */
	void borrar(const string &nombre);
	/**
	 * @brief Delete a telephone
	 * 
	 * @param nombre Which we want to delete
	 * @param tlf His telephone
	 */
	void borrar(const string &nombre,const string &tlf);
	/**
	 * @brief The number of telephones
	 * 
	 * @return int The number of telephones
	 */
	int size() const;	      
	/**
	 * @brief Count how many telephones have a name asociatted
	 * 
	 * @param nombre 
	 * @return unsigned int 
	 */
	unsigned int contabiliza(const string &nombre);
	/**
	 * @brief clear the guide
	 * 
	 */
	void clear();	      
	/**
	 * @brief Overload the + operator
	 * 
	 * @param g The other guide
	 * @return Guia_Tlf The guide joined
	 */
	Guia_Tlf operator+(const Guia_Tlf & g);	   		
	/**
	 * @brief Overload the - operator
	 * 
	 * @param g The other guide
	 * @return Guia_Tlf The guide merged
	 */
	Guia_Tlf operator-(const Guia_Tlf & g);
	/**
	 * @brief Overload the << operator
	 * 
	 * @param os The stream of data
	 * @param g The datas
	 * @return ostream& The stream of datas
	 */
	friend ostream & operator<<(ostream & os, Guia_Tlf & g);
	/**
	 * @brief Overload the >> operator
	 * 
	 * @param is The stream of data
	 * @param g The datas
	 * @return istream& The stream of data
	 */
	friend istream & operator>>(istream & is, Guia_Tlf & g);
	/**
	 * @brief Intersects two guides
	 * 
	 * @param gt1 The first guide
	 * @param gt2 The second guide
	 * @return Guia_Tlf The intersection
	 */
	Guia_Tlf intersect(Guia_Tlf &gt1);
	/**
	 * @brief Change a telephone number
	 * 
	 * @param number The new number
	 * @param name Who we will change the number
	 */
	void changeNumber(string name, string number);
	/**
	 * @brief Check if the guide is empty
	 * 
	 * @return true If it is empty
	 * @return false if it is not
	 */
	bool empty();
	/**
	 * @brief Get the Names from a number
	 * 
	 * @param number The number
	 * @return string All the names with that number
	 */
	string getNames(string number);
	/**
	 * @brief The begin of the guide
	 * 
	 * @return Guia_Tlf::Iterator An iterator to the beginning
	 */
	Guia_Tlf::Iterator begin();
	/**
	 * @brief The end of the guide
	 * 
	 * @return Guia_Tlf::Iterator An iterator to the ending
	 */	
	Guia_Tlf::Iterator end();
	/**
	 * @brief The begin of the guide const version
	 * 
	 * @return Guia_Tlf::Iterator An iterator to the beginning
	 */
	Guia_Tlf::Const_Iterator cbegin();
	/**
	 * @brief The end of the guide const version
	 * 
	 * @return Guia_Tlf::Iterator An iterator to the ending
	 */
	Guia_Tlf::Const_Iterator cend();
};
#endif