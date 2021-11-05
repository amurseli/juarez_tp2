#include "constructora.h"

Constructora::Constructora(Edificios *&edificioTxt, Materiales *&materialesTxt, Matriz *&matrizOriginal)
{

    edificios = edificioTxt;
    materiales = materialesTxt;
    matriz = matrizOriginal;
}

void Constructora::construirEdificio()
{

    string nombreNuevoEdificio;
    bool entradaValida = false;

    do
    {
        cout << "Ingrese el nombre del nuevo edificio: ";
        cin >> nombreNuevoEdificio;
        entradaValida = edificios->validarEdificios(nombreNuevoEdificio);

        if (!entradaValida)
            mostrarAviso();

    } while (!entradaValida && nombreNuevoEdificio != "1");

    if (entradaValida)
        validarMateriales(nombreNuevoEdificio);
}

void Constructora::validarMateriales(string nombreNuevoEdificio)
{

    bool materialesValidos = false, confirmacion = false;

    Inventario *inventarioDeEdificio = edificios->devolverInventario(nombreNuevoEdificio);

    materialesValidos = materiales->validarMateriales(inventarioDeEdificio->devolverPiedra(), inventarioDeEdificio->devolverMadera(), inventarioDeEdificio->devolverMetal());

    if(materialesValidos)
        confirmacion = confirmar(inventarioDeEdificio->devolverPiedra(), inventarioDeEdificio->devolverMadera(), inventarioDeEdificio->devolverMetal());
    else{
        cout << "\n No tienes suficientes materiales" << endl;
    }
    if (materialesValidos && confirmacion)
    {
        ingresoDeCoordenadas(nombreNuevoEdificio);
    }      
}

bool Constructora::confirmar(int piedraNecesaria, int maderaNecesaria, int metalNecesario)
{
    string confirmacion;

    cout << "\nLos materiales después de la construccion seran: " << endl;
    cout << "Piedra: " << materiales->devolverPiedra() - piedraNecesaria << endl;
    cout << "Madera: " << materiales->devolverMadera() - maderaNecesaria << endl;
    cout << "Metal: " << materiales->devolverMetal() - metalNecesario << endl;
    cout << "\n¿Desea construir? [s/n]: ";
    cin >> confirmacion;

    return (confirmacion == "s");
}

void Constructora::ingresoDeCoordenadas(string nombreNuevoEdificio)
{

    int coord1, coord2;
    bool validarCoordenadas = false;

    cout << "Ingrese la primer coordenada: ";
    cin >> coord1;
    cout << endl
         << "Ingrese la segunda coordenada: ";
    cin >> coord2;

    validarCoordenadas = true; //hacer el validador de coordenadas en matriz y que sea efectivamente construible

    if (validarCoordenadas)
        matriz->construirEdificio(coord1-1, coord2-1, nombreNuevoEdificio);
}

void Constructora::mostrarAviso()
{

    cout << "\n EL edificio que intenta crear no existe, para salir presione 1" << endl;
}

void Constructora::preguntarCoordenadas() {}