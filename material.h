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
    
    Array<string>* tipoMaterial = NULL;
    int cantidadMateriales;

public:

    Material();

    Material(string elemento);

    void inicializar();

    void agregarMaterial(string elemento);

    bool validarEspacioDisponible();

    void hablar();

    bool validarExistenciaDato();

    ~Material();
    
};

#endif