#ifndef FABRICA_H
#define FABRICA_H
#include "edificio.h"

class Fabrica : public Edificio
{
private:

    const int CANTIDADMATERIAL = 0;
    const string MATERIAL = "no brinda";

public:

    Fabrica(string nombre);

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    void imprimirLetra();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    void hablarSobreMi();

    virtual ~Fabrica();
};

#endif 