#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <iostream>

#include <string>

using namespace std;

class Edificio
{
private:

    string nombre;

public:
    
    Edificio (string tipoEdificio);

    string devolverNombre();

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
