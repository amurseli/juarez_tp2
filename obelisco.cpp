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

Obelisco::~Obelisco(){}