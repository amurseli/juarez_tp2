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
    cout << "(" << posicionY <<", "<< posicionX <<")";
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
    string nombre = VACIO;

    if(punteroEdificio != NULL)
        nombre = punteroEdificio->devolverNombre();

    return nombre;
}

void CasilleroConstruible::modificarTerreno(string nombreEdificio,int opcion){

    if(opcion == CONSTRUIR)
    {
        crearEdificio(nombreEdificio);
    }
    else if (opcion == DEMOLER)
    {
        removerEdificio();
    }
}

void CasilleroConstruible::crearEdificio(string nombreEdificio){

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

void CasilleroConstruible::removerEdificio(){

    delete punteroEdificio;
    punteroEdificio = NULL;
}

CasilleroConstruible::~CasilleroConstruible(){

    if (punteroEdificio != NULL)
        delete punteroEdificio;
}