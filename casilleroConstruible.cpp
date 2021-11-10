#include "casilleroConstruible.h"
#include "fabrica.h"
#include "escuela.h"
#include "planta.h"
#include "aserradero.h"
#include "colors.h"

CasilleroConstruible::CasilleroConstruible(string elemento, int posx, int posy) : Casillero(elemento){
    posicionX = posx;
    posicionY = posy;
}

void CasilleroConstruible::queSoy(){

    if(punteroEdificio == nullptr)
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y ESTOY VACIO :(" << endl;
    else{
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y NO ESTOY VACIO" << endl;
        punteroEdificio->hablarSobreMi();
    }
}

void CasilleroConstruible::devolverPosicion()
{
    cout << "(" << posicionY + 1 <<", "<< posicionX + 1 <<")";
}

void CasilleroConstruible::mostrarContenido() {
    string nombreEdificio;
    if(punteroEdificio != nullptr)
    {
        punteroEdificio->imprimirLetra();
    }
    else
        cout <<BGND_LIGHT_GREEN_77<< TXT_BLACK_16<< " " <<END_COLOR;
}

void CasilleroConstruible::recolectar(Materiales* &materiales){

    string material;
    int cantidad;
    
    if(punteroEdificio != nullptr){
        cantidad = punteroEdificio->cantidadMaterial();
        material = punteroEdificio->materialProducido();
        materiales->agregarMaterial(material,cantidad);
    }
}

string CasilleroConstruible::mostrarEdificio()
{
    string nombre = VACIO;

    if(punteroEdificio != nullptr)
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
    punteroEdificio = nullptr;
}

string CasilleroConstruible::mostrarMaterial(){
    return nullptr;
}

CasilleroConstruible::~CasilleroConstruible(){
    delete punteroEdificio;
}