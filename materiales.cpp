#include "materiales.h"
#include <string>
#include <iostream>

using namespace std;

materiales::materiales(string nombre):archivo(nombre){

    leerArchivo(nombre);

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

void leerArchivo(string nombre)
{

    fstream documento(nombre, ios::in);

    string nombreMaterial, cantidad;

    while (documento >> nombreMaterial)
    {
        documento >> cantidad;
        agregarElementoArray(cantidad);
        
    }

    documento.close();
}
