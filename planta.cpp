#include "planta.h"

Planta::Planta(string nombre) : Edificio (nombre){

    cout << "\nPlanta creada" << endl;
}

void Planta::imprimirLetra()
{
    cout << "P";
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