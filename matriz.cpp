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
    Casillero *crearCasillero;

    if (elemento == LAGO)
    {   
        crearCasillero = new CasilleroInaccesible(elemento);
    }
    else if (elemento == CONSTRUIBLE)
    {
        crearCasillero = new CasilleroConstruible(elemento);
    }
    else if (elemento == TRANSITABLE)
    {
        crearCasillero = new CasilleroTransitable(elemento);
    }

    punteroMatriz[coordenadaY][coordenadaX] = crearCasillero;
    
}

void Matriz::mostrarCoordenada(int coordenadaX, int CoordenadaY){

    punteroMatriz[coordenadaX][CoordenadaY]->queSoy();

}

void Matriz::construirEdificio(Edificio* &nuevoEdificio, int coordX, int coordY, string nombreNuevoEdificio)
{
    punteroMatriz[coordX][coordY]->agregarEdificio(nombreNuevoEdificio,nuevoEdificio);
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

void Matriz::generarLluviaMateriales(){

    string tipoTerreno;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {

            tipoTerreno = punteroMatriz[i][j]->obtenerTipoTerreno();
            validarTipoTerreno(tipoTerreno,i,j);
        }
    }

}

void Matriz::validarTipoTerreno(string tipoTerreno, int coordenadaX, int coordenadaY){

    string materialCayendo;
    if (tipoTerreno == TRANSITABLE)
    {
        materialCayendo = "PIEDRA"; //generar random de material en otro metodo
        punteroMatriz[coordenadaX][coordenadaY]->agregarAlTerreno(materialCayendo);
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
