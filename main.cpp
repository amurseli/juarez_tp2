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
    Matriz* punteroOriginal; // Para trabajar con la matriz desde el main

    Mapa prueba(PATH_MAPA);

    punteroOriginal = prueba.retornarPunteroMatriz();

    punteroOriginal->mostrarCoordenada(0,0);
    punteroOriginal->mostrarCoordenada(1,5);

    



    return 0;
}

