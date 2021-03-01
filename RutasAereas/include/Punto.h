#ifndef PUNTO_H
#define PUNTO_H

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Punto{
private:
    double latitud, longitud;
    string descripcion;
public:
    /**
     * @brief Construct a new Punto object
     * 
     */
    Punto();
    /**
     * @brief Construct a new Punto object
     * 
     * @param P Another point from we want to construct
     */
    Punto(const Punto& P);
    /**
     * @brief Construct a new Punto object
     * 
     * @param lat The latitude
     * @param lon The long
     * @param desc The description
     */
    Punto(double lat, double lon, string desc);
    /**
     * @brief Overload the == operator
     * 
     * @param P The point we will equalice
     * @return Punto& A reference to the new point
     */
    Punto & operator=(const Punto & P);
    /**
     * @brief Overload the == operator
     * 
     * @param p The point we want to check if its equal to this
     * @return true If its equal
     * @return false If not
     */
    bool operator==(const Punto& p) const;
    /**
     * @brief Overload the != operator
     * 
     * @param p The point we want to check if its different
     * @return true If its different
     * @return false If not
     */
    bool operator!=(const Punto& p);
    /**
     * @brief Get the Lat object
     * 
     * @return double The lat
     */
    double getLat() const;
    /**
     * @brief Get the Lon object
     * 
     * @return double The long
     */
    double getLon() const;
    /**
     * @brief Get the Desc object
     * 
     * @return string The desc
     */
    string getDesc() const;
    /**
     * @brief Set the Lat object
     * 
     * @param lat The lat
     */
    void setLat(double lat);
    /**
     * @brief Set the Lon object
     * 
     * @param lon The long
     */
    void setLon(double lon);
    /**
     * @brief Set the Desc object
     * 
     * @param desc The desc
     */
    void setDesc(string desc);
    /**
     * @brief Overload the >> operator
     * 
     * @param is The stream of data
     * @param P The point we will fill
     * @return istream& The stream of data
     */
    friend istream& operator>>(istream & is, Punto &P);
    /**
     * @brief Overload the << operator
     * 
     * @param os The stream of data
     * @param P The point we will show
     * @return ostream& The stream of data
     */
    friend ostream& operator<<(ostream & os, const Punto &P);

};

#endif