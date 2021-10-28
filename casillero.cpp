#include "casillero.h"

casillero::casillero(string letraMapa) {
    tipoTerreno = letraMapa;
}

void casillero::mostrarTipoTerreno (){
    cout << tipoTerreno << endl;
}