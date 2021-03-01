#include "../inc/Diccionario.h"
#include "../inc/guiatlf.h"
#include <fstream>
#include <cstring>
#include <string>

int main() {
    //Prueba del diccionario
    Dictionary<string,string> D1, D2, D3;
    list<string> aux;
    Dictionary<string,string>::Iterator it;

    aux.push_back("Instrumento de limpieza");

    D1.insert("Fregona",aux);
    cout << D1;
    cout << "-----------------------------------------------------------------------" << endl;

    D1.addMeaning("Se usa para limpiar", "Fregona");
    cout << D1;
    cout << "-------------------- HAGAMOS UN SEGUNDO DICCIONARIO -------------------" << endl;

    D2.insert("Mopa",aux);
    cout << D2;
    cout << "-----------------------------------------------------------------------" << endl;

    D2.addMeaning("No tiene entrada en la RAE", "Mopa");
    cout << D2;
    cout << "-------------------- SUMEMOS LOS DOS DICCIONARIOS ---------------------" << endl;

    D3 = D1 + D2;
    cout << D3;
    cout << "------------------- ELIMINEMOS LOS ELEMENTOS 1 A 1 --------------------" << endl;

    while(!D3.empty()) {
        it = D3.begin();
        D3.erase(it);
        cout << D3;
        cout << "-----------------------------------------------------------------------" << endl;
    }
    
    if (D3.empty())
        cout << "Esta vacia" << endl;
    else
        cout << "No esta vacia" << endl;

    cout << "Probemos ahora las guias telefonicas" << endl;

    Guia_Tlf g;
    fstream file1;
    file1.open("data/guia.txt");
    
    cout << "Introduce una guia"<<endl;
    file1 >> g;
    cout <<"La guia insertada es:\n"<<g<<endl;
    file1.close();
    /**
    cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
    string n;
    while (getline(cin,n)){
        cout<<"Buscando "<<n<<"...."<<endl;
        string tlf = g.gettelefono(n);
        if (tlf==""){
                cout<<"No existe ese nombre en la guia"<<endl;
        }
        else 
            cout<<"El telefono es "<<tlf<<endl;
        cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
    }	
    cin.clear();
    cout<<"Dime el nombre que quieres borrar"<<endl;
    
    while (getline(cin,n)){
        g.borrar(n);
        cout<<"Dime el nombre que quieres borrar"<<endl;
    }
    
    cout<<"Dime el nombre que quieres borrar"<<endl;
    
    while (getline(cin,n)){
        g.borrar(n);
        cout<<"Ahora la guia es:"<<endl;
        cout<<g<<endl;
        cout<<"Dime el nombre que quieres borrar"<<endl;
    }
    cin.clear();
    **/
    Guia_Tlf otraguia;
    fstream file2;
    file2.open("data/guia2.txt");

    cout<<"Introduce otra guia"<<endl;

    file2 >> otraguia;

    cout << "La guia insertada es:\n" << otraguia << endl;
    file2.close();
    cout << "Cambiamos el numero de Tristan Salinas Porte por 1234567890" << endl;
    otraguia.changeNumber("Tristan Salinas Porte", "1234567890");
    cout << "Veamos si el numero es este nuevo: " << otraguia.getNames("1234567890") << endl;

    Guia_Tlf un = g+otraguia;
    Guia_Tlf dif = g-otraguia;
    Guia_Tlf in = g.intersect(otraguia);

    cout << "La union de las dos guias: " << endl << un << endl;
    
    cout << "La diferencia de las dos guias:" << endl << dif << endl;

    cout << "La interseccion de las dos guias: " << endl << in << endl;
}