#include "mina.h"

Mina::Mina(string nombre) : Edificio (nombre){

    cout << "\nMina creada" << endl;
}

int Mina::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Mina::materialProducido(){

    return (MATERIAL);
}

Mina::~Mina(){}