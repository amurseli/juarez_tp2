#include "aserradero.h"

Aserradero::Aserradero(string nombre) : Edificio (nombre){

    cout << "\nAserradero creado" << endl;
}

void Aserradero::imprimirLetra()
{
    cout << "A";
}

int Aserradero::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Aserradero::materialProducido(){

    return (MATERIAL);
}

void Aserradero::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Aserradero::~Aserradero(){}