#ifndef YACIMIENTO_H
#define YACIMIENTO_H
#include "edificio.h"
#include "yacimiento.h"

class Yacimiento : public Edificio
{
private:

    const int CANTIDADMATERIAL = 0;
    const string MATERIAL = "no brinda";

public:

    Yacimiento(string nombre);

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    void hablarSobreMi();

    virtual ~Yacimiento();
};

#endif 