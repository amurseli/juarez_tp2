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

void Mina::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Mina::~Mina(){}