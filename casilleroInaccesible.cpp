#include "casilleroInaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string elemento):Casillero(elemento){}

void CasilleroInaccesible::queSoy(){

    cout << "HOLA... SOY UN LAGO" << endl;
}

void CasilleroInaccesible::mostrarContenido(){

    cout << "L" ;
}

string CasilleroInaccesible::mostrarEdificio(){return VACIO;}

void CasilleroInaccesible::recolectar(Materiales &materiales){}

string CasilleroInaccesible::mostrarMaterial(){return nullptr;}

void CasilleroInaccesible::modificarTerreno(string elemento, int opcion){}

void CasilleroInaccesible::devolverPosicion(){}

CasilleroInaccesible::~CasilleroInaccesible(){}