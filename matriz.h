#ifndef MATRIZ_H
#define MATRIZ_H

#include<string>
#include<fstream>
#include "array.h"


using namespace std;

class Matriz
{
private:
    int tamanio, columnas, filas;
    array<Casillero>* punteroMatriz;

public:

    Matriz(int ancho,int alto);

    void construirMatriz();

    void agregarElementoArrayMatriz(string elemento);

    void agregarCasillero(string tipoTerreno, int i, int j);

    void mostrarMatriz();



    ~Matriz();
};

#endif


