#include "metal.h"

Metal::Metal(string material):Material(material){
    cantidad = 1;
}
void Metal::imprimirLetra()
{
    cout << "I";
}


void Metal::hablar(){

    cout << "SOY UN METAL Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
}

Metal::~Metal(){}