#ifndef OBELISCO_H
#define OBELISCO_H
#include "edificio.h"



const int MINA = 15; // brinda piedras.  
const int ASERRADERO = 25; // brinda maderas. 
const int FABRICA = 40; // brinda metales. 
const int ESCUELA = 0; // no brinda materiales.  
const int ; // no brinda materiales.  
const int PLANTAELECTRICA = 0; // no brinda materiales. 

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

#endif OBELISCO_H