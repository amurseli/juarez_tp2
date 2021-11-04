#ifndef OBELISCO_H
#define OBELISCO_H
#include "edificio.h"

class Obelisco : public Edificio
{
private:

    const int CANTIDADMATERIAL = 0;
    const string MATERIAL = "NO BRINDA";

public:

    Obelisco(string nombre);

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    ~Obelisco();
};

#endif //OBELISCO_H