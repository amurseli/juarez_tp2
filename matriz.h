#ifndef MATRIZ_H
#define MATRIZ_H

#include<string>
#include<fstream>
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

    void construirMatriz();

    void agregarElementoArrayMatriz(string elemento);

    void crearMemoriaPunteros();

    void agregarCasillero(string tipoTerreno, int coordenadaX, int coordenadaY);

    void mostrarCoordenada(int coordenadaX, int CoordenadaY);

    void recoletarMateriales(Materiales &materiales);

    void construirEdificio(int coordX, int coordY, string nombreNuevoEdificio);

    void mostrarMatriz();

    void mostrarEdificiosConstruidos();

    int devolverMaxCol();

    int devolverMaxFil();

    //PRE:
    //POST:Recorre toda la matriz y agrega el material a las casillas transitables
    void generarLluviaMateriales();

    string devolverTipoTerreno(int coord1,int coord2);

    //PRE:necesita el tipo de terreno
    //POST:Valida el tipo de terreno sea un transitable y ejecuta el posible material en el random.
    void validarParaAgregar(string elemento,int coordenadaX, int coordenadaY);

    ~Matriz();
};

#endif


