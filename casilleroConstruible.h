#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "obelisco.h"
#include "mina.h"

using namespace std;

const string MINA = "mina";
const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string OBELISCO = "obelisco";
const string PLANTA_ELECTRICA = "planta electrica";  
const int CONSTRUIR = 1;
const int DEMOLER = 2;

class CasilleroConstruible : public Casillero //debe heredar de casillero.h
{
private:

    Edificio* punteroEdificio = nullptr;
    int posicionX,posicionY;

public:

    CasilleroConstruible(string elemento,int posicionX, int posicionY);
    
    void queSoy();

    void mostrarContenido();

    //PRE:Recibe el edificio a agregar
    //Post:Agrega el edificio a la casilla correspondiente.
    void modificarTerreno(string nombreEdificio, int opcion);

    void crearEdificio(string nombreEdificio);

    void removerEdificio();

    void devolverPosicion();

    //PRE:Recibe las coordenadas
    //POST:Recolecta los materiales/2 los suma a materiales (llamando a edificio), eliminar la memoria y apunta a NULL.
    //void demoler();

    void recolectar(Materiales &materiales);

    string mostrarMaterial();

    string mostrarEdificio();

    //PRE:
    //POST:Borra la direccion de memoria solicitada en ubicaciones.cpp.
    virtual ~CasilleroConstruible();
   
};

#endif