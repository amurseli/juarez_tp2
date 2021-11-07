#include "casilleroInaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string elemento):Casillero(elemento){

}

void CasilleroInaccesible::queSoy(){

    cout << "HOLA... SOY UN LAGO" << endl;

}
void CasilleroInaccesible::devolverPosicion(){}

void CasilleroInaccesible::mostrarContenido() {
    cout << "I" ;
}

string CasilleroInaccesible::mostrarEdificio(){
    return VACIO;
}

void CasilleroInaccesible::modificarTerreno(string elemento, int opcion){}

void CasilleroInaccesible::recolectar(Materiales &materiales){}

string CasilleroInaccesible::mostrarMaterial(){
    return nullptr;
}

CasilleroInaccesible::~CasilleroInaccesible(){}