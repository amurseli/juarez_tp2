#include <fstream>
#include <iostream>
#include "archivo.h"

using namespace std;

Archivo::Archivo(string nombreArchivo)
{
    nombreTxt = nombreArchivo;
    validarArchivo();

}

void Archivo::validarArchivo()
{

    fstream documento(nombreTxt, ios::in);

    existenciaArchivo = documento.is_open();

    if (!existenciaArchivo)
    {
        cout << "No se encontro un Archivo con nombre \"" << nombreTxt << endl;
    }

    documento.close();

}

bool Archivo::getArchivoValido()
{

    return existenciaArchivo;
}


string Archivo::devolverNombre(){

    return nombreTxt;
}

Archivo::~Archivo(){}


