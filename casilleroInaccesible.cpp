#include "casilleroInaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string elemento):Casillero(elemento){

}

void CasilleroInaccesible::queSoy(){

    cout << "HOLA... SOY UN LAGO" << endl;

}

void CasilleroInaccesible::agregarAlTerreno(string elemento){}

void CasilleroInaccesible::recolectar(Materiales &materiales){}

CasilleroInaccesible::~CasilleroInaccesible(){}