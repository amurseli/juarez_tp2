#ifndef CASILLEROCTRANSITABLE_H
#define CASILLEROCTRANSITABLE_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "piedra.h"
#include "metal.h"
#include "madera.h"

using namespace std;

const int SIN_ACCION = 0;

class CasilleroTransitable : public Casillero
{
private:
    
    Material* materialEnCasilla = nullptr;

public:

    CasilleroTransitable(string elemento);
    
    void queSoy();

    string mostrarEdificio();

    void mostrarContenido();

    void devolverPosicion();

    //PRE:Recibe el material a agregar en el terreno
    //POST:Coloca el material.
    void modificarTerreno(string elemento, int opcion);

    void recolectar(Materiales &materiales);

    string mostrarMaterial();

    virtual ~CasilleroTransitable();
};

#endif