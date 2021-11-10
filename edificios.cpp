#include "edificios.h"
#include <string>
#include <iostream>

using namespace std;

Edificios::Edificios(string nombre) : Archivo(nombre)
{

    if (getArchivoValido())
    {
        crearContenidoInventario();
        leerArchivo(nombre);
    }
}

void Edificios::leerArchivo(string nombre)
{
    fstream documento(nombre, ios::in);

    string nombreEdificio, segundoNombre, piedra, madera, metal, maximaCantidadPermitidos, construidos;

    while (documento >> nombreEdificio)
    {
        if(nombreEdificio == "planta"){
            documento >> segundoNombre;
            nombreEdificio = nombreEdificio + " " + segundoNombre;
        }

        documento >> piedra;
        documento >> madera;
        documento >> metal;
        documento >> maximaCantidadPermitidos;
        agregarEnInventario(nombreEdificio, piedra, madera, metal, maximaCantidadPermitidos);
        tamanio++;
    }

    documento.close();
}

void Edificios::crearContenidoInventario()
{

    inventarioTotal = new Inventario *[6];
}

void Edificios::agregarEnInventario(string nombreEdificio, string piedra, string madera, string metal, string maximaCantidadPermitidos)
{

    int piedraReal, maderaReal, metalReal, maximaCantidadPermitidosReal;

    piedraReal = atoi(piedra.c_str());
    maderaReal = atoi(madera.c_str());
    metalReal = atoi(metal.c_str());
    maximaCantidadPermitidosReal = atoi(maximaCantidadPermitidos.c_str());

    inventarioTotal[tamanio] = new Inventario(nombreEdificio, piedraReal, maderaReal, metalReal, maximaCantidadPermitidosReal);
}

void Edificios::listarTodosLosEdificios(){

    for (int i = 0; i < tamanio; i++)
    {
        inventarioTotal[i]->devolverEdificios();
    }
}

string Edificios::devolverNombreEdificio(int edificio)
{

    return inventarioTotal[edificio]->devolverNombre();
}

Edificios* Edificios::retornarPunteroEdificios(){

    return (this);
}

bool Edificios::validarEdificios(string edificio){
    
    int valor = buscarPosicionEnInventario(edificio);

    return ((0<=valor) && (valor<=tamanio));
}

Inventario* Edificios::devolverInventario(string edificio){

    int posicion = buscarPosicionEnInventario(edificio);

    return (inventarioTotal[posicion]->devolverMemoria());
}

int Edificios::buscarPosicionEnInventario(string edificio){

    int contador=0;
    bool found = false;

    while (!found && contador!=tamanio)
    {   

        if(edificio == devolverNombreEdificio(contador))
            found = true;
        contador++;
    
    }

    contador =contador-1;

    if(!found)
        contador = -1;

    return (contador);
}

Edificios::~Edificios()
{

    if (inventarioTotal != NULL)
    {

        for (int i = 0; i < tamanio; i++)
        {
            delete inventarioTotal[i];
        }

        delete[] inventarioTotal;
    }
}