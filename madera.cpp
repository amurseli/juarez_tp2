#include "madera.h"

Madera::Madera(string material):Material(material){
    cantidad = 1;
}

void Madera::hablar(){

    cout << "SOY UNA MADERA Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
}

Madera::~Madera(){}