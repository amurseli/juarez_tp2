#include "mapa.h"
#include <string>
#include <iostream>

using namespace std;

Mapa::Mapa(string nombre):Archivo(nombre){

    if(getArchivoValido())
        leerArchivo(nombre);

}

void Mapa::leerArchivo(string nombre)
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

    documento.close();
}

void Mapa::construirMatriz(){
    matrizMapa = new Matriz(columnas,filas);
}

Matriz* Mapa::retornarPunteroMatriz(){

    return matrizMapa;
}

Mapa::~Mapa() {
    if(matrizMapa != NULL)
        delete matrizMapa;
}
