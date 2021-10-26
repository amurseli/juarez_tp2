#include <iostream>
#include<fstream>
#include<string>
#include"materiales.h"
#include "array.h"
#include"edificios.h"
#include"mapa.h"
#include"matriz.h"


using namespace std;

const string PATH_MATERIALES = "../materiales.txt";
const string PATH_EDIFICIOS = "../edificios.txt";
const string PATH_MAPA = "../mapa.txt";

int main()
{
    materiales materialesTxt(PATH_MATERIALES);

    materialesTxt.mostrarContenido();

    edificios edificiosTxt(PATH_EDIFICIOS);  

    edificiosTxt.mostrarContenido();

    mapa mapaTxt(PATH_MAPA);

    archivo::array * a = new archivo::array();

    Matriz matrizOriginal(mapaTxt.devolverAncho(), mapaTxt.devolverAlto(), a);

    delete a;
    return 0;
}

