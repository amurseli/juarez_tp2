#ifndef CASILLEROCINACCESIBLE_H
#define CASILLEROCINACCESIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"

using namespace std;

class CasilleroInaccesible : public Casillero
{
public:
    CasilleroInaccesible(string elemento);


    //PRE:
    //POST: Dice el tipo de casillero que es por pantalla
    void queSoy();

    //PRE:
    //POST: Al ser hijo de casillero debe estar definido.
    void modificarTerreno(string elemento, int opcion);


    //PRE:
    //POST:Al ser hijo de casillero debe estar definido.
    void devolverPosicion();


    //PRE:
    //POST: Muestra el la letra que le corresponde.
    void mostrarContenido();


    //PRE:
    //POST: Al ser hijo de casillero debe estar definido.
    void recolectar(Materiales* &materiales);


    //PRE:
    //POST: Al ser hijo de casillero debe estar definido.
    string mostrarEdificio();

    //PRE:
    //POST: Al ser hijo de casillero debe estar definido.
    string mostrarMaterial();

    //PRE:
    //POST: Destruye la clase
    virtual ~CasilleroInaccesible();
};

#endif