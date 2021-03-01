SRC=src/
INC=inc/
OBJ=obj/
BIN=bin/
DOC=doc/

main: main.o
	@echo Compilando...
	@g++ $(OBJ)main.o -o $(BIN)main
	@echo Compilado con exito!

main.o:
	@g++ -c $(SRC)main.cpp -o $(OBJ)main.o

clean:
	@echo Limpiando...
	@rm -rf $(OBJ)* $(BIN)* $(DOC)*

document:
	@doxygen
	@echo La documentacion generada se ha guardado en $(DOC)