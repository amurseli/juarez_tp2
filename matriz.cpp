#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz(int columnasMatriz, int filasMatriz) {
    
    filas=filasMatriz;
    columnas=columnasMatriz;

    construirMatriz();

}

void Matriz::construirMatriz()
{

    punteroMatriz = new array<string>(columnas,filas);
    punteroMatriz->agregarCasilla();//Agrega una A
    punteroMatriz->mostrarArrayPuntero();

}   


void Matriz::agregarElementoArrayMatriz(string elemento)
{

}

Matriz::~Matriz() {

    delete punteroMatriz;

}

