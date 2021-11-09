#include "fabrica.h"

Fabrica::Fabrica(string nombre) : Edificio (nombre){

    cout << "\nFabrica creada" << endl;
}


void Fabrica::imprimirLetra()
{
    cout << "F";
}

int Fabrica::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Fabrica::materialProducido(){

    return (MATERIAL);
}

void Fabrica::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Fabrica::~Fabrica(){}