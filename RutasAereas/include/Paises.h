#ifndef PAISES_H
#define PAISES_H
#include "Pais.h"
#include <set>
using namespace std;

class Paises{
private:
    set<Pais> datos;
public:
	Paises();

	void Insertar(const Pais &P);

	void Borrar(const Pais &P);

    class const_iterator;

	class iterator{
	private:
	    set<Pais>::iterator p;
	public:
	    iterator();

	    iterator & operator ++();

	    iterator & operator --();

	    bool operator==(const iterator  & it);

	    bool operator!=(const iterator  & it);

	    const Pais & operator*()const;

	    friend class Paises;
		
	    friend class const_iterator;
	};

	class const_iterator{
	private:
	    set<Pais>::const_iterator p;
	public:
	    const_iterator();

	    const_iterator(const iterator & it);

	    const_iterator & operator=(const iterator & it);

	    const_iterator & operator++();

	    const_iterator & operator--();

	    bool operator==(const const_iterator  & it);

	    bool operator!=(const const_iterator  & it);

	    const Pais &operator*()const;

	    friend class Paises;
	};

	iterator begin();
	
	const_iterator begin() const;

	iterator end();

	const_iterator end() const;

	iterator find(const Pais &p);

	iterator find(const Punto &p);

	friend istream & operator>>(istream & is, Paises & R);

	friend ostream & operator<<(ostream & os, const Paises &R);
};
#endif

