main: main.o guiatlf.o
	@g++ -g obj/main.o obj/guiatlf.o -o bin/main
	@echo El puto amo

guiatlf.o:
	@g++  -c -g src/guiatlf.cpp -o obj/guiatlf.o

main.o:
	@g++ -g -c src/main.cpp -o obj/main.o

clean:
	@echo Limpiando...
	@rm -rf bin/* obj/*