#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include"casillero.h"
#include"casilleroInaccesible.h"
#include "casilleroTransitable.h"
#include "casilleroConstruible.h"
#include "materiales.h"


const string LAGO = "L";
const string TRANSITABLE = "C";
const string CONSTRUIBLE = "T";


using namespace std;

class Matriz
{
private:

    int columnas, filas;
    Casillero*** punteroMatriz;

public:

    Matriz(int ancho,int alto);

    //Pre:
    //Post:Crea la memoria para generar la matriz
    void crearMemoriaPunteros();

    //Pre:
    //Post:Genera lso casilleros individuales de cada coordenada dependiendo de la info de mapa
    void agregarCasillero(string tipoTerreno, int coordenadaX, int coordenadaY);

    void mostrarCoordenada(int coordenadaX, int CoordenadaY);

    void recoletarMateriales(Materiales* &materiales);

    //Pre:
    //Post:Chequea si el terreno es construible, si lo es, crea un edificio
    void construirEdificio(int coordX, int coordY, string nombreNuevoEdificio);

    //Pre:
    //Post:Chequea si el hay un edifico, si lo hay, destruye un edificio
    void demolerEdificio(int coordX, int coordY);

    //Pre:
    //Post:Itera sobre la matriz para revisar lo que hay en cada casillero e imprimirlo
    void mostrarMatriz();

    void mostrarEdificiosConstruidos();

    int devolverCantidadEdificio(string edificio);

    void imprimirCantidades(int contMina,int contObelisco, int contAserradero, int contEscuela, int contFabrica, int contPlanta);

    //Pre:
    //Post:devuelve la cantidad de columnas
    int devolverMaxCol();

    //Pre:
    //Post:Devuelve la cantidad de filas
    int devolverMaxFil();

    //PRE:
    //POST:Utiliza el metodo srand para generar caida de elemntos aleatorios en el mapa
    void generarLluviaMateriales();

    //Pre:
    //Post:Agrega lo lloviddo a la coordenada correspondiente
    void agregarAcoordenada(int cantidad, string material);

    bool validarExistenciaMaterial(int coordeX,int coordeY);

    bool validarTipoConstruible(int coord1, int coord2);

    string devolverTipoTerreno(int coord1,int coord2);

    string devolverTipoEdificio(int coord1,int coord2);

    void agregarMaterial(int cantidad, string material);

    ~Matriz();
};

#endif


