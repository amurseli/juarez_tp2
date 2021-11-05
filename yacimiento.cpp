#include "yacimiento.h"

Yacimiento::Yacimiento(string nombre) : Edificio (nombre){

    cout << "\nPlanta creada" << endl;
}

int Yacimiento::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Yacimiento::materialProducido(){

    return (MATERIAL);
}

void Yacimiento::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Yacimiento::~Yacimiento(){}