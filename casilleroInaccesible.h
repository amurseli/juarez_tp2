#ifndef CASILLEROCINACCESIBLE_H
#define CASILLEROCINACCESIBLE_H
#include <string>
#include <iostream>
#include "casillero.h"

using namespace std;

class CasilleroInaccesible : public Casillero
{
private:
    string prueba;
public:
    CasilleroInaccesible(string elemento);

    void queSoy();

    //PRE:
    //POST: Al ser hijo de casillero debe estar definido.
    void modificarTerreno(string elemento, int opcion);

    void devolverPosicion();

    void recolectar(Materiales &materiales);

    string mostrarEdificio();
    
    virtual ~CasilleroInaccesible();
};

#endif