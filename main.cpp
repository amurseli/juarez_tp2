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
    mapa prueba(PATH_MAPA);

    return 0;
}

