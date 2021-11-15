#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <iostream>
#include "colors.h"

#include <string>

using namespace std;

class Edificio
{
private:

    string nombre;

public:
    
    //PRE:necesita el nombre del edificio
    //POST: guarda el nombre del edficio en nombre
    Edificio (string tipoEdificio);

    //PRE:
    //POST: devuelve el nombre del edifico
    string devolverNombre();

    //PRE:
    //POST:imprime la letra del tipo de casillero de forma polimorfica o lo que tiene dentro
    virtual void imprimirLetra() =0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    virtual int cantidadMaterial() = 0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    virtual string materialProducido() = 0;

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    virtual void hablarSobreMi() = 0;

    virtual ~Edificio() = 0;

};


#endif //EDIFICIO_H
