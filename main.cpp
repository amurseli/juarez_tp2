#include <iostream>
#include<fstream>
#include<string>
#include"materiales.h"
#include"array.h"
#include"edificios.h"
#include"mapa.h"

using namespace std;

const string PATH_MATERIALES = "../materiales.txt";
const string PATH_EDIFICIOS = "../edificios.txt";
const string PATH_MAPA = "../mapa.txt";

int main()
{
    //leer archivo materiales - nombre_edificio piedra madera metal máxima_cantidad_permitidos

    materiales materialesTxt(PATH_MATERIALES);

    materialesTxt.mostrarContenido();

    edificios edificiosTxt(PATH_EDIFICIOS);  

    edificiosTxt.mostrarContenido();

    mapa mapaTxt(PATH_MAPA);

    mapaTxt.mostrarContenido();

    return 0;
}

