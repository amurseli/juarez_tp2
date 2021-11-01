#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <string>

using namespace std;

class Casillero
{
private:
    string tipoTerreno;

public:

    Casillero(string letraMapa);
    void mostrarTipoTerreno();
    void queSoy();
};

#endif