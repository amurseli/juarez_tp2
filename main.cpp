#include <iostream>
#include<fstream>
#include<string>
#include"materiales.h"
#include"archivo.h"
#include"array.h"

using namespace std;

const string PATH_MATERIALES = "materiales.txt";

int main()
{
    //leer archivo materiales - nombre_edificio piedra madera metal máxima_cantidad_permitidos

    materiales materialesTxt(PATH_MATERIALES);

    materialesTxt.mostarContenido();







    return 0;
}

