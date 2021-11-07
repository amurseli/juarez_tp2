#ifndef PIEDRA_H
#define PIEDRA_H
#include "material.h"

class Piedra : public Material
{
private:
    
    int cantidad;

public:

    Piedra(string material);

    void hablar();

    virtual ~Piedra();
    
};

#endif