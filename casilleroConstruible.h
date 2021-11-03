#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"

using namespace std;

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

    void agregarEdificio(string edificio, Edificio* &edificioNuevo);

    //PRE:Recibe las coordenadas
    //POST:Recolecta los materiales/2 los suma a materiales (llamando a edificio), eliminar la memoria y apunta a NULL.
    //void demoler();

    //PRE:
    //POST:Borra la direccion de memoria solicitada en ubicaciones.cpp.
    virtual ~CasilleroConstruible();
   
};

#endif