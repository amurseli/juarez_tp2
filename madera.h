#ifndef MADERA_H
#define MADERA_H
#include "material.h"

class Madera : public Material
{
private:
    
    int cantidad;

public:

    Madera(string material);

    void imprimirLetra();

    void hablar();

    virtual ~Madera();
    
};

#endif