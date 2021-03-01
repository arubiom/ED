#include "Punto.h"
#include <cassert>
#include <iostream>
#include <string>


Punto::Punto(){
}

Punto::Punto(const Punto& P){
    setLat(P.getLat());
    setLon(P.getLon());
    setDesc(P.getDesc());
}

Punto::Punto(double lat, double lon, string desc){
    setLat(lat); 
    setLon(lon);
    setDesc(desc);
}

Punto & Punto::operator=(const Punto & P){
    if (this!=&P){
		setLat(P.getLat());
        setLon(P.getLon());
        setDesc(P.getDesc());;
	}

	return *this;
}


bool Punto::operator==(const Punto& p) const{
    return (getLat() == p.getLat()) && (getLon() == p.getLon());
}

bool Punto::operator!=(const Punto& p){
    return !((*this) == p);
}


double Punto::getLat() const {
    return latitud;
}


double Punto::getLon() const {
    return longitud;
}


string Punto::getDesc() const {
    return descripcion;
}


void Punto::setLat(double lat){
    latitud = lat;
}


void Punto::setLon(double lon){
    longitud = lon;
}


void Punto::setDesc(string desc){
    descripcion = desc;
}


istream& operator>>(istream & is, Punto &P){
    double lon, lat;
    char basura;
    
    is >> basura;
    is >> lat;
    is >> basura;
    is >> lon;
    is >> basura;

    P.setLat(lat);
    P.setLon(lon);

    return is;
}


ostream& operator<<(ostream & os, const Punto &P){
    os << "(" << P.getLat() << "," << P.getLon() << ")";

    return os;
}