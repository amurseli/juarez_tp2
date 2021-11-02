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

public:
    CasilleroConstruible(string elemento);
    
    void queSoy();

    void agregarEdificio(string edificio);

    virtual ~CasilleroConstruible();
   
};

#endif