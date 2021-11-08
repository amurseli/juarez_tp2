#ifndef MATRIZ_H
#define MATRIZ_H

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

    void crearMemoriaPunteros();

    void agregarCasillero(string tipoTerreno, int coordenadaX, int coordenadaY);

    void mostrarCoordenada(int coordenadaX, int CoordenadaY);

    void recoletarMateriales(Materiales &materiales);

    void construirEdificio(int coordX, int coordY, string nombreNuevoEdificio);

    void demolerEdificio(int coordX, int coordY);

    void mostrarMatriz();

    void mostrarEdificiosConstruidos();

    void imprimirCantidades(int contMina,int contObelisco, int contAserradero, int contEscuela, int contFabrica, int contPlanta);

    int devolverMaxCol();

    int devolverMaxFil();

    //PRE:
    //POST:
    void generarLluviaMateriales();

    void agregarAcoordenada(int cantidad, string material);

    bool validarExistenciaMaterial(int coordeX,int coordeY);

    bool validarTipoConstruible(int coord1, int coord2);

    string devolverTipoTerreno(int coord1,int coord2);

    string devolverTipoEdificio(int coord1,int coord2);

    //PRE:
    //POST:
    void agregarMaterial(int cantidad, string material);

    ~Matriz();
};

#endif


