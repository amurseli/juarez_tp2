#include "obelisco.h"    
    
Obelisco::Obelisco(string nombre) : Edificio (nombre){

    cout << "\nObelisco creado" << endl;
}

int Obelisco::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Obelisco::materialProducido(){

    return (MATERIAL);
}

void Obelisco::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Obelisco::~Obelisco(){}