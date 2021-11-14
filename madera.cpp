#include "madera.h"

Madera::Madera(string material):Material(material){
    cantidad = 1;
}
void Madera::imprimirLetra()
{
    cout<< BGND_GRAY_243 << TXT_BLACK_16 << "W" << END_COLOR;
}


void Madera::hablar(){

    cout << "SOY UNA MADERA Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
}

Madera::~Madera(){}