#include "Ruta.h"
#include "AlmacenRutas.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char * argv[]){
  cout << "Ha empezado el programa" << endl;
  if (argc!=2){
    cout<<"Dime el nombre del fichero de entrada"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  
  Ruta R;
  AlmacenRutas AR;
  string aux;

  cout << "Vamos a hacer el de entrada" << endl;
  f>>AR; //leemos las rutas y los puntos de interes
  cout << "Entrada ta bien" << endl;


  cout << AR << endl;
  cout << "Salida ta bien" << endl;
  
}
  