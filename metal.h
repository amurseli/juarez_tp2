#ifndef METAL_H
#define METAL_H
#include "material.h"

class Metal : public Material
{
private:
    
    int cantidad;

public:

    Metal(string material);

    void hablar();

    virtual ~Metal();
    
};

#endif