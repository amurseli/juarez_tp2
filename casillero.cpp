#include "casillero.h"


Casillero::Casillero(string letraMapa) {
    tipoTerreno = letraMapa;
}

void Casillero::mostrarTipoTerreno (){
    cout << tipoTerreno;
}

void Casillero::queSoy(){

    if(tipoTerreno == "T"){
        cout << "HOLA... SOY UN CASILLERO TRANSITABLE" << endl;
    }
    else if (tipoTerreno == "L")
    {
        cout << "HOLA... SOY UN LAGO" << endl;
    }
    else{
        cout << "HOLA... SOY UN CASILLERO CONSTRUIBLE" << endl;
    }
    
}