#include "escuela.h"

Escuela::Escuela(string nombre) : Edificio (nombre){

    cout << "\nPlanta creada" << endl;
}

int Escuela::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Escuela::materialProducido(){

    return (MATERIAL);
}

void Escuela::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Escuela::~Escuela(){}