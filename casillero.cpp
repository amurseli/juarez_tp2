#include "casillero.h"


Casillero::Casillero(string letraMapa) {
    tipoTerreno = letraMapa;
    //tipoCasillero();
}

void Casillero::mostrarTipoTerreno (){
    cout << tipoTerreno;
}

/*void Casillero::queSoy(){

    if(tipoTerreno == TRANSITABLE){
        cout << "HOLA... SOY UN CASILLERO TRANSITABLE" << endl;
    }
    else if (tipoTerreno == LAGO)
    {
        cout << "HOLA... SOY UN LAGO" << endl;
    }
    else if(tipoTerreno == CONSTRUIBLE){
        cout << "\nHOLA... SOY UN CASILLERO CONSTRUIBLE Y EL EDIFICIO QUE TENGO ES: ";
        punteroConstruible->mostrarEdificio();
        
    }
    
}*/

/*void Casllero::tipoCasillero(){

    if (tipoTerreno == CONSTRUIBLE)
    {
        punteroConstruible = new CasilleroConstruible();
    }
    
}*/


Casillero::~Casillero(){

    delete this;
    
}