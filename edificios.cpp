#include "edificios.h"
#include <string>
#include <iostream>

using namespace std;

Edificios::Edificios(string nombre):Archivo(nombre){

    crearContenido();
    leerArchivo(nombre);


}

void Edificios::leerArchivo(string nombre)
{

   fstream documento(nombre, ios::in);

    string nombreEdificio, piedra, madera, metal, maximaCantidadPermitidos;

    while (documento >> nombreEdificio)
    {
        documento >> piedra;
        documento >> madera;
        documento >> metal;
        documento >> maximaCantidadPermitidos;
        agregarElementoArray(nombreEdificio);
        agregarElementoArray(piedra);
        agregarElementoArray(madera);
        agregarElementoArray(metal);
        agregarElementoArray(maximaCantidadPermitidos);

    }

    documento.close();
}
