#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "obelisco.h"
#include "mina.h"
#include "edificios.h"

using namespace std;

const string MINA = "mina";
const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string OBELISCO = "obelisco";
const string PLANTA_ELECTRICA = "planta electrica";  
/*const string MADERA = "madera";
const string PIEDRA = "piedra";
const string METAL = "metal";*/

class CasilleroConstruible : public Casillero //debe heredar de casillero.h
{
private:
    
    string tipoEdificio;
    Edificio* punteroEdificio = NULL;

public:
    CasilleroConstruible(string elemento);
    
    void queSoy();

    //PRE:Recibe el edificio a agregar
    //Post:Agrega el edificio a la casilla correspondiente.
    void agregarAlTerreno(string elemento);

    void agregarEdificio(string edificio);

    //PRE:Recibe las coordenadas
    //POST:Recolecta los materiales/2 los suma a materiales (llamando a edificio), eliminar la memoria y apunta a NULL.
    //void demoler();

    void crearEdificio(string nombreEdificio);

    void recolectar();

    //PRE:
    //POST:Borra la direccion de memoria solicitada en ubicaciones.cpp.
    virtual ~CasilleroConstruible();
   
};

#endif