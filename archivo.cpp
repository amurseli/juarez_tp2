#include <fstream>
#include <iostream>
#include "archivo.h"

using namespace std;

archivo::archivo(string nombreArchivo)
{
    nombre = nombreArchivo;
    contenido = new array();

    validarArchivo();

    //if (getArchivoValido())
      //  leerArchivo(nombre);
}

void archivo::validarArchivo()
{

    fstream documento(nombre, ios::in);

    existenciaArchivo = documento.is_open();

    if (!existenciaArchivo)
    {
        cout << "No se encontro un archivo con nombre \"" << nombre << endl;
    }

    documento.close();

}

bool archivo::getArchivoValido()
{

    return existenciaArchivo;
}

void archivo::agregarElementoArray(string elemento)
{
    contenido->agregarElemento(elemento);

}

archivo::~archivo()
{

    delete contenido;
}
