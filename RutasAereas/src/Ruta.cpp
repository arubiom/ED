#include "Ruta.h"

Ruta::Ruta() {}


Ruta::Ruta(const Ruta &otra) {
    ruta = otra.getRuta();
    codigo = otra.getCod();
}

Ruta& Ruta::operator=(const Ruta & r) {
    if (this != &r) {
        clear();
        ruta = r.getRuta();
        codigo = r.getCod();
    }

    return *this;
}

Ruta::~Ruta() {}

void Ruta::clear(){
    ruta.clear();
}

vector<Punto> Ruta::getRuta() const{
    return ruta;
}

Punto& Ruta::operator[](int i) {
    return ruta[i];
}

Punto Ruta::operator[](int i) const{
    return ruta[i];
}

int Ruta::size() const {
    return ruta.size();
}

// bool Ruta::operator<(const Ruta &R){
//     return (codigo < R.getCod());
// }

void Ruta::setCod(string cod){
    codigo = cod;
}

string Ruta::getCod() const{
    return codigo;
}

istream& operator>>(istream &is, Ruta &R) {
    int n;
    Punto dato;
    string cod;

    is >> cod;
    R.setCod(cod);

    is >> n;
    
    for (int i = 0; i < n; i++) {
        is >> dato;
        R.ruta.push_back(dato);
    }

    return is;
}

ostream& operator<<(ostream &os, const Ruta &R){
    os << R.getCod() << " ";

    os << R.size();

    for(int i=0; i<R.size(); i++){
        os << " " << R[i];
    }

    return os;
}

Ruta::iterator::iterator(){}

Ruta::iterator::iterator(const vector<Punto>::iterator & it) {
    rit = it;
}

Ruta::iterator & Ruta::iterator::operator=(const Ruta::iterator & it){
    if (this != &it) {
        rit = it.rit;
    }

    return *this;
}

Ruta::iterator & Ruta::iterator::operator ++(){
    ++rit;
    return *this;
}

Ruta::iterator & Ruta::iterator::operator --(){
    --rit;
    return *this;
}

bool Ruta::iterator::operator==(const Ruta::iterator  & it){
    return rit == it.rit;
}

bool Ruta::iterator::operator!=(const iterator  & it){
    return rit != it.rit;
}

const Punto & Ruta::iterator::operator*()const{
    return *rit;
}


Ruta::const_iterator::const_iterator(){}

Ruta::const_iterator::const_iterator(const vector<Punto>::const_iterator & it){
    rit = it;
}

Ruta::const_iterator& Ruta::const_iterator::operator=(const Ruta::const_iterator & it){
    if (this != &it) {
        rit = it.rit;
    }

    return *this;
}

Ruta::const_iterator & Ruta::const_iterator::operator++(){
    ++rit;
    return *this;
}

Ruta::const_iterator & Ruta::const_iterator::operator--(){
    --rit;
    return *this;
}

bool Ruta::const_iterator::operator==(const const_iterator  & it){
    return rit == it.rit;
}

bool Ruta::const_iterator::operator!=(const const_iterator  & it){
    return rit != it.rit;
}

const Punto& Ruta::const_iterator::operator*()const{
    return *rit;
}

Ruta::iterator Ruta::begin() {
    Ruta::iterator it(ruta.begin());
    return it;
}


Ruta::iterator Ruta::end() {
    Ruta::iterator it(ruta.end());
    return it;
}


Ruta::const_iterator Ruta::cbegin() {
    Ruta::const_iterator it(ruta.cbegin());
    return it;
}


Ruta::const_iterator Ruta::cend() {
    Ruta::const_iterator it(ruta.cend());
    return it;
}


