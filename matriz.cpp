#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz(int anchoMatriz, int altoMatriz) {
    
    columnas=anchoMatriz;
    filas=altoMatriz;

    construirMatriz();


}

void Matriz::construirMatriz()
{

    punteroMatriz = new array<string>(filas,columnas);

    punteroMatriz->mostrarArrayPuntero();

}   


void Matriz::agregarElementoArrayMatriz(string elemento)
{

}

Matriz::~Matriz() {

}

