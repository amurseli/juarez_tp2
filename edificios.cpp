#include "edificios.h"
#include <string>
#include <iostream>

using namespace std;

void edificios::leerArchivo(string nombre)
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
