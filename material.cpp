#include "material.h"

Material::Material(string material){

    tipoMaterial = material;
}

string Material::devolverTipoMaterial(){

    return tipoMaterial;
}

Material::~Material(){}

