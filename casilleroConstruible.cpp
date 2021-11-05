#include "casilleroConstruible.h"

CasilleroConstruible::CasilleroConstruible(string elemento) : Casillero(elemento){}

void CasilleroConstruible::queSoy(){

    if(punteroEdificio == NULL)
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y ESTOY VACIO :(" << endl;
    else{
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y NO ESTOY VACIO" << endl;
        punteroEdificio->hablarSobreMi();
    }

}

void CasilleroConstruible::recolectar(Materiales &materiales){

    string material;
    int cantidad;
    
    if(punteroEdificio != NULL){
        cantidad = punteroEdificio->cantidadMaterial();
        material = punteroEdificio->materialProducido();
        materiales.agregarMaterial(material,cantidad);
    }
}

string CasilleroConstruible::mostrarEdificio()
{
    string name;
    if(punteroEdificio != NULL)
    {
        name = punteroEdificio->devolverNombre();
    }
    return name;
}

void CasilleroConstruible::agregarAlTerreno(string nombreEdificio){

    if(nombreEdificio == OBELISCO){
        punteroEdificio = new Obelisco(nombreEdificio);
    }
    else if(nombreEdificio == MINA){
        punteroEdificio = new Mina(nombreEdificio);
    }
}

CasilleroConstruible::~CasilleroConstruible(){

    if (punteroEdificio != NULL)
        delete punteroEdificio;
}