#include "casilleroConstruible.h"

CasilleroConstruible::CasilleroConstruible(string elemento) : Casillero(elemento) {

    tipoEdificio = "AUN NO TENGO NADA";

}

void CasilleroConstruible::queSoy(){

    cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y EL EDIFICIO QUE TENGO ES: " + tipoEdificio << endl;

}

void CasilleroConstruible::agregarEdificio(string edificio, Edificio* &edificioNuevo){

    tipoEdificio = edificio;
    punteroEdificio = edificioNuevo;

}


CasilleroConstruible::~CasilleroConstruible(){

}