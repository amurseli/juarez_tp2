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

    //PRE:
    //POST: Muestra por pantalla el tipo de casillero que es
    void queSoy();

    //PRE:
    //POST: Devuelve el edificio que contiene
    string mostrarEdificio();

    //PRE:
    //POST: Muestra por pantalla la letra del tipo de terreno o del material que contiene
    void mostrarContenido();

    //PRE:
    //POST: Muestra por pantalla la posicion del casillero
    void devolverPosicion();

    //PRE:Recibe el material a agregar en el terreno
    //POST:Coloca el material.
    void modificarTerreno(string elemento, int opcion);

    //PRE:
    //POST:Por estar en el padre debe estar definida aca
    void recolectar(Materiales* &materiales);

    //PRE:
    //POST: Devuelve el material que hay en casilla
    string mostrarMaterial();

    //PRE:
    //POST: Destructor correpsondiente
    virtual ~CasilleroTransitable();
};

#endif