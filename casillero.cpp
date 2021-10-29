#include "casillero.h"

Casillero::Casillero(string letraMapa) {
    tipoTerreno = letraMapa;
}

void Casillero::mostrarTipoTerreno (){
    cout << tipoTerreno << endl;
}