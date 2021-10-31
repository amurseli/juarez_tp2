#include "casillero.h"

Casillero::Casillero() {

}

Casillero::Casillero(string letraMapa) {
    tipoTerreno = letraMapa;
}

string Casillero::mostrarTipoTerreno (){
    return tipoTerreno ;
}