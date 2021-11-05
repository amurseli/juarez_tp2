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

void Archivo::agregarElementoArray(string nombre)
{
    contenido->agregarElemento(nombre);
}

void Archivo::mostrarContenido(){

    contenido->mostrarArray();

}
void Archivo::mostrarContenido(int posicion){

    contenido->mostrarArray(posicion);

}

string Archivo::devolverElemento(int posicion)
{

    return contenido->devolverElemento(posicion);
}


int Archivo::devolverTamanio()
{
    return (contenido->devolverTamanio());
}

Archivo::~Archivo()
{
    if (contenido != NULL){
        delete contenido;
        contenido = NULL;
    }    
}