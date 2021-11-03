#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"

using namespace std;

const int MINA = 15; // brinda piedras.  
const int ASERRADERO = 25; // brinda maderas. 
const int FABRICA = 40; // brinda metales. 
const int ESCUELA = 0; // no brinda materiales.  
const int OBELISCO = 0; // no brinda materiales.  
const int PLANTAELECTRICA = 0; // no brinda materiales. 

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

    virtual ~CasilleroConstruible();
   
};

#endif