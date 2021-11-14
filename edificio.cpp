#include "edificio.h"


Edificio::Edificio(string tipoEdificio)
{
    nombre = tipoEdificio;
}

string Edificio::devolverNombre(){ 
    
    return (nombre);
}

Edificio::~Edificio(){}