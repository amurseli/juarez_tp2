#include <fstream>
#include <iostream>
#include "archivo.h"

using namespace std;

Archivo::Archivo(string nombreArchivo)
{
    nombre = nombreArchivo;
    validarArchivo();

}

void Archivo::crearContenido(){

    contenido = new Array<string>();
}

void Archivo::validarArchivo()
{

    fstream documento(nombre, ios::in);

    existenciaArchivo = documento.is_open();

    if (!existenciaArchivo)
    {
        cout << "No se encontro un Archivo con nombre \"" << nombre << endl;
    }

    documento.close();

}

bool Archivo::getArchivoValido()
{

    return existenciaArchivo;
}

void Archivo::agregarElementoArray(string elemento)
{
    contenido->agregarElemento(elemento);
}

void Archivo::mostrarContenido(){

    contenido->mostrarArray();

}

Archivo::~Archivo()
{
    if (!NULL)
        delete contenido;    
}