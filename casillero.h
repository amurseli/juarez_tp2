#ifndef CASILLERO_H
#define CASILLERO_H
#include <iostream>
#include "edificio.h"
#include "edificios.h"
#include "materiales.h"
#include <string>

const string VACIO = "-";

using namespace std;

class Casillero
{
private:

    string tipoTerreno;

public:

    Casillero(string letraMapa);

    //PRE:
    //POST:Muestra por pantalla el tipo de terreno.
    void mostrarTipoTerreno();

    //PRE:
    //POST:Devuelve el tipo de terreno.
    string obtenerTipoTerreno();

    //PRE:
    //POST:Imprime por pantalla la posicion.
    virtual void devolverPosicion() = 0;

    //PRE:
    //POST:Imprime por pantalla la letra correpsondiente de lo que se encuentra en casillero.
    virtual void mostrarContenido() = 0;

    //PRE:
    //POST:Llama al metodo del hijo para que pueda decir que tiene.
    virtual void queSoy() = 0;

    //PRE:
    //POST:Devuelve el edificio que esta en casilla, si no un VACIO
    virtual string mostrarEdificio() = 0;

    //PRE:
    //POST:Devuelve el material que esta en casilla, si no un VACIO
    virtual string mostrarMaterial() = 0;

    //PRE:Recibe lo que va agregar
    //POST:Llama al hijo respectivo.
    virtual void modificarTerreno(string elemento, int opcion) = 0;


    //PRE:
    //POST:Suma el material al inventario de materiales (de lo que dio el edificio en casilla).
    virtual void recolectar(Materiales* &materiales) = 0;

    virtual ~Casillero() = 0;
};

#endif