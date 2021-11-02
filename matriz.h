#ifndef MATRIZ_H
#define MATRIZ_H

#include<string>
#include<fstream>
#include"casillero.h"
#include"casilleroInaccesible.h"
#include "casilleroTransitable.h"
#include "casilleroConstruible.h"


using namespace std;

class Matriz
{
private:
    int columnas, filas;
    Casillero*** punteroMatriz;

public:

    Matriz(int ancho,int alto);

    void construirMatriz();

    void agregarElementoArrayMatriz(string elemento);

    void crearMemoriaPunteros();

    void agregarCasillero(string tipoTerreno, int coordenadaX, int coordenadaY);

    void mostrarCoordenada(int coordenadaX, int CoordenadaY);

    void mostrarMatriz();

    ~Matriz();
};

#endif


