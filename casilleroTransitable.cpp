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
    cout << "C" ;
}


void CasilleroTransitable::modificarTerreno(string elemento, int opcion){

    if(elemento == PIEDRA)
    {
        materialEnCasilla = new Piedra(elemento);
    }
    else if(elemento == MADERA){
        materialEnCasilla = new Madera(elemento);
    }
    else if(elemento == METAL){
        materialEnCasilla = new Metal(elemento);
    }
}


string CasilleroTransitable::mostrarMaterial(){

    string tipoMaterial;

    if(materialEnCasilla != nullptr)
        tipoMaterial = materialEnCasilla->devolverTipoMaterial();
    else{
        tipoMaterial = VACIO;
    }

    return tipoMaterial;
}

void CasilleroTransitable::recolectar(Materiales &materiales){}

CasilleroTransitable::~CasilleroTransitable(){

    if (materialEnCasilla != nullptr)
    {
      delete materialEnCasilla;
    }    
}