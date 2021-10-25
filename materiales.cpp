#include "materiales.h"
#include <string>
#include <iostream>

using namespace std;

void materiales::leerArchivo(string nombre)
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
