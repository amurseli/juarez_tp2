#ifndef CASILLEROCTRANSITABLE_H
#define CASILLEROCTRANSITABLE_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "material.h"

using namespace std;

const int SIN_ACCION = 0;

class CasilleroTransitable : public Casillero
{
private:
    
    Material* materialEnCasilla = NULL;

public:

    CasilleroTransitable(string elemento);
    
    void queSoy();

    string mostrarEdificio();

    void devolverPosicion();

    //PRE:Recibe el material a agregar en el terreno
    //POST:Coloca el material.
    void modificarTerreno(string elemento, int opcion);

    void inicializarMaterial();

    void recolectar(Materiales &materiales);

    virtual ~CasilleroTransitable();
};

#endif