#ifndef CASILLERO_H
#define CASILLERO_H
#include <iostream>
#include "edificio.h"
#include <string>

using namespace std;

const string LAGO = "L";
const string TRANSITABLE = "T";
const string CONSTRUIBLE = "C";

class Casillero
{
private:
    string tipoTerreno;

public:

    Casillero(string letraMapa);
    void mostrarTipoTerreno();
    virtual void queSoy() = 0;
    virtual ~Casillero();
    void setEdificio(Edificio* &edificio);
};

#endif