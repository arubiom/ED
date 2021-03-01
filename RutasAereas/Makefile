SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin

rutas_aereas: Ruta.o Punto.o ruta_aerea.o almacen.o imagen.o imagenES.o Pais.o Paises.o
	g++ -I$(INC) $(OBJ)/rutas_aereas.o $(OBJ)/Ruta.o $(OBJ)/Punto.o $(OBJ)/almacen.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/Pais.o $(OBJ)/Paises.o -o $(BIN)/rutas_aereas

Ruta.o: 
	g++ -c -I$(INC) $(SRC)/Ruta.cpp -o $(OBJ)/Ruta.o

Punto.o:
	g++ -c -I$(INC) $(SRC)/Punto.cpp -o $(OBJ)/Punto.o

ruta_aerea.o: 
	g++ -c -I$(INC) $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o

almacen.o:
	g++ -c -I$(INC) $(SRC)/AlmacenRutas.cpp -o $(OBJ)/almacen.o

imagen.o:
	g++ -c -I$(INC) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

imagenES.o:
	g++ -c -I$(INC) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

Pais.o:
	g++ -c -I$(INC) $(SRC)/Pais.cpp -o $(OBJ)/Pais.o
	
Paises.o:
	g++ -c -I$(INC) $(SRC)/Paises.cpp -o $(OBJ)/Paises.o
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
