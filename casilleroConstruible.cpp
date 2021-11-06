#include "casilleroConstruible.h"
#include "fabrica.h"
#include "escuela.h"
#include "planta.h"
#include "aserradero.h"

CasilleroConstruible::CasilleroConstruible(string elemento, int posx, int posy) : Casillero(elemento){
    posicionX = posx;
    posicionY = posy;
}

void CasilleroConstruible::queSoy(){

    if(punteroEdificio == NULL)
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y ESTOY VACIO :(" << endl;
    else{
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y NO ESTOY VACIO" << endl;
        punteroEdificio->hablarSobreMi();
    }
}

void CasilleroConstruible::devolverPosicion()
{
    cout << "(" << posicionX <<", "<< posicionY <<")";
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
    else if(nombreEdificio == PLANTA_ELECTRICA){
        punteroEdificio = new Planta(nombreEdificio);
    }
    else if(nombreEdificio == ESCUELA){
        punteroEdificio = new Escuela(nombreEdificio);
    }
    else if(nombreEdificio == FABRICA){
        punteroEdificio = new Fabrica(nombreEdificio);
    }
    else if(nombreEdificio == ASERRADERO){
        punteroEdificio = new Aserradero(nombreEdificio);
    }

}

CasilleroConstruible::~CasilleroConstruible(){

    if (punteroEdificio != NULL)
        delete punteroEdificio;
}