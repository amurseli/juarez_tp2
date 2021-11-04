#include "materiales.h"
#include <string>
#include <iostream>

using namespace std;

Materiales::Materiales(string nombre):Archivo(nombre){

    crearContenido();
    leerArchivo(nombre);


}
void Materiales::leerArchivo(string nombre)
{

    fstream documento(nombre, ios::in);

    string nombreMaterial, cantidad;

    while (documento >> nombreMaterial)
    {
        documento >> cantidad;
        guardarDatos(nombreMaterial,cantidad);
    }
    documento.close();
}
int Materiales::devolverPiedra()
{
    return piedra;
}
int Materiales::devolverMadera()
{
    return madera;
}
int Materiales::devolverMetal()
{
    return metal;
}

void Materiales::guardarDatos(string nombreMaterial, string cantidad)
{
    if( nombreMaterial == "piedra")
    {
        piedra = atoi(cantidad.c_str());
    }
    else if (nombreMaterial == "madera")
    {
        madera =  atoi(cantidad.c_str());
    }
    else if (nombreMaterial == "metal")
    {
        metal =  atoi(cantidad.c_str());
    }
}

void Materiales::mostrarMateriales() {
    cout << "Piedra disponible: " << piedra << endl;
    cout << "Madera disponible: " << madera << endl;
    cout << "Metal disponible: " << metal << endl;
}
