#include "material.h"

Material::Material(){

    cantidadMateriales = 0;
}

void Material::agregarMaterial(string elemento){
    
    if(materialUno == VACIO){
        materialUno = elemento;
        cantidadMateriales++;
    }
    else if (materialDos == VACIO){
        materialDos = elemento;
        cantidadMateriales++;
    }

}
void Material::hablar(){

    if(!validarExistenciaDato()){
        cout << "SOY UNA " + materialUno + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
        cout << "SOY UNA " + materialDos + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
    }
    else{
        cout << "SOY UNA " + materialUno + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO"<< endl;
    }
}

bool Material::validarExistenciaDato(){

    return (cantidadMateriales == 1);
}

Material::~Material(){}

