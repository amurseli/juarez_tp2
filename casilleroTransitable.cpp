#include "casilleroTransitable.h"

CasilleroTransitable::CasilleroTransitable(string elemento):Casillero(elemento){}

void CasilleroTransitable::queSoy(){

    cout << "\nHOLA SOY UN CASILLERO TRANSITABLE ";

    if (materialEnCasilla != NULL)
    {   
        cout << "Y NO ME ENCUENTRO VACIO" << endl;
      //  materialEnCasilla->hablar();
    }
    else
    {   cout << "Y ME ENCUENTRO VACIO" << endl;}
}

void CasilleroTransitable::agregarAlTerreno(string elemento){

    if (materialEnCasilla == NULL)
    {
        inicializarMaterial();
    }
  
   // materialEnCasilla->agregarMaterial(elemento);
}

void CasilleroTransitable::inicializarMaterial(){
    
 //   materialEnCasilla = new Material();
}
void CasilleroTransitable::agregarEdificio(string edificio, Edificio* &edificioNuevo) {

}


CasilleroTransitable::~CasilleroTransitable(){

    if (materialEnCasilla != NULL)
    {
//        delete materialEnCasilla;
    }    

}