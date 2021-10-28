#include "mapa.h"
#include <string>
#include <iostream>

using namespace std;

mapa::mapa(string nombre):archivo(nombre){

    leerArchivo(nombre);

}

void mapa::leerArchivo(string nombre)
{
    int i = 0;
    int j = 0;

    fstream documento(nombre, ios::in);

    string tipoTerreno;

    documento >> filas;
    documento >> columnas;

    construirMatriz();

    while (documento >> tipoTerreno) {
        matrizMapa->agregarCasillero(tipoTerreno, i, j);
        i++;
        if (i % columnas == 0)
        {
            j++;
            i = 0;
        }
    }
    matrizMapa->mostrarMatriz();

    documento.close();
}

void mapa::construirMatriz(){
    matrizMapa = new Matriz(columnas,filas);
}

mapa::~mapa() {
    delete matrizMapa;
}
