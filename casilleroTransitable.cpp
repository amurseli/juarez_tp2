#include "casilleroTransitable.h"

CasilleroTransitable::CasilleroTransitable(string elemento):Casillero(elemento){}

void CasilleroTransitable::queSoy(){

    cout << "\nHOLA SOY UN CASILLERO TRANSITABLE ";

    if (materialEnCasilla != nullptr)
    {   
        cout << "Y NO ME ENCUENTRO VACIO" << endl;
        materialEnCasilla->hablar();
    }
    else
    {   cout << "Y ME ENCUENTRO VACIO" << endl;}
}
string CasilleroTransitable::mostrarEdificio(){
    return VACIO;
}

void CasilleroTransitable::devolverPosicion()
{
   // cout << "(" << posicionX <<", "<< posicionY <<")";
}

void CasilleroTransitable::mostrarContenido() {
    cout << "T" ;
}


void CasilleroTransitable::modificarTerreno(string elemento, int opcion){

    if (materialEnCasilla == nullptr)
    {
        inicializarMaterial();
    }
  
    materialEnCasilla->agregarMaterial(elemento);
}

void CasilleroTransitable::inicializarMaterial(){
    
    materialEnCasilla = new Material();
}

void CasilleroTransitable::recolectar(Materiales &materiales){}

CasilleroTransitable::~CasilleroTransitable(){

    if (materialEnCasilla != nullptr)
    {
      delete materialEnCasilla;
    }    
}