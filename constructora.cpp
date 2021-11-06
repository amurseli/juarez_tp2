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
        materiales->restarPiedra(inventarioDeEdificio->devolverPiedra());
        materiales->restarMadera(inventarioDeEdificio->devolverMadera());
        materiales->restarMetal(inventarioDeEdificio->devolverMetal());
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
    bool coordsOk = false;
    cout << "Ingrese la primer coordenada: ";
    cin >> coord1;
    cout << endl
         << "Ingrese la segunda coordenada: ";
    cin >> coord2;
    validarCoordenadas(coord1,coord2);
    matriz->construirEdificio(coord1, coord2, nombreNuevoEdificio);
}

void Constructora::validarCoordenadas(int coord1, int coord2)
{
    while(coord1 > matriz->devolverMaxFil()-1 || coord2 > matriz->devolverMaxCol()-1 || coord1 < 0 || coord2 < 0 || matriz->devolverTipoTerreno(coord1,coord2) != "T"){
        if (matriz->devolverTipoTerreno(coord1,coord2) != "T")
        {
            cout << "Ese no es un casillero construible" << endl;
        }
        cout << "Fila -> (0, " <<  matriz->devolverMaxFil() -1 <<") Columna -> (0, " << matriz->devolverMaxCol() -1 << ")" << endl;
        cout << "Ingrese fila: ";
        cin >> coord1;
        cout << endl
             << "Ingrese la columna: ";
        cin >> coord2;
    }
}

void Constructora::mostrarAviso()
{

    cout << "\n EL edificio que intenta crear no existe, para salir presione 1" << endl;
}

void Constructora::preguntarCoordenadas() {}