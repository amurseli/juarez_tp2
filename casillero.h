#ifndef CASILLERO_H
#define CASILLERO_H
#include <iostream>
#include <string>

using namespace std;

const string LAGO = "L";
const string TRANSITABLE = "T";
const string CONSTRUIBLE = "C";

class Casillero
{
private:
    string tipoTerreno;

    //CasilleroConstruible* punteroConstruible = NULL;

public:

    Casillero(string letraMapa);
    //void tipoCasillero();
    void mostrarTipoTerreno();
    virtual void queSoy() = 0; //este debe ser un virtual
    virtual ~Casillero();
};

#endif