#ifndef CASILLEROCTRANSITABLE_H
#define CASILLEROCTRANSITABLE_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "material.h"

using namespace std;

class CasilleroTransitable : public Casillero
{
private:
    
    Material* materialEnCasilla = NULL;

public:
    CasilleroTransitable(string elemento);
    
    void queSoy();

    //PRE:Recibe el material a agregar en el terreno
    //POST:Coloca el material.
    void agregarAlTerreno(string elemento);

    void inicializarMaterial();

    virtual ~CasilleroTransitable();
};

#endif