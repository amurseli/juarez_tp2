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
        agregarElementoArray(nombreMaterial);
        agregarElementoArray(cantidad);

    }

    documento.close();
}

void Materiales::mostrarMateriales() {
    mostrarContenido();
}
