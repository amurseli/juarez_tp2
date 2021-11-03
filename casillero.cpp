#include "casillero.h"


Casillero::Casillero(string letraMapa) {
    tipoTerreno = letraMapa;
}

void Casillero::mostrarTipoTerreno (){
    cout << tipoTerreno;
}

string Casillero::obtenerTipoTerreno(){

    return (tipoTerreno);
}

void Casillero::setEdificio(Edificio* &nuevoEdificio){}



Casillero::~Casillero(){

}