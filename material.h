#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "colors.h"

using namespace std;

class Material
{
private:
    
    string tipoMaterial;

public:

    Material(string material);

    virtual void imprimirLetra() =0;

    string devolverTipoMaterial();

    //Pre:
    //Post:Imprime la info corresponiente a esta clase.
    virtual void hablar() = 0;

    virtual ~Material() = 0;
    
};

#endif