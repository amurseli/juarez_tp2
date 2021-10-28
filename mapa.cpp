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

    string tipoTerreno;

    documento >> filas;
    documento >> columnas;

    construirMatriz();

    while (documento >> tipoTerreno)
    {
        agregarElementoArray(tipoTerreno);
    }


    documento.close();
}

void mapa::construirMatriz(){

    matrizMapa = new Matriz(columnas,filas);


}

mapa::~mapa() {

    delete matrizMapa;

}
