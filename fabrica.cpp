#include "fabrica.h"

Fabrica::Fabrica(string nombre) : Edificio (nombre){}


void Fabrica::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "F" << END_COLOR;
}

int Fabrica::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Fabrica::materialProducido(){

    return (MATERIAL);
}

void Fabrica::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Fabrica::~Fabrica(){}