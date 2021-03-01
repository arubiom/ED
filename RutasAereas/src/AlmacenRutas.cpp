#include "AlmacenRutas.h"

AlmacenRutas::AlmacenRutas(){}

AlmacenRutas::AlmacenRutas(const AlmacenRutas & AR){
    almacen = AR.almacen;
}

AlmacenRutas::~AlmacenRutas(){}

void AlmacenRutas::clear(){
    almacen.clear();
}

AlmacenRutas& AlmacenRutas::operator=(const AlmacenRutas & AR){
    if (this != &AR)
        almacen = AR.almacen;

    return *this;
}

void AlmacenRutas::add(const Ruta & r){
    almacen.push_back(r);
}

AlmacenRutas& AlmacenRutas::operator+=(const Ruta & r){
    add(r);
    return *this;
}

Ruta AlmacenRutas::getRuta(string cod){
    AlmacenRutas:iterator it;

    for (it = begin(); it != end(); ++it) {
        if ((*it).getCod() == cod)
            return *it;
    }

    Ruta r;
    return r;
}

istream& operator>>(istream &is, AlmacenRutas &AR) {
    Ruta ruta;
    string basura;

    is >> basura;

    while(is){
        is >> ruta;
        if(ruta.size() > 0)
            AR.almacen.push_back(ruta);
        ruta.clear();
    }
    
    return is;
}

ostream& operator<<(ostream &os, const AlmacenRutas &AR) {
    AlmacenRutas::const_iterator it;

    for(it = AR.cbegin(); it != AR.cend(); ++it){
        os << (*it) << endl << endl;
    }

    return os;
}

AlmacenRutas::iterator::iterator() {}


AlmacenRutas::iterator::iterator(const list<Ruta>::iterator & it) {
    ait = it;
}

AlmacenRutas::iterator & AlmacenRutas::iterator::operator=(const AlmacenRutas::iterator  & it){
    if (this != &it)
        ait = it.ait;

    return *this;
}

AlmacenRutas::iterator & AlmacenRutas::iterator::operator++() {
    ++ait;
    return *this;
}


AlmacenRutas::iterator & AlmacenRutas::iterator::operator--() {
    --ait;
    return *this;
}


bool AlmacenRutas::iterator::operator==(const AlmacenRutas::iterator & it) {
    return ait==it.ait;
}


bool AlmacenRutas::iterator::operator!=(const AlmacenRutas::iterator & it) {
    return !(*this==it);
}


Ruta & AlmacenRutas::iterator::operator*()const {
    return *ait;
}


AlmacenRutas::const_iterator::const_iterator(){}


AlmacenRutas::const_iterator::const_iterator(const list<Ruta>::const_iterator & it) {
    ait = it;
}


AlmacenRutas::const_iterator & AlmacenRutas::const_iterator::operator=(const AlmacenRutas::const_iterator & it) {
    if (this != &it)
        ait = it.ait;

    return *this;
}


AlmacenRutas::const_iterator & AlmacenRutas::const_iterator::operator++() {
    ++ait;
    return *this;
}


AlmacenRutas::const_iterator & AlmacenRutas::const_iterator::operator--() {
    --ait;
    return *this;
}


bool AlmacenRutas::const_iterator::operator==(const AlmacenRutas::const_iterator  & it) {
    return ait == it.ait;
}


bool AlmacenRutas::const_iterator::operator!=(const AlmacenRutas::const_iterator  & it) {
    return !(*this==it);
}


const Ruta &AlmacenRutas::const_iterator::operator*()const {
    return *ait;
}


AlmacenRutas::iterator AlmacenRutas::begin() {
    AlmacenRutas::iterator it(almacen.begin());
    return it;
}


AlmacenRutas::iterator AlmacenRutas::end() {
    AlmacenRutas::iterator it(almacen.end());
    return it;
}


AlmacenRutas::const_iterator AlmacenRutas::cbegin() const {
    AlmacenRutas::const_iterator it(almacen.begin());
    return it;
}


AlmacenRutas::const_iterator AlmacenRutas::cend() const {
    AlmacenRutas::const_iterator it(almacen.end());
    return it;
}

