#include "mapa.h"
#include <string>
#include <iostream>

using namespace std;

mapa::mapa(string nombre):archivo(nombre){

    leerArchivo(nombre);

}

void mapa::leerArchivo(string nombre)
{

    fstream documento(nombre, ios::in);

    int ancho,alto;
    string tipoTerreno;

    documento >> ancho;
    documento >> alto;

    while (documento >> tipoTerreno)
    {
        agregarElementoArray(tipoTerreno);
    }

    documento.close();
}

