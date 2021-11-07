#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include <iostream>
#include "casillero.h"
#include "array.h"

using namespace std;

class Material
{
private:
    
    int cantidadMateriales;
    string materialUno = VACIO, materialDos = VACIO;

public:

    Material();

    void agregarMaterial(string elemento);

    void hablar();

    bool validarExistenciaDato();

    ~Material();
    
};

#endif