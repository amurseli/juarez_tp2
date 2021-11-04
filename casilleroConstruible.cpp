#include "casilleroConstruible.h"

CasilleroConstruible::CasilleroConstruible(string elemento) : Casillero(elemento) {

    tipoEdificio = "AUN NO TENGO NADA";

}

void CasilleroConstruible::queSoy(){

    cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y EL EDIFICIO QUE TENGO ES: " + tipoEdificio << endl;

}

void CasilleroConstruible::agregarEdificio(string edificio){

    tipoEdificio = edificio;
    crearEdificio(edificio);
}

void CasilleroConstruible::crearEdificio(string nombreEdificio){

    if(nombreEdificio == OBELISCO){
        punteroEdificio = new Obelisco(nombreEdificio);
    }
    else if(nombreEdificio == MINA){
        punteroEdificio = new Mina(nombreEdificio);
    }
}

void CasilleroConstruible::recolectar(){
    cout << "ENTRO" << endl;
}

void CasilleroConstruible::agregarAlTerreno(string elemento){}

CasilleroConstruible::~CasilleroConstruible(){

    if (punteroEdificio != NULL)
        delete punteroEdificio;
}