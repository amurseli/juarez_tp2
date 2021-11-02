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
    punteroMatriz = new Casillero **[filas];

    for (int i = 0; i < filas; i++)
        punteroMatriz[i] = new Casillero *[columnas];
}

void Matriz::agregarCasillero(string elemento, int coordenadaX, int coordenadaY)
{
    if (elemento == "L")
    {   
        Casillero *aux = new CasilleroInaccesible(elemento);
        punteroMatriz[coordenadaY][coordenadaX] = aux;
    }
    else if (elemento == "C")
    {
        Casillero *aux = new CasilleroConstruible(elemento);
        punteroMatriz[coordenadaY][coordenadaX] = aux;
    }
    else if (elemento == "T")
    {
        Casillero *aux = new CasilleroTransitable(elemento);
        punteroMatriz[coordenadaY][coordenadaX] = aux;
    }
    
}

void Matriz::mostrarCoordenada(int coordenadaX, int CoordenadaY){

    punteroMatriz[coordenadaX][CoordenadaY]->queSoy();

}

void Matriz::mostrarMatriz()
{

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)

            punteroMatriz[i][j]->mostrarTipoTerreno();

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

                delete punteroMatriz[i][j];

            delete[] punteroMatriz[i];
        }

        delete punteroMatriz;
    }
}
