#include "../inc/guiatlf.h"

istream & operator>>(istream &is,pair<string,string> &d){
	  
	getline(is,d.first,'\t');
	getline(is,d.second);
	return is;
}

Guia_Tlf::Guia_Tlf() {}

Guia_Tlf::Guia_Tlf(const Guia_Tlf & gt) {
    *this = gt;
}

Guia_Tlf::~Guia_Tlf() {}

Guia_Tlf & Guia_Tlf::operator=(const Guia_Tlf & gt) {
    if (this!=&gt) {
        clear();
        datos = gt.get();
    }

    return *this;
}

map<string,string> Guia_Tlf::get() const {
    return datos;
}

string & Guia_Tlf::operator[](const string &nombre) {
	return datos[nombre];
}

string  Guia_Tlf::gettelefono(const string & nombre){
    map<string,string>::iterator it=datos.find(nombre);
    if (it==datos.end()) 
        return string("");
    else 
        return it->second;
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(string nombre, string tlf){
    pair<string,string> p (nombre,tlf);
    pair< map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p); 
    return ret;     
			
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(pair<string,string> p){
			
    pair<map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p); 
    return ret;     
			
}

void Guia_Tlf::borrar(const string &nombre){
    map<string,string>::iterator itlow = datos.lower_bound(nombre);
    map<string,string>::iterator itupper = datos.upper_bound(nombre);
    datos.erase(itlow,itupper);
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
    map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
    map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
    map<string,string>::iterator it;
    bool salir =false;
    for (it=itlow; it!=itupper && !salir;++it){
        if (it->second==tlf){
            datos.erase(it);
            salir =true;
        }		
    }		
    
}

int Guia_Tlf::size()const{
    return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre){
    return datos.count(nombre);
}

void Guia_Tlf::clear(){
    datos.clear();
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
	Guia_Tlf aux(*this);
	map<string,string>::const_iterator it;
	for (it=g.datos.begin();it!=g.datos.end();++it){
		aux.insert(it->first,it->second);
	}	  
	return aux;
	
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
	Guia_Tlf aux(*this);
	map<string,string>::const_iterator it;
	for (it=g.datos.begin();it!=g.datos.end();++it){
		aux.borrar(it->first,it->second);
	}	  
	return aux;
	
}

ostream & operator<<(ostream & os, Guia_Tlf & g){
    map<string,string>::iterator it;
    for (it=g.datos.begin(); it!=g.datos.end();++it){
    os<<it->first<<"\t"<<it->second<<endl;
    }
    return os;
}

istream & operator>>(istream & is, Guia_Tlf & g){
    pair<string,string> p;
    Guia_Tlf aux;
    
    while (is>>p){
        aux.insert(p);
    }

    g = aux;
    return is;
}

Guia_Tlf Guia_Tlf::intersect(Guia_Tlf &gt1) {
    Guia_Tlf ret;

    ret = (gt1 + *this) - ((gt1 - *this) + (*this - gt1));

    return ret;
}

void Guia_Tlf::changeNumber(string name, string number) {
    Guia_Tlf::Iterator it;

    for (it = begin(); it != end(); ++it) {
        if ((*it).first == name) {
            (*it).second = number;
        }
    }
}

bool Guia_Tlf::empty() {
    return datos.empty();
}

string Guia_Tlf::getNames(string number) {
    string ret = "";
    Guia_Tlf::Iterator it;

    for (it = begin(); it != end(); ++it) {
        if ((*it).second == number)
            ret += (*it).first + " ";
    }

    return ret;
}

map<string,string>::iterator Guia_Tlf::Iterator::get() const {
    return it;
}

Guia_Tlf::Iterator::Iterator() {}

Guia_Tlf::Iterator::Iterator(map<string,string>::iterator iter) {
    it = iter;
}

Guia_Tlf::Iterator Guia_Tlf::Iterator::operator++() {
    return ++it;
}

Guia_Tlf::Iterator Guia_Tlf::Iterator::operator--() {
    return --it;
}

Guia_Tlf::Iterator Guia_Tlf::Iterator::operator=(Guia_Tlf::Iterator iter) {
    if (this != &iter)
        it = iter.get();
    return *this;
}

bool Guia_Tlf::Iterator::operator!=(const Guia_Tlf::Iterator & iter) {
    return it != iter.get();
}

bool Guia_Tlf::Iterator::operator==(const Iterator & iter) {
    return it == iter.get();
}

pair<const string,string> & Guia_Tlf::Iterator::operator*() {
    return *it;
}

Guia_Tlf::Const_Iterator::Const_Iterator() {}

Guia_Tlf::Const_Iterator::Const_Iterator(map<string,string>::const_iterator iter) {
    it = iter;
}

map<string,string>::const_iterator Guia_Tlf::Const_Iterator::getConst() const {
    return it;
}

Guia_Tlf::Const_Iterator Guia_Tlf::Const_Iterator::operator++() {
    return ++it;
}

Guia_Tlf::Const_Iterator Guia_Tlf::Const_Iterator::operator--() {
    return --it;
}

Guia_Tlf::Const_Iterator Guia_Tlf::Const_Iterator::operator=(Guia_Tlf::Const_Iterator iter) {
    if (this != &iter)
        it = iter.getConst();
    return *this;
}

bool Guia_Tlf::Const_Iterator::operator!=(const Guia_Tlf::Const_Iterator & iter) {
    return it != iter.getConst();
}

const pair<const string,string> & Guia_Tlf::Const_Iterator::operator*() {
    return *it;
}

Guia_Tlf::Iterator Guia_Tlf::begin() {
    Guia_Tlf::Iterator iter(datos.begin());
    return iter;
}

Guia_Tlf::Iterator Guia_Tlf::end() {
    Guia_Tlf::Iterator iter(datos.end());
    return iter;
}

Guia_Tlf::Const_Iterator Guia_Tlf::cbegin() {
    Guia_Tlf::Const_Iterator iter(datos.cbegin());
    return iter;
}

Guia_Tlf::Const_Iterator Guia_Tlf::cend() {
    Guia_Tlf::Const_Iterator iter(datos.cend());
    return iter;
}