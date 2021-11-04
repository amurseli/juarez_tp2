#ifndef MINA_H
#define MINA_H
#include "edificio.h"

class Mina : public Edificio
{
private:

    const int CANTIDADMATERIAL = 15;
    const string MATERIAL = "PIEDRA";

public:

    Mina(string nombre);

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    ~Mina();
};

#endif //MINA_H