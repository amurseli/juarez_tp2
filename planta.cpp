#include "planta.h"

Planta::Planta(string nombre) : Edificio (nombre){}

void Planta::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "P" << END_COLOR;
}

int Planta::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Planta::materialProducido(){

    return (MATERIAL);
}

void Planta::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Planta::~Planta(){}