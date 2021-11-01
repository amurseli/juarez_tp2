#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz(int columnasMatriz, int filasMatriz)
{

    filas = filasMatriz;
    columnas = columnasMatriz;

    crearMemoriaPunteros();
}

void Matriz::crearMemoriaPunteros()
{
    puntero = new Casillero **[filas];

    for (int i = 0; i < filas; i++)
        puntero[i] = new Casillero *[columnas];
}

void Matriz::agregarCasillero(string elemento, int coordenadaX, int coordenadaY)
{

    Casillero *aux = new Casillero(elemento);
    puntero[coordenadaY][coordenadaX] = aux;
}

void Matriz::mostrarCoordenada(int coordenadaX, int CoordenadaY){

    puntero[coordenadaX][CoordenadaY]->queSoy();

}

void Matriz::mostrarMatriz()
{

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)

            puntero[i][j]->mostrarTipoTerreno();

        cout << " " << endl;
    }
}

Matriz::~Matriz()
{

    if (columnas > 0)
    {

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)

                delete puntero[i][j];

            delete[] puntero[i];
        }

        delete puntero;
    }
}
