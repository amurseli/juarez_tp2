#ifndef CASILLERO_H
#define CASILLERO_H
#include <iostream>
#include "edificio.h"
#include <string>

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
    //POST:Llama al metodo del hijo para que pueda decir que tiene.
    virtual void queSoy() = 0;

    //PRE:Recibe lo que va agregar
    //POST:Llama al hijo respectivo.
    virtual void agregarAlTerreno(string elemento) = 0;

    virtual ~Casillero();

    void setEdificio(Edificio* &edificio);
};

#endif