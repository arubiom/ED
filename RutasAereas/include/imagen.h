#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>
enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;
struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};  
class Imagen{
private:
	Pixel **data;
	int nf,nc;
	void Borrar();
	void Copiar(const Imagen &I);
public:
	/**
	 * @brief Construct a new Imagen object
	 * 
	 */
	Imagen();
	/**
	 * @brief Construct a new Imagen object
	 * 
	 * @param f The number of rows
	 * @param c The number of columns
	 */
	Imagen(int f,int c);
	/**
	 * @brief Construct a new Imagen object
	 * 
	 * @param I Another Image
	 */
	Imagen(const Imagen & I);
	/**
	 * @brief Overload the = operator
	 * 
	 * @param I The image we want to equalize
	 * @return Imagen& The image that we will copy 
	 */
	Imagen & operator=(const Imagen & I);
	/**
	 * @brief Destroy the Imagen object
	 * 
	 */
	~Imagen();

	Pixel getPixel();

	void set(const Pixel &p);
	
	Pixel & operator ()(int i,int j);

	const Pixel & operator ()(int i,int j)const;

	void EscribirImagen(const char *nombre);

	void LeerImagen (const char *nombre, const string &nombremascara="");

	void LimpiarTransp();

	inline int num_filas() const{return nf;}

	inline int num_cols() const{return nc;}

	void PutImagen(int posi,int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO);

	Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);
};
   
#endif