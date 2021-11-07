#include "piedra.h"

Piedra::Piedra(string material):Material(material){
    cantidad = 1;
}

void Piedra::hablar(){

    cout << "SOY UNA PIEDRA Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
}

Piedra::~Piedra(){}