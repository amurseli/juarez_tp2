#include "mina.h"

Mina::Mina(string nombre) : Edificio (nombre){}


void Mina::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "M" << END_COLOR;
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