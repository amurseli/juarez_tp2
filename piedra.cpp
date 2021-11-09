#include "piedra.h"

Piedra::Piedra(string material):Material(material){
    cantidad = 1;
}

void Piedra::imprimirLetra()
{
    cout<< BGND_GRAY_243 <<TXT_BLACK_16<< "S" << END_COLOR;
}


void Piedra::hablar(){

    cout << "SOY UNA PIEDRA Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
}

Piedra::~Piedra(){}