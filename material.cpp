#include "material.h"

Material::Material(){

    cantidadMateriales = -1;
}

void Material::inicializar(){
    tipoMaterial = new Array<string>();
}

void Material::agregarMaterial(string elemento){

    if (validarExistenciaDato())
    {
        inicializar();
    }
    
    if(validarEspacioDisponible()){
        tipoMaterial->agregarElemento(elemento);
        cantidadMateriales++;
    }
}

bool Material::validarEspacioDisponible(){

    return (cantidadMateriales<1);
}
void Material::hablar(){

    if (!validarExistenciaDato())
    {
        for (int i = 0; i < cantidadMateriales+1; i++)
        {
            cout << "SOY UNA " + tipoMaterial->devolverElemento(i) + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
        }  
    } 
}

bool Material::validarExistenciaDato(){

    return (cantidadMateriales == -1);
}

Material::~Material(){

    if (tipoMaterial != NULL)
    {
        delete tipoMaterial;
    }
}

